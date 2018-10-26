
#ifndef CRITTER_HPP
#define CRITTER_HPP

enum critterType {ANT, DOODLEBUG};
enum spaceType {ANT_SPACE, DOODLEBUG_SPACE, EMPTY, OUTOFBOUNDS};
enum direction {NONE=-1, UP, RIGHT, DOWN, LEFT};

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
    void incBreed();  //  Increments stepsSinceBreed.
    void resetBreed();  //  Sets stepsSinceBreed to 0.
    void incEat();  //  Increments stepsSinceEat.
    void resetEat();  //  Sets stepsSinceEat to 0.
    critterType getCritterType();
    virtual bool move()=0;
    virtual direction breed()=0;
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
