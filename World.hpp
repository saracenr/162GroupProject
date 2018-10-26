#ifndef WORLD_H
#define WORLD_H

#include <vector>

using std::vector;
#include "Doodlebug.hpp"
#include "Ant.hpp"

class World
{
	private:	
		Critter*** critterSim;
		int numAnts;
		int numDoodles;
		int nRow;
		int nCol;
		vector<spaceType> adjacents; //to hold all adjacent spaces (0-up, 1-r, 2-d, 3-l)
		direction breedDir;
	public: 
		World(int nr=20, int nc=20, int na=100, int nd=5); //WIP
		~World(); 
		void runIter(); //WIP
		void resetCritters(); 
		void moveCritters(critterType c); //WIP
		void breedCritters(critterType c); //WIP
		void starveCritters(); //WIP
		void printGrid(); 
		void runSim(int nSteps); //WIP
		void setAdjacent(int, int);
		bool inBounds(int r, int c);

};


#endif