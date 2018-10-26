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
		vector<spaceType> adjacents; //to hold all adjacent spaces (0-up, 1-r, 2-d, 3-l)
	public: 
		World(int nr=20, int nc=20, int na=100, int nd=5);
		~World(); 
		void runIter();
		void resetCritters(); 
		void moveCritters(critterType c);
		void breedCritters(critterType c); //WIP
		void starveCritters();
		void printGrid(); 
		void runSim(int nSteps);
		void setAdjacent(int, int);
		bool inBounds(int r, int c);

};


#endif