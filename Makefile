all:

	g++ -c game.cpp -o game.o  -c main.cpp -o main.o game.o main.o -o main
