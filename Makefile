all:
	g++ -c main.cpp gui/Gui.cpp game/game.cpp shapes/shapes.cpp LstShapes/LstShapes.cpp LstColors/LstColors.cpp -lncurses
	g++ main.o Gui.o game.o shapes.o LstShapes.o LstColors.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
	rm *.o