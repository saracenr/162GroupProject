/*****************************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russel James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Class: Critter
 *
 * Arguments: Constructor takes (int xCoordinate, int yCoordinate, critterType bugType)
 * Member variables: xCoord, yCoord, bugType, hasMovedThisTurn, stepsSinceEat, stepsSinceBreed
 *
 * Description: This class is the base critter class for the simulation.
 * It has virtual move, breed and starve functions for derived classes to define.
 * With getters and setters for each member variable.  As well as resetting and incrementing
 * functions for the counting steps variables.
 *******************************************************************************************/
#include "Critter.hpp"

Critter::Critter(int xCoord_, int yCoord_, critterType bugType_) {
    xCoord = xCoord_;
    yCoord = yCoord_;
    bugType = bugType_;
    hasMovedThisTurn = true;
    stepsSinceEat = 0;
    stepsSinceBreed = 0;
};

int Critter::getX() {
    return xCoord;
}

void Critter::setX(int xCoord_) {
    xCoord = xCoord_;
}

int Critter::getY() {
    return yCoord;
}

void Critter::setY(int yCoord_) {
    yCoord = yCoord_;
}

void Critter::resetMoved() {
    hasMovedThisTurn = false;
}

void Critter::hasMoved() {
    hasMovedThisTurn = true;
}

bool Critter::getMoved(){
    return hasMovedThisTurn;
}

int Critter::getBreed() {
    return stepsSinceBreed;
}

void Critter::incBreed() {
    stepsSinceBreed++;
}

void Critter::resetBreed() {
    stepsSinceBreed = 0;
}

int Critter::getEat() {
    return stepsSinceEat;
}

void Critter::incEat() {
    stepsSinceEat++;
}

void Critter::resetEat() {
    stepsSinceEat = 0;
}

critterType Critter::getCritterType() {
    return bugType;
}



