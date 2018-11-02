/*****************************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
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

/*****************************************************************
Critter constructor. Takes starting coordinates and critter type. 
Sets counters to zero to start.
*****************************************************************/
Critter::Critter(int xCoord_, int yCoord_, critterType bugType_) {
    xCoord = xCoord_;
    yCoord = yCoord_;
    bugType = bugType_;
    hasMovedThisTurn = true;
    stepsSinceEat = 0;
    stepsSinceBreed = 0;
};

/*****************************************************************
get X coordinate of critter
*****************************************************************/
int Critter::getX() {
    return xCoord;
}

/*****************************************************************
set X coordinate of critter
*****************************************************************/
void Critter::setX(int xCoord_) {
    xCoord = xCoord_;
}

/*****************************************************************
get Y coordinate of critter
*****************************************************************/
int Critter::getY() {
    return yCoord;
}

/*****************************************************************
set Y coordinate of critter
*****************************************************************/
void Critter::setY(int yCoord_) {
    yCoord = yCoord_;
}

/*****************************************************************
Reset bool indicating whether the critter has moved 
*****************************************************************/
void Critter::resetMoved() {
    hasMovedThisTurn = false;
}

/*****************************************************************
Set bool indicating movement to true
*****************************************************************/
void Critter::hasMoved() {
    hasMovedThisTurn = true;
}

/*****************************************************************
Get whether the critter has moved
*****************************************************************/
bool Critter::getMoved(){
    return hasMovedThisTurn;
}

/*****************************************************************
Get number of steps since last breed
*****************************************************************/
int Critter::getBreed() {
    return stepsSinceBreed;
}

/*****************************************************************
Increment breed counter
*****************************************************************/
void Critter::incBreed() {
    stepsSinceBreed++;
}

/*****************************************************************
Reset breed counter, called when critter breeds.
*****************************************************************/
void Critter::resetBreed() {
    stepsSinceBreed = 0;
}

/*****************************************************************
Get number of steps since last meal
*****************************************************************/
int Critter::getEat() {
    return stepsSinceEat;
}

/*****************************************************************
Increment stepsSinceEat, called if critter goes a step without eating
*****************************************************************/
void Critter::incEat() {
    stepsSinceEat++;
}

/*****************************************************************
Resets stepsSinceEat, called in move function
*****************************************************************/
void Critter::resetEat() {
    stepsSinceEat = 0;
}

/*****************************************************************
Returns critterType
*****************************************************************/
critterType Critter::getCritterType() {
    return bugType;
}



