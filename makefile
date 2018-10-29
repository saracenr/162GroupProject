
doodle: worldMain.o Ant.o World.o utils.o Critter.o Doodlebug.o menu.o
	g++ worldMain.o Ant.o World.o utils.o Critter.o Doodlebug.o menu.o -o doodle

Critter.o: Critter.cpp
	g++ -std=c++11 -c Critter.cpp

worldMain.o: worldMain.cpp
	g++ -std=c++11 -c worldMain.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++11 -c Ant.cpp

World.o: World.cpp World.hpp
	g++ -std=c++11 -c World.cpp

utils.o: utils.cpp utils.hpp
	g++ -std=c++11 -c utils.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	g++ -std=c++11 -c Doodlebug.cpp
	
menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o doodle
