all:
	# g++ -o main main.cpp game/game.cpp -lncurses
	# ./main
	g++ -c test.cpp gui/Gui.cpp game/game.cpp shapes/shapes.cpp   -lncurses
	g++ test.o Gui.o game.o shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
	# g++ -c main.cpp gui/Gui.cpp game/game.cpp shapes/shapes.cpp -lncurses
	# g++ main.o Gui.o game.o shapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	# ./sfml-app
	# rm *.o
	# g++ -o tit tit.cpp -lncurses
	# ./tit