lab2: main.o
	g++ -std=c++11 -g -Wall main.o -o lab2
main.o: main.cpp Hash.h Hash.hpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -std=c++11 -g -Wall -c main.cpp
clean:
	rm *.o lab2
