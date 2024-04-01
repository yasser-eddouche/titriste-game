all:
	# g++ -o main main.cpp game/game.cpp -lncurses
	# ./main
	# g++ -c gui/gui.cpp game/game.cpp shapes/shapes.cpp -lncurses
	# g++ gui.o game.o shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	# ./sfml-app
	# g++ -c test.cpp shapes/shapes.cpp   -lncurses
	# g++ test.o shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	# ./sfml-app
	g++ -c main.cpp gui/gui.cpp game/game.cpp shapes/shapes.cpp -lncurses
	g++ main.o gui.o game.o shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app