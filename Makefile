all : turtix.out

turtix.out : main.o Mission.o Map.o Turtle.o Turtle_baby.o
	g++ -std=c++11 main.o Mission.o Map.o Turtle.o Turtle_baby.o -o turtix.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o : main.cpp Mission.hpp Map.hpp Turtle.hpp
	g++ -std=c++11 -c main.cpp

Mission.o : Mission.hpp Mission.cpp Map.hpp Turtle.hpp Turtle_baby.hpp
	g++ -std=c++11 -c Mission.cpp

Map.o : Map.hpp Map.cpp Turtle.hpp Turtle_baby.hpp
	g++ -std=c++11 -c Map.cpp

Turtle.o : Turtle.hpp Turtle.cpp
	g++ -std=c++11 -c Turtle.cpp	

Turtle_baby.o : Turtle.hpp Turtle_baby.cpp Turtle_baby.hpp
	g++ -std=c++11 -c Turtle_baby.cpp

clean : 
	rm *.o turtix.out