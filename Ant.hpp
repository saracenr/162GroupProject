
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant: public Critter {
public:
    Ant(int, int);
    bool move(spaceType, spaceType, spaceType, spaceType); // Checks if a random adjacent space is empty and moves there if so.
    direction breed();
    bool starve();
    ~Ant(){};
};

#endif //ANT_HPP
