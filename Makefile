all:
	g++ -o main main.cpp game/game.cpp -lncurses
	./main