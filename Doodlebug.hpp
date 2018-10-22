
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug: public Critter {
public:
    Doodlebug(int, int);
    bool move();
    direction breed();
    bool starve();
    ~Doodlebug(){};
};

#endif //DOODLEBUG_HPP