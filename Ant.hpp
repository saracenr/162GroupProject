
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant: public Critter {
public:
    Ant(int, int);
    bool move(vector<spaceType>); // Checks if a random adjacent space is empty and moves there if so.
    direction breed(vector<spaceType>);
    bool starve();
    ~Ant(){};
};

#endif //ANT_HPP
