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


	/*int randRow, randCol;
	for (int i=0; i<numAnts; i++)
	{
		randRow=(rand()%nRow);
		randCol=(rand()%nCol);

		while (critterSim[randRow][randCol]!=nullPtr)
	}*/

	// tests 
	critterSim[1][1] = new Ant(1,1);
	critterSim[1][2] = new Ant(1,2);

} //WIP

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
void World::breedCritters(critterType c){} //WIP
void World::starveCritters(){} //WIP
void World::runSim(int nSteps){} //WIP


