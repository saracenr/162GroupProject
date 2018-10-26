
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

int Critter::getBreed() {
    return stepsSinceBreed;
}

void Critter::incBreed() {
    stepsSinceBreed++;
}

void Critter::resetBreed() {
    stepsSinceEat = 0;
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



