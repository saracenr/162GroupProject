#include "World.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "constants.hpp"
#include <iostream>

World::World(int nr, int nc, int na, int nd)
{
	nRow=nr;
	nCol=nc;
	numAnts=na;
	numDoodles=nd;

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
void World::printGrid()
{
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
			}
			else if (critterSim[i][j]!=nullptr && 
				(critterSim[i][j])->getCritterType()==DOODLEBUG)
			{
				std::cout<<DOODLE_CHAR;
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

void World::runIter(){
	resetCritters();
	moveCritters(DOODLEBUG);
	breedCritters(DOODLEBUG);
	starveCritters();
	moveCritters(ANT);
	breedCritters(ANT);

} //WIP

void World::moveCritters(critterType c){
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nCol; j++){
			// make sure critterType matches
			if(critterSim[i][j]->getCritterType() == c){
				// make spaces to give status of possible moves
				spaceType up, down, right, left;

				// check spaces to set up
				if(critterSim[i - 1][j] == NULL && inBounds(i - 1, j) == true){
					up = EMPTY;
				}
				else if(inBounds(i - 1, j) == false){
					up = OUTOFBOUNDS;
				}
				else if(critterSim[i - 1][j]->getCritterType() == DOODLEBUG){
					up = DOODLEBUG_SPACE;
				}
				else if(critterSim[i - 1][j]->getCritterType() == ANT){
					up = ANT_SPACE;
				}
				// check spaces to set down
				if(critterSim[i + 1][j] == NULL && inBounds(i + 1, j) == true){
					down = EMPTY;
				}
				else if(inBounds(i + 1, j) == false){
					down = OUTOFBOUNDS;
				}
				else if(critterSim[i + 1][j]->getCritterType() == DOODLEBUG){
					down = DOODLEBUG_SPACE;
				}
				else if(critterSim[i + 1][j]->getCritterType() == ANT){
					down = ANT_SPACE;
				}
				// check spaces to set right
				if(critterSim[i][j + 1] == NULL && inBounds(i, j + 1) == true){
					right = EMPTY;
				}
				else if(inBounds(i, j + 1) == false){
				 	right = OUTOFBOUNDS;
				}
				else if(critterSim[i][j + 1]->getCritterType() == DOODLEBUG){
					right = DOODLEBUG_SPACE;
				}
				else if(critterSim[i][j + 1]->getCritterType() == ANT){
					right = ANT_SPACE;
				}
				// check spaces to set left
				if(critterSim[i][j - 1] == NULL && inBounds(i, j - 1) == true){
					left = EMPTY;
				}
				else if(inBounds(i, j - 1) == false){
					left = OUTOFBOUNDS;
				}
				else if(critterSim[i][j - 1]->getCritterType() == DOODLEBUG){
					left = DOODLEBUG_SPACE;
				}
				else if(critterSim[i][j - 1]->getCritterType() == ANT){
					left = ANT_SPACE;
				}

				// input spaces into function to get bool, and move critter on board if true
				if(critterSim[i][j]->move(up, right, down, left) == true){
					// delete ant if eat
					if(critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()]->getCritterType() == ANT){
						delete critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()];
						critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()] = NULL;
					}
					// move critter
					critterSim[critterSim[i][j]->getX()][critterSim[i][j]->getY()] = critterSim[i][j];
					critterSim[i][j] = NULL;
				}
			}
		}
	}
} //WIP

void World::breedCritters(critterType c){} //WIP

void World::starveCritters(){
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nCol; j++){
			if(critterSim[i][j]->getCritterType() == DOODLEBUG && critterSim[i][j]->starve() == true){
				delete critterSim[i][j];
				critterSim[i][j] = NULL;
			}
		}
	}
} //WIP

void World::runSim(int nSteps){
	for(int i = 0; i < nSteps; i++){
		runIter();
	}
} //WIP

bool World::inBounds(int row, int col){
	if(row >= 0 && row < nRow && col >= 0 && col < nCol){
		return true;
	}
	else{
		return false;
	}
}


