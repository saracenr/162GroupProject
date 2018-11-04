/******************************************************************************
 * Program Name: doodle
 * Authors: Robert Saraceno, Christina Brasco, Russell James,
 * Christopher Gundlach, Amy Stockinger
 * Date: 10/24/2018
 * Class: Ant
 *
 * Arguments: Constructor takes (int xCoordinate, int yCoordinate)
 *
 * Description: This class represents the ant for the simulation.  It has all 
 * the member variables from critter.  It has a move function that takes a 
 * vector with the spaceType of each adjacent space relative to its location 
 * (up[0], right[1], down[2], left[3]). Also a breed function that will return 
 * a random empty adjacent space if possible for a new ant to be created.
 *****************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant: public Critter {
public:
    Ant(int, int);
    bool move(vector<spaceType>); 
    direction breed(vector<spaceType>);
    bool starve();
    ~Ant(){};
};

#endif //ANT_HPP
