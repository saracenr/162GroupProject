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
	for (int i = 8; i < 10; i++) {
		w.moveCritters(DOODLEBUG);
	}
	w.breedCritters(DOODLEBUG);
	w.printGrid();
	//w.moveCritters(ANT);
	//w.printGrid();
	//w.resetCritters();
	
	return 0;
}