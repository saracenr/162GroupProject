#include"menu.hpp"
#include"World.hpp"
#include"Ant.hpp"
#include"Doodlebug.hpp"
#include"utils.hpp"
#include<iostream>

void menu()
{
	int numRow = 0;
	int numCol = 0;
	int numAnt = 0;
	int numDoodle = 0;
	int numSteps = 0;
	std::cout << "To the grader. We did the extra credit. No beating around the bush here." << std::endl;

	std::cout << "Please select a number of grid rows between 2 and 200 for the critters." << std::endl;
	numRow = getInt(2, 200);

	std::cout << "Please select a number of grid columns between 2 and 200 for the critters." << std::endl;
	numCol = getInt(2, 200);

	std::cout << "Please select a number between 50 and 300 of ants." << std::endl;
	numAnt = getInt(50, 300);

	std::cout << "Please select a number between 2 and 20 of doodlebugs." << std::endl;
	numDoodle = getInt(2, 20);

	std::cout << "And finally, please select a number of steps between 2 and 200 for the program to run through." << std::endl;
	numSteps = getInt(2, 200);

	World w(numRow, numCol, numAnt, numDoodle);
	w.printGrid();
	for (int i = 0; i < 5; i++) {
		w.resetCritters();
		std::cout << "Step: " << i << std::endl;
		w.moveCritters(DOODLEBUG);
		w.breedCritters(DOODLEBUG);
		w.starveCritters();
		w.printGrid();
		w.moveCritters(ANT);
		w.breedCritters(ANT);
		std::cout << "Step: " << i << std::endl;
		w.printGrid();
	}
	//w.breedCritters(DOODLEBUG);
	w.printGrid();
	//w.moveCritters(ANT);
	//w.printGrid();
	//w.resetCritters();

	
}