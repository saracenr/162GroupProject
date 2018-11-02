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
#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <vector>
#include "constants.hpp"

using std::vector;

class Critter {
public:
    Critter(){};
    Critter(int, int, critterType);
    int getX();  // Get x Coord.
    void setX(int);  //  Set x Coord.
    int getY();  //  Get y Coord.
    void setY(int);  // Set y Coord.
    void resetMoved();  //  Sets hasMovedThisTurn to false.
    void hasMoved();  //  Sets hasMovedThisTurn to true.
    bool getMoved();
    int getBreed();  //  Returns stepsSinceBreed.
    void incBreed();  //  Increments stepsSinceBreed.
    void resetBreed();  //  Sets stepsSinceBreed to 0.
    int getEat();  //  returns stepsSinceEat.
    void incEat();  //  Increments stepsSinceEat.
    void resetEat();  //  Sets stepsSinceEat to 0.
    critterType getCritterType();
    virtual direction breed(vector<spaceType>)=0;
    //virtual bool move(spaceType, spaceType, spaceType, spaceType) = 0;
    virtual bool move(vector<spaceType>) = 0;
    virtual bool starve()= 0;
    virtual ~Critter(){};

private:
    int xCoord;
    int yCoord;
    bool hasMovedThisTurn;
    int stepsSinceBreed;
    int stepsSinceEat;
    critterType bugType;
};

#endif //CRITTER_HPP
