
#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <vector>

enum critterType {ANT, DOODLEBUG};
enum spaceType {ANT_SPACE, DOODLEBUG_SPACE, EMPTY, OUTOFBOUNDS};
enum direction {NONE=-1, UP, RIGHT, DOWN, LEFT};

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
    virtual bool move(spaceType, spaceType, spaceType, spaceType) = 0;
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
