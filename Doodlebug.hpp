
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include <random>
#include "Critter.hpp"

class Doodlebug: public Critter {
public:
    Doodlebug(int, int);
    bool move(vector<spaceType>);
    direction breed(vector<spaceType>);
    //bool move(spaceType, spaceType, spaceType, spaceType);
    bool starve();
    ~Doodlebug(){};
};

#endif //DOODLEBUG_HPP
