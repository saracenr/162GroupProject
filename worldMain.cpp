/*************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Description: This program executes a predator/prey simulation according to
 * the user's input. Upon running the doodle executable, the user will be
 * prompted to choose whether they would like to run a simulation or quit. 
 * If they choose to run a simulation, they'll be prompted to enter their
 * choices for simulation parameters, and the simulation will run.
 **************************************************************************/

#include "World.hpp"
#include "utils.hpp"
#include "menu.hpp"
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

	menu();
	return 0;
}