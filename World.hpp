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


#ifndef WORLD_H
#define WORLD_H

#include "Doodlebug.hpp"
#include "Ant.hpp"
#include <vector>

using std::vector;

class World
{
	private:	
		Critter*** critterSim;
		int numAnts;
		int numDoodles;
		int nRow;
		int nCol;
		vector<spaceType> adjacents;//holds adjacent spaces (0-u, 1-r, 2-d, 3-l)
	public: 
		World(int nr=20, int nc=20, int na=100, int nd=5);
		~World(); 
		void runIter();
		void resetCritters(); 
		void moveCritters(critterType c);
		void breedCritters(critterType c);
		void starveCritters();
		void printGrid(); 
		void runSim(int nSteps);
		void setAdjacent(int, int);
		bool inBounds(int r, int c);

};


#endif