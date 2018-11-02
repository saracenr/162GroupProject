/*****************************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Class: Ant
 *
 * Arguments: Constructor takes (int xCoordinate, int yCoordinate)
 *
 * Description: This class represents the ant for the simulation.  It has all the
 * member variables from critter.  It has a move function that takes a vector with
 * the spaceType of each adjacent space relative to its location (up[0], right[1], down[2], left[3]).
 * Also a breed function that will return a random empty adjacent space if possible for
 * a new ant to be created.
 *******************************************************************************************/
#include <random>
#include "Ant.hpp"
#include <iostream>

/*****************************************************************
Ant constructor, calls Critter constructor
*****************************************************************/
Ant::Ant(int xCoord_, int yCoord_): Critter(xCoord_, yCoord_, ANT) {}

/*****************************************************************
Overridden move function for Ant. Randomly chooses a direction, moves if the 
space is empty, and if move was made returns true. Otherwise, returns false. 
Always increments steps since breed and sets moved boolean to true.
*****************************************************************/
bool Ant::move(vector<spaceType> adjacents) {
	std::random_device rd;  // Seeds the random number.
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> ran(0, 3); //  Random number from 0 to 3. (up[0], right[1], down[2], left[3])
	int movement;
	movement = ran(rd);  // Generate the random number.

	if (movement == UP) {  // Checks if space above is empty, moves/increments values.
		if (adjacents[0] == EMPTY) {
			setX(getX() - 1);
			hasMoved();
			incBreed();
			return true;
		}
		else {
			hasMoved();
			incBreed();
			return false;
		}
	}

	else if (movement == RIGHT) {  // Checks if space to the right is empty and moves and increments values.
		if (adjacents[1] == EMPTY) {
			setY(getY() + 1);
			hasMoved();
			incBreed();
			return true;
		}
		else {
			hasMoved();
			incBreed();
			return false;
		}
	}

	else if (movement == DOWN) {  // Checks if space below is empty and moves and increments values.
		if (adjacents[2] == EMPTY) {
			setX(getX() + 1);
			hasMoved();
			incBreed();
			return true;
		}
		else {
			hasMoved();
			incBreed();
			return false;
		}
	}

	else if (movement == LEFT) {  // Checks if space to left is empty and moves and increments values.
		if (adjacents[3] == EMPTY) {
			setY(getY() - 1);
			hasMoved();
			incBreed();
			return true;
		}
		else {
			hasMoved();
			incBreed();
			return false;
		}
	}
}

/*****************************************************************
Create new ant in an open adjacent space, if space exists.
Returns direction of breed.
*****************************************************************/
direction Ant::breed(vector<spaceType> spaces) 
{
	direction retDir = NONE;
	if (getBreed() >= 3) {
		vector<int> empties;
		//extract the empty spaces
		for (int i = 0; i < 4; i ++) {
			if (spaces[i] == EMPTY) {
				empties.push_back(i);
			}
		}
		
		if (empties.size() > 0) {
			//get random index
			int randIndex = rand() % empties.size(); //0 - UP; 1 - RIGHT; 2 - DOWN; 3 - LEFT
			retDir = static_cast<direction>(empties[randIndex]);
			resetBreed();
		}
	}
	return retDir;
}

/*****************************************************************
Overridden starve function. Since ant can't starve, just returns false.
*****************************************************************/
bool Ant::starve() {
	return false;
}