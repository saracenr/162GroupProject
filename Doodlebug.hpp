/*****************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Class: Doodlebug
 *
 * Arguments: Constructor takes (int xCoordinate, int yCoordinate)
 *
 * Description: This class represents the doodlebug for the simulation.  It has 
 * all the member variables from critter.  It has a move function that takes a 
 * vector with the spaceType of each adjacent space relative to its location 
 * (up[0], right[1], down[2], left[3]). The move function will prioritize 
 * moving into adjacent ants for the doodlebug to eat, otherwise it will 
 * randomly try to move in a direction like an ant. It has a breed function
 *  that will return a random empty adjacent space if possible for a new 
 * doodlebug to be created.
 *****************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include <random>
#include "Critter.hpp"

class Doodlebug: public Critter {
public:
    Doodlebug(int, int);
    bool move(vector<spaceType>);
    direction breed(vector<spaceType>);
    bool starve();
    ~Doodlebug(){};
};

#endif //DOODLEBUG_HPP
