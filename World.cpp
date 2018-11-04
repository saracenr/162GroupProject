/*****************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 11/4/2018
 * Class: World
 *
 * Arguments: Constructor takes (int numRow, numCol, numAnts, numDoodles)
 *
 * Description: This class represents the world for the predator/prey
 * simulation. It contains a constructor and destructor, which appropriately 
 * handle the allocation and deallocation of the Critter*** pointer which is 
 * the basis of the simulation. It also contains functions which move or breed
 * all critters of a certain type, reset all the critters, print the board, 
 * and fill adjacent squares. 
 *****************************************************************************/


#include "World.hpp"
#include <iostream>


/*****************************************************************
World constructor. Takes number of rows/columns, and critters, and
dynamically allocates a triple pointer (2d array of Critter*). Sets
all pointers in array to nullptr, except randomly chosen ones which
are set to appropriate critters. 
*****************************************************************/
World::World(int nr, int nc, int na, int nd)
{
	nRow=nr;
	nCol=nc;
	numAnts=na;
	numDoodles=nd;

	//initialize all out of bounds vector elements
	for (int i = 0; i < 4; i++) {
		adjacents.push_back(OUTOFBOUNDS);
	}

	// initialize empty Critter*** with nullptrs
	critterSim = new Critter**[nRow];
	for (int i=0; i<nRow; i++)
	{	
		critterSim[i] = new Critter*[nCol];
		for (int j=0; j<nCol; j++)
		{
			critterSim[i][j] = nullptr;
		}
	}

	// randomly place ants
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

	// randomly place doodlebugs
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

/*****************************************************************
World destructor. Deletes each element, rows and finally the entire 
Critter*** object, to prevent memory leaks.
*****************************************************************/
World::~World()
{
	// for every element of critterSim, deallocate dynamically allocated
	// critters if they're not nullptrs
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

	// deallocate array
	for (int i=0; i<nRow; i++)
	{
		delete [] critterSim[i];
	}
	delete [] critterSim;

}


/*****************************************************************
Function to printGrid(), with lines around the outside to represent
boundaries. Prints characters depending on critter type, and counts 
number of critters of each type in the process. 
*****************************************************************/
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
	std::cout << "Doodlebugs: " << numDoodles << "   " 
				<< "Ants: " << numAnts << std::endl;

	return;

}

/*********************************************************************
Resets all non-nullptr critters in the Critter*** array before moves are made
*********************************************************************/
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
					if (critterSim[i][j]->getCritterType() == DOODLEBUG) { 
						setAdjacent(i, j);
						breedDir = critterSim[i][j]->breed(adjacents); 
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

/*********************************************************************
Calls other functions in sequence to run a single iteration of predator/prey
simulation. 
*********************************************************************/
void World::runIter(){
	resetCritters();
	moveCritters(DOODLEBUG);
	breedCritters(DOODLEBUG);
	starveCritters();
	moveCritters(ANT);
	breedCritters(ANT);
	printGrid(); // print after every step
}

/*********************************************************************
Moves all critters, and deletes/moves pointers as necessary following moves
*********************************************************************/
void World::moveCritters(critterType c){
	for (int i = 0; i < nRow; i++){
		for (int j = 0; j < nCol; j++){
			// check that critter is allocated, is correct type, hasn't moved
			if(critterSim[i][j] != nullptr && 
			critterSim[i][j]->getCritterType() == c 
			&& critterSim[i][j]->getMoved() == false){
				setAdjacent(i, j);

				// check if a move was made, and whether the critter in bounds
				if(critterSim[i][j]->move(adjacents) && 
				inBounds(critterSim[i][j]->getX(), critterSim[i][j]->getY())){
					// if the critter is a doodlebug, and it moves to ANT
					if(critterSim[critterSim[i][j]->getX()]
						[critterSim[i][j]->getY()] != nullptr 
					&& critterSim[i][j]->getCritterType() == DOODLEBUG 
					&& critterSim[critterSim[i][j]->getX()]
						[critterSim[i][j]->getY()]->getCritterType() == ANT){

						// "kill" the Ant, set to nullptr
						delete critterSim[critterSim[i][j]->getX()]
								[critterSim[i][j]->getY()];
						critterSim[critterSim[i][j]->getX()]
								[critterSim[i][j]->getY()] = nullptr;

					}
					// move critter if it has moved
					critterSim[critterSim[i][j]->getX()]
							[critterSim[i][j]->getY()] = critterSim[i][j];
					critterSim[i][j] = nullptr;
				}
			}
		}
	}
}

/*********************************************************************
Runs through entire array and starves all critters as appropriate
*********************************************************************/
void World::starveCritters(){
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nCol; j++){
			if(critterSim[i][j] != nullptr && critterSim[i][j]->starve()){
				delete critterSim[i][j];
				critterSim[i][j] = nullptr;
			}
		}
	}
}

/*********************************************************************
Runs entire simulation, with number of steps provided by user. Prints 
step numbers as it goes.
*********************************************************************/
void World::runSim(int nSteps){
	printGrid();
	for(int i = 0; i < nSteps; i++){
		std::cout<<"\n--------------------------------------\n";
		std::cout << "Step: " << i+1 << std::endl;
		runIter();
	}
}

/*********************************************************************
Checks whether a space is in bounds.
*********************************************************************/
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
	// check space above
	if (rowIn - 1 < 0) { // if out of bounds, set out of bounds
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
	// check space to the right
	if (colIn + 1 > nCol - 1) { // if out of bounds, set out of bounds
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
	//check space below
	if (rowIn + 1 > nRow - 1) {  // if out of bounds, set out of bounds
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
	//check space to the left
	if (colIn - 1 < 0) {  // if out of bounds, set out of bounds
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


