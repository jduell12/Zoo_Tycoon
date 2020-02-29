zoo: main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o InputValid.o
	g++ main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o InputValid.o -o zoo

main.o: main.cpp
	g++ -c main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -c Animal.cpp
	
Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp
	
Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp
	
Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

InputValid.o: InputValid.hpp InputValid.cpp
	g++ -c InputValid.cpp

clean:
	rm *.o zoo
