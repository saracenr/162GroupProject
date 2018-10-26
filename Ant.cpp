
#include <random>
#include "Ant.hpp"

Ant::Ant(int xCoord_, int yCoord_): Critter(xCoord_, yCoord_, ANT) {}

bool Ant::move(vector<spaceType> spaces) {
    std::random_device rd;  // Seeds the random number.// RJ - move seeding to main?
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> ran(0, 3); //  Random number from 0 to 3. (up[0], right[1], down[2], left[3])
    int movement;
    movement = ran(rd);  // Generate the random number.

    if (movement == UP) {  // Checks if space above is empty and moves and increments values.
        if (spaces[0] == EMPTY) {
            setY(getY() + 1);
            hasMoved();
            incBreed();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == RIGHT) {  // Checks if space to the right is empty and moves and increments values.
        if (spaces[1] == EMPTY) {
            setX(getX() + 1);
            hasMoved();
            incBreed();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == DOWN) {  // Checks if space below is empty and moves and increments values.
        if (spaces[2] == EMPTY) {
            setY(getY() - 1);
            hasMoved();
            incBreed();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == LEFT) {  // Checks if space to left is empty and moves and increments values.
        if (spaces[3] == EMPTY) {
            setX(getX() - 1);
            hasMoved();
            incBreed();
            return true;
        }
        else {
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
	if (getBreed() == 3) {
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
		}

		resetBreed();
	}
	return retDir;
}

bool Ant::starve() {}