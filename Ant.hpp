
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant: public Critter {
public:
    Ant(int, int);
    bool move();
    direction breed();
    bool starve();
    ~Ant(){};
};

#endif //ANT_HPP
