#include "World.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	unsigned seed = time(0);
	srand(seed);

	World w;
	w.printGrid();
	for (int i = 0; i < 5; i++) {
		w.resetCritters();
		cout << "Step: " << i << endl;
		w.moveCritters(DOODLEBUG);
		w.breedCritters(DOODLEBUG);
		w.starveCritters();
		w.printGrid();
		w.moveCritters(ANT);
		w.breedCritters(ANT);
		cout << "Step: " << i << endl;
		w.printGrid();
	}
	//w.breedCritters(DOODLEBUG);
	w.printGrid();
	//w.moveCritters(ANT);
	//w.printGrid();
	//w.resetCritters();
	
	return 0;
}