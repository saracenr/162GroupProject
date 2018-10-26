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
	breedDir = NONE;

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
				(*critterSim[i][j]).getCritterType()==critterType::ANT)
			{
				std::cout<<ANT_CHAR;
			}
			else if (critterSim[i][j]!=nullptr && 
				(*critterSim[i][j]).getCritterType()==critterType::DOODLEBUG)
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

void World::runIter(){} //WIP
void World::moveCritters(critterType c){} //WIP
/*********************************************************************
Calls each critter's breed function to get direction of breed. Sets
new critter type in appropriate adjacent cell.
*********************************************************************/
void World::breedCritters(critterType c)  //WIP, incomplete
{
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			if (critterSim[i][j] != nullptr) {
				setAdjacent(i, j);
				breedDir = critterSim[i][j]->breed(adjacents); //RJ  will pick up here later
			}
		}
	}
} 
void World::starveCritters(){} //WIP
void World::runSim(int nSteps){} //WIP

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
	if (colIn + 1 > nCol) {
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
	if (rowIn + 1 > nRow) {
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
	else if (critterSim[colIn - 1][rowIn] == nullptr) {
		adjacents[3] = EMPTY;
	}
	else if (critterSim[colIn - 1][rowIn]->getCritterType() == ANT) {
		adjacents[3] = ANT_SPACE;
	}
	else if (critterSim[colIn - 1][rowIn]->getCritterType() == DOODLEBUG) {
		adjacents[3] = DOODLEBUG_SPACE;
	}
}


