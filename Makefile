all:
	# g++ -o console console.cpp game/game.cpp LstShapes/LstShapes.cpp -lncurses
	# ./console
	# g++ -c console.cpp gui/test.cpp game/CircularList.cpp shapes/shapes.cpp LstShapes/LstShapes.cpp  -lncurses
	# g++ console.o test.o CircularList.o shapes.o LstShapes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	# ./sfml-app
	g++ -c main.cpp gui/Gui.cpp game/game.cpp shapes/shapes.cpp LstShapes/LstShapes.cpp LstColors/LstColors.cpp -lncurses
	g++ main.o Gui.o game.o shapes.o LstShapes.o LstColors.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
	rm *.o
	# g++ -o tit tit.cpp -lncurses
	# ./tit