main: main.o list.o misc.o
	g++ -Wall -pedantic -g -o main main.o list.o misc.o
main.o: main.cpp list.h weather.h misc.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp
list.o: list.cpp list.h weather.h
	g++ -Wall -pedantic -g -std=c++11 -c list.cpp
misc.o: misc.cpp misc.h
	g++ -Wall -pedantic -g -std=c++11 -c misc.cpp
clean:
	rm -rf main.o list.o misc.o main 
