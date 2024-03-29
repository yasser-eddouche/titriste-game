all:
	# g++ -o main main.cpp game/game.cpp -lncurses
	# ./main
	g++ -c gui/gui.cpp -lncurses
	g++ gui.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app