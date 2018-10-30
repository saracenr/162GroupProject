#include "World.hpp"
#include "utils.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	unsigned seed = time(0);
	srand(seed);

	menu();
	return 0;
}