#include "World.hpp"
#include <cstdlib>
#include <random>
#include <ctime>

int main()
{
	//unsigned seed = time(0);
	//srand(seed);

	World w;
	w.resetCritters();
	w.printGrid();
	
	return 0;
}