#include "World.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <random>
#include <ctime>

int main()
{
	unsigned seed = time(0);
	srand(seed);

	World w;
	w.printGrid();
	for (int i = 0; i < 10; i++) {
		w.moveCritters(DOODLEBUG);
		w.printGrid();
		w.resetCritters();
	}
	w.breedCritters(DOODLEBUG);
	w.printGrid();
	//w.moveCritters(ANT);
	//w.printGrid();
	//w.resetCritters();
	
	return 0;
}