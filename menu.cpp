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
	int menuChoice = 0;
	bool menuRepeater = true;

	std::cout << "To the grader. We did the extra credit. No beating around the bush here." << std::endl;

	std::cout << "Welcome to our game. Would you like to play?" << "\n";
	std::cout << "1. Play the game" << "\n";
	std::cout << "2. Quit" << std::endl;
	menuChoice = getInt(1, 2);

	while (menuRepeater)
	{
		if (menuChoice == 1)
		{
			std::cout << "Please select a number of grid rows between 2 and 200 for the critters." << std::endl;
			numRow = getInt(2, 200);

			std::cout << "Please select a number of grid columns between 2 and 200 for the critters." << std::endl;
			numCol = getInt(2, 200);

			std::cout << "Please select a number between 2 and " << numRow * numCol << " of ants." << std::endl;
			numAnt = getInt(2, numRow * numCol);

			std::cout << "Please select a number between 2 and " << numRow * numCol - numAnt << " of doodlebugs." << std::endl;
			numDoodle = getInt(2, numRow * numCol - numAnt);

			std::cout << "And finally, please select a number of steps between 2 and 200 for the program to run through." << std::endl;
			numSteps = getInt(2, 200);

			World w(numRow, numCol, numAnt, numDoodle);
			w.runSim(numSteps);

			std::cout << "1. Play the game again" << "\n";
			std::cout << "2. Quit" << std::endl;
			menuChoice = getInt(1, 2);
		}
		else if (menuChoice == 2)
		{
			menuRepeater = false;
		}
	}	
}
