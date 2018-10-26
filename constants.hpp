#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP


// constants to indicate ASCII range of integers
const int ASCII_INT_MIN = 48;
const int ASCII_INT_MAX = 57;

enum critterType {ANT, DOODLEBUG};
enum spaceType {ANT_SPACE, DOODLEBUG_SPACE, EMPTY, OUTOFBOUNDS};
enum direction {NONE=-1, UP, RIGHT, DOWN, LEFT};

const char ANT_CHAR='O';
const char DOODLE_CHAR='X';
const char EMPTY_CHAR=' ';

#endif // !CONSTANTS_HPP
