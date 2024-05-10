#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "../game/game.hpp"
#include "../shapes/shapes.hpp"
#include <queue> 
#include "../LstShapes/LstShapes.hpp"
#include "../LstColors/LstColors.hpp"

enum GameStatus {
    playing, win, lose
};
class Gui
{
    private:
        std::queue<std::pair<Color, Shapes>> nextPiecesQueue;
        GameStatus gameStatus;
        ShapesForm shapesForm;
        Color randomColor;
        Shapes randomShape;
    public:
        Gui(LstPieces*);
        ~Gui();
        void generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape,sf::RenderWindow&);
        void drawList(LstPieces*,ShapesForm&,sf::RenderWindow&);
        void gamePage(LstPieces*,sf::RenderWindow&);
        void winGamePage(sf::RenderWindow&,int);
        void loseGamePage(sf::RenderWindow&,int);
        void printAllPieces();
        void drawNextPieces( ShapesForm& shapesForm, sf::RenderWindow& window);
};

