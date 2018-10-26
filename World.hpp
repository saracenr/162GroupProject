#ifndef WORLD_H
#define WORLD_H

#include "Critter.hpp"

class World
{
	private:	
		Critter*** critterSim;
		int numAnts;
		int numDoodles;
		int nRow;
		int nCol;
	public: 
		World(int nr=20, int nc=20, int na=100, int nd=5); //WIP
		void runIter(); //WIP
		void resetCritters(); //WIP
		void moveCritters(critterType c); //WIP
		void breedCritters(critterType c); //WIP
		void starveCritters(); //WIP
		void printGrid(); //WIP
		void runSim(int nSteps); //WIP
		~World(); //WIP

};


#endif