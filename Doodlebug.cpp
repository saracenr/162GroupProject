
#include "Doodlebug.hpp"

Doodlebug::Doodlebug(int xCoord_, int yCoord_): Critter(xCoord_, yCoord_, DOODLEBUG) {}

bool Doodlebug::move(vector<spaceType> spaces) {

    bool nearbyAnt = false;
    int x = 0;
    for (; x < 4; x++) {
        if (spaces[x] == ANT_SPACE) {  //  Checks if an ant is adjacent to the doodlebug.
            nearbyAnt = true;
            break;
        }
    }

    //  If an ant is nearby it will move and eat the first one found in the loop above (up >> right >> down >> left)
    if (nearbyAnt) {
        if (x == UP) {
            setY(getY() + 1);
            hasMoved();
            incBreed();
            resetEat();
            return true;
        }
        else if (x == RIGHT) {
            setX(getX() + 1);
            hasMoved();
            incBreed();
            resetEat();
            return true;
        }
        else if (x == DOWN) {
            setY(getY() - 1);
            hasMoved();
            incBreed();
            resetEat();
            return true;
        }
        else if (x == LEFT) {
            setX(getX() - 1);
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

    if (movement == UP) {
        if (spaces[0] == EMPTY) {
            setY(getY() + 1);
            hasMoved();
            incBreed();
            incEat();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == RIGHT) {
        if (spaces[1] == EMPTY) {
            setX(getX() + 1);
            hasMoved();
            incBreed();
            incEat();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == DOWN) {
        if (spaces[2] == EMPTY) {
            setY(getY() - 1);
            hasMoved();
            incBreed();
            incEat();
            return true;
        }
        else {
            return false;
        }
    }

    if (movement == LEFT) {
        if (spaces[3] == EMPTY) {
            setX(getX() - 1);
            hasMoved();
            incBreed();
            incEat();
            return true;
        }
        else {
            return false;
        }
    }
}

direction Doodlebug::breed(vector<spaceType> spaces) //WIP
{
	return NONE;
}

bool Doodlebug::starve()  //WIP
{
	return false;
}