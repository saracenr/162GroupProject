#include "World.hpp"
//#include "Ant.hpp"
//#include "Doodlebug.hpp"
//#include "constants.hpp"
#include <iostream>

World::World(int nr, int nc, int na, int nd)
{
	nRow=nr;
	nCol=nc;
	numAnts=na;
	numDoodles=nd;

	//initialize all out of bounds
	for (int i = 0; i < 4; i++) {
		adjacents.push_back(OUTOFBOUNDS);
	}

	critterSim = new Critter**[nRow];
	for (int i=0; i<nRow; i++)
	{	
		critterSim[i] = new Critter*[nCol];
		for (int j=0; j<nCol; j++)
		{
			critterSim[i][j] = nullptr;
		}
	}


	int randRow, randCol;
	for (int i=0; i<numAnts; i++)
	{
		randRow=(rand()%nRow);
		randCol=(rand()%nCol);

		// generate new random rows until you randomly find a nullptr
		while (critterSim[randRow][randCol]!=nullptr)
		{
			randRow=(rand()%nRow);
			randCol=(rand()%nCol);
		}

		critterSim[randRow][randCol]=new Ant(randRow, randCol);
	}


	for (int i=0; i<numDoodles; i++)
	{
		randRow=(rand()%nRow);
		randCol=(rand()%nCol);

		// generate new random rows until you randomly find a nullptr
		while (critterSim[randRow][randCol]!=nullptr)
		{
			randRow=(rand()%nRow);
			randCol=(rand()%nCol);
		}

		critterSim[randRow][randCol]=new Doodlebug(randRow, randCol);
	}

} 

World::~World()
{
	for (int i=0; i<nRow; i++)
	{
		for (int j=0; j<nCol; j++)
		{
			if (critterSim[i][j]!=nullptr)
			{
				delete critterSim[i][j];
			}
		}
	}

	for (int i=0; i<nRow; i++)
	{
		delete [] critterSim[i];
	}
	delete [] critterSim;

}


// Function to print board with lines around the outside of it to show limits
void World::printGrid(){

	numDoodles = 0;
	numAnts = 0;

	// print row of dashes before world rows
	for (int i=0; i<=(nCol+1); i++)
	{
		std::cout<<"-";
	}
	std::cout<<std::endl;

	// print each row bounded by '|'
	for (int i=0; i<nRow; i++)
	{	
		std::cout<<"|";
		for (int j=0; j<nCol; j++)
		{
			if (critterSim[i][j]==nullptr)
			{
				std::cout<<EMPTY_CHAR;
			}
			else if (critterSim[i][j]!=nullptr && 
				(critterSim[i][j])->getCritterType()==ANT)
			{
				std::cout<<ANT_CHAR;
				numAnts++;
			}
			else if (critterSim[i][j]!=nullptr && 
				(critterSim[i][j])->getCritterType()==DOODLEBUG)
			{
				std::cout<<DOODLE_CHAR;
				numDoodles++;
			}
		}
		std::cout<<"|"<<std::endl;
	}

	// print row of dashes after world rows
	for (int i=0; i<=(nCol+1); i++)
	{
		std::cout<<"-";
	}
	std::cout<<std::endl;
	std::cout << "Doodlebugs: " << numDoodles << "   " << "Ants: " << numAnts << std::endl;

	return;

}

void World::resetCritters()
{
	for (int i=0; i<nRow; i++)
	{
		for (int j=0; j<nCol; j++)
		{
			if (critterSim[i][j]!=nullptr)
			{
				(*critterSim[i][j]).resetMoved();
			}
		}
	}

	return;
}

/*********************************************************************
Calls each critter's breed function to get direction of breed. Sets
new critter type in appropriate adjacent cell.
*********************************************************************/
void World::breedCritters(critterType c)  
{
	direction breedDir = NONE;
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			//Filter for Doodlebugs
			if (c == DOODLEBUG) {
				if (critterSim[i][j] != nullptr) {
					if (critterSim[i][j]->getCritterType() == DOODLEBUG) { //team Arrow!! ;)
						setAdjacent(i, j);
						breedDir = critterSim[i][j]->breed(adjacents); //RJ  will pick up here later
						//place new doodle according to returned breed direction
						if (breedDir == UP) {
							critterSim[i - 1][j] = new Doodlebug(i - 1, j);
						}
						if (breedDir == RIGHT) {
							critterSim[i][j + 1] = new Doodlebug(i, j + 1);
						}
						if (breedDir == DOWN) {
							critterSim[i + 1][j] = new Doodlebug(i + 1, j);
						}
						if (breedDir == LEFT) {
							critterSim[i][j - 1] = new Doodlebug(i, j - 1);
						}
					}
				}
			}
			//Filter for Ants
			if (c == ANT) {
				if (critterSim[i][j] != nullptr) {
					if (critterSim[i][j]->getCritterType() == ANT) {
						setAdjacent(i, j);
						breedDir = critterSim[i][j]->breed(adjacents);
						//Place new Ants according to returned breed direction
						if (breedDir == UP) {
							critterSim[i - 1][j] = new Ant(i - 1, j);
						}
						if (breedDir == RIGHT) {
							critterSim[i][j + 1] = new Ant(i, j + 1);
						}
						if (breedDir == DOWN) {
							critterSim[i + 1][j] = new  Ant(i + 1, j);
						}
						if (breedDir == LEFT) {
							critterSim[i][j - 1] = new Ant(i, j - 1);
						}
					}
				}
			}
		}
	}
}

void World::runIter(){
	resetCritters();
	moveCritters(DOODLEBUG);
	breedCritters(DOODLEBUG);
	starveCritters();
	moveCritters(ANT);
	breedCritters(ANT);
	printGrid(); // print after every step

}

void World::moveCritters(critterType c){
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nCol; j++){
			if(critterSim[i][j] != nullptr){
				if(critterSim[i][j]->getCritterType() == c && critterSim[i][j]->getMoved() == false){
					// make spacetypes for possible moves
					spaceType up = OUTOFBOUNDS, down = OUTOFBOUNDS, right = OUTOFBOUNDS, left = OUTOFBOUNDS;

					// set up
					if(inBounds(i - 1, j) == false){
						up = OUTOFBOUNDS;
					}
					else if(critterSim[i - 1][j] == nullptr && inBounds(i - 1, j) == true){
						up = EMPTY;
					}
					else if(critterSim[i - 1][j]->getCritterType() == DOODLEBUG && inBounds(i - 1, j) == true){
						up = DOODLEBUG_SPACE;
					}
					else if(critterSim[i - 1][j]->getCritterType() == ANT && inBounds(i - 1, j) == true){
						up = ANT_SPACE;
					}

					// set down
					if(inBounds(i + 1, j) == false){
						down = OUTOFBOUNDS;
					}
					else if(critterSim[i + 1][j] == nullptr && inBounds(i + 1, j) == true){
						down = EMPTY;
					}
					else if(critterSim[i + 1][j]->getCritterType() == DOODLEBUG && inBounds(i + 1, j) == true){
						down = DOODLEBUG_SPACE;
					}
					else if(critterSim[i + 1][j]->getCritterType() == ANT && inBounds(i + 1, j) == true){
						down = ANT_SPACE;
					}

					// set right
					if(inBounds(i, j + 1) == false){
						right = OUTOFBOUNDS;
					}
					else if(critterSim[i][j + 1] == nullptr && inBounds(i, j + 1) == true){
						right = EMPTY;
					}
					else if(critterSim[i][j + 1]->getCritterType() == DOODLEBUG && inBounds(i, j + 1) == true){
						right = DOODLEBUG_SPACE;
					}
					else if(critterSim[i][j + 1]->getCritterType() == ANT && inBounds(i, j + 1) == true){
						right = ANT_SPACE;
					}

					// set left
					if(inBounds(i, j - 1) == false){
						left = OUTOFBOUNDS;
					}
					else if(critterSim[i][j - 1] == nullptr && inBounds(i, j - 1) == true){
						left = EMPTY;
					}
					else if(critterSim[i][j - 1]->getCritterType() == DOODLEBUG && inBounds(i, j - 1) == true){
						left = DOODLEBUG_SPACE;
					}
					else if(critterSim[i][j - 1]->getCritterType() == ANT && inBounds(i, j - 1) == true){
						left = ANT_SPACE;
					}

					// check if doodle eats ant, and move spaces
					if(critterSim[i][j]->move(up, right, down, left) == true && inBounds(critterSim[i][j]->getX(), critterSim[i][j]->getY()) == true){
						if(critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()] != nullptr){
							if(critterSim[i][j]->getCritterType() == DOODLEBUG && critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()]->getCritterType() == ANT){
								delete critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()];
								critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()] = nullptr;
							}
						}
						critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()] = critterSim[i][j];
						critterSim[i][j] = nullptr;
					}
				}
			}
		}
	}
}

void World::starveCritters(){
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nCol; j++){
			if(critterSim[i][j] != nullptr && critterSim[i][j]->starve() == true){
				delete critterSim[i][j];
				critterSim[i][j] = nullptr;
			}
		}
	}
}

void World::runSim(int nSteps){
	for(int i = 0; i < nSteps; i++){
		runIter();
	}
}

bool World::inBounds(int row, int col){
	if(row >= 0 && row < nRow && col >= 0 && col < nCol){
		return true;
	}
	else{
		return false;
	}
}

/******************************************************************
Checks adjacent spaces and fills vector with status of each space.
Bounds checking function.
*******************************************************************/
void World::setAdjacent(int rowIn, int colIn)
{
	critterType type;
	//fill adjacent vector with status of adjacent spaces
	//above
	if (rowIn - 1 < 0) {
		adjacents[0] = OUTOFBOUNDS;
	}
	else if (critterSim[rowIn - 1][colIn] == nullptr) {
		adjacents[0] = EMPTY;
	}
	else if (critterSim[rowIn - 1][colIn] != nullptr) {
		type = critterSim[rowIn - 1][colIn]->getCritterType();
		if (type == ANT) {
			adjacents[0] = ANT_SPACE;
		}
		else if (type == DOODLEBUG) {
			adjacents[0] = DOODLEBUG_SPACE;
		}
	}
	//right
	if (colIn + 1 > nCol - 1) {
		adjacents[1] = OUTOFBOUNDS;
	}
	else if (critterSim[rowIn][colIn + 1] == nullptr) {
		adjacents[1] = EMPTY;
	}
	else if (critterSim[rowIn][colIn + 1] != nullptr) {
		type = critterSim[rowIn][colIn + 1]->getCritterType();
		if (type == ANT) {
			adjacents[1] = ANT_SPACE;
		}
		else if (type == DOODLEBUG) {
			adjacents[1] = DOODLEBUG_SPACE;
		}
	}
	//below
	if (rowIn + 1 > nRow - 1) {
		adjacents[2] = OUTOFBOUNDS;
	}
	else if (critterSim[rowIn + 1][colIn] == nullptr) {
		adjacents[2] = EMPTY;
	}
	else if (critterSim[rowIn + 1][colIn] != nullptr) {
		type = critterSim[rowIn + 1][colIn]->getCritterType();
		if (type == ANT) {
			adjacents[2] = ANT_SPACE;
		}
		else if (type == DOODLEBUG) {
			adjacents[2] = DOODLEBUG_SPACE;
		}
	}
	//left
	if (colIn - 1 < 0) {
		adjacents[3] = OUTOFBOUNDS;
	}
	else if (critterSim[rowIn][colIn - 1] == nullptr) {
		adjacents[3] = EMPTY;
	}
	else if (critterSim[rowIn][colIn - 1]->getCritterType() == ANT) {
		adjacents[3] = ANT_SPACE;
	}
	else if (critterSim[rowIn][colIn - 1]->getCritterType() == DOODLEBUG) {
		adjacents[3] = DOODLEBUG_SPACE;
	}
}


