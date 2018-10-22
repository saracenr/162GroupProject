
#ifndef CRITTER_HPP
#define CRITTER_HPP

enum critterType {ANT, DOODLEBUG};
enum spaceType {ANT_SPACE, DOODLEBUG_SPACE, EMPTY, OUTOFBOUNDS};
enum direction {NONE=-1, UP, RIGHT, DOWN, LEFT};

class Critter {
public:
    Critter(){};
    Critter(int, int, critterType);
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    void resetMoved();
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
