#include "World.hpp"
#include <cstdlib>
#include <random>
#include <ctime>

int main()
{
	unsigned seed = time(0);
	srand(seed);

	World w;
	w.printGrid();
	//w.moveCritters(DOODLEBUG);
	w.breedCritters(DOODLEBUG);
	w.printGrid();
	//w.moveCritters(ANT);
	//w.printGrid();
	//w.resetCritters();
	
	return 0;
}