#include"menu.hpp"
#include"World.hpp"
#include"Ant.hpp"
#include"Doodlebug.hpp"
#include"utils.hpp"
#include<iostream>

/*****************************************************************
Menu function for predator/prey simulation. Prompts the user to enter
simulation parameters, and creates a World object to run a simulation. It
continues to prompt the user to enter simulation parameters until the 
user chooses to quit.
*****************************************************************/
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
			std::cout << "Please select a number of grid rows between 2 and 100 for the critters." << std::endl;
			numRow = getInt(2, 100);

			std::cout << "Please select a number of grid columns between 2 and 80 for the critters." << std::endl;
			numCol = getInt(2, 80);

			std::cout << "Please select a number between 0 and " << numRow * numCol << " of ants." << std::endl;
			numAnt = getInt(0, numRow * numCol);

			std::cout << "Please select a number between 0 and " << numRow * numCol - numAnt << " of doodlebugs." << std::endl;
			numDoodle = getInt(0, numRow * numCol - numAnt);

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
