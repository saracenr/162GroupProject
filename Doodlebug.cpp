/*****************************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russel James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Class: Doodlebug
 *
 * Arguments: Constructor takes (int xCoordinate, int yCoordinate)
 *
 * Description: This class represents the doodlebug for the simulation.  It has all the
 * member variables from critter.  It has a move function that takes a vector with
 * the spaceType of each adjacent space relative to its location (up[0], right[1], down[2], left[3]).
 * The move function will prioritize moving into adjacent ants for the doodlebug to eat, otherwise
 * it will randomly try to move in a direction like an ant.
 * It has a breed function that will return a random empty adjacent space if possible for
 * a new doodlebug to be created.
 *******************************************************************************************/
#include "Doodlebug.hpp"
#include <iostream>

Doodlebug::Doodlebug(int xCoord_, int yCoord_): Critter(xCoord_, yCoord_, DOODLEBUG) {}

bool Doodlebug::move(vector<spaceType> adjacents) {

	bool nearbyAnt = false;
	direction x;
	if(adjacents[0] == ANT_SPACE) {  //  Checks if an ant is adjacent to the doodlebug.
		nearbyAnt = true;
		x = UP;
	}
	if(adjacents[1] == ANT_SPACE){
		nearbyAnt = true;
		x = RIGHT;
	}
	if(adjacents[2] == ANT_SPACE){
		nearbyAnt = true;
		x = DOWN;
	}
	if(adjacents[3] == ANT_SPACE){
		nearbyAnt = true;
		x = LEFT;
	}

	//  If an ant is nearby it will move and eat the first one found in the loop above (up >> right >> down >> left)
	if (nearbyAnt) {
		if (x == UP) {
			setX(getX() - 1);
			hasMoved();
			incBreed();
			resetEat();
			return true;
		}
		else if (x == RIGHT) {
			setY(getY() + 1);
			hasMoved();
			incBreed();
			resetEat();
			return true;
		}
		else if (x == DOWN) {
			setX(getX() + 1);
			hasMoved();
			incBreed();
			resetEat();
			return true;
		}
		else if (x == LEFT) {
			setY(getY() - 1);
			hasMoved();
			incBreed();
			resetEat();
			return true;
		}
	}



	std::random_device rd;  // Seeds the random number.
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> ran(0, 3); //  Random number from 0 to 3. (up[0], right[1], down[2], left[3])
	int movement;
	movement = ran(rd);

	if (movement == UP) {  // Checks if space above is empty and moves and increments values.
		if (adjacents[0] == EMPTY) {
			setX(getX() - 1);
			hasMoved();
			incBreed();
			incEat();
			return true;
		}
		else {
			incEat();
			incBreed();
			hasMoved();
			return false;
		}
	}

	if (movement == RIGHT) {  // Checks if space to the right is empty and moves and increments values.
		if (adjacents[1] == EMPTY) {
			setY(getY() + 1);
			hasMoved();
			incBreed();
			incEat();
			return true;
		}
		else {
			incEat();
			incBreed();
			hasMoved();
			return false;
		}
	}

	if (movement == DOWN) {  // Checks if space below is empty and moves and increments values.
		if (adjacents[2] == EMPTY) {
			setX(getX() + 1);
			hasMoved();
			incBreed();
			incEat();
			return true;
		}
		else {
			incEat();
			incBreed();
			hasMoved();
			return false;
		}
	}

	if (movement == LEFT) {  // Checks if space to left is empty and moves and increments values.
		if (adjacents[3] == EMPTY) {
			setY(getY() - 1);
			hasMoved();
			incBreed();
			incEat();
			return true;
		}
		else {
			incEat();
			incBreed();
			hasMoved();
			return false;
		}
	}
	return false;
}

/****************************************************************************
Breeds the Doodlebug. Takes adjacent spaces as parameter. Returns the 
direction doodlebug was bred. Returns NONE if no spaces available.
*****************************************************************************/
direction Doodlebug::breed(vector<spaceType> spaces) //WIP
{
	direction retDir = NONE;
	if (getBreed() >= 8) {
		vector<int> empties;
		//get empty spaces
		for (int i = 0; i < 4; i++) {
			if (spaces[i] == EMPTY) {
				empties.push_back(i);
			}
		}

		if (empties.size() > 0) {
			//get random index
			int randIndex = rand() % empties.size();
			retDir = static_cast<direction>(empties[randIndex]);
			resetBreed();
		}
	}
	return retDir;
}

bool Doodlebug::starve()  //WIP
{
	if (getEat()>=3)
	{
		return true;
	}
	else 
	{
		return false;
	}
}