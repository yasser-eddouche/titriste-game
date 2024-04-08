#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Include <cstdlib> for rand() function
#include "../game/game.hpp"
#include "../shapes/shapes.hpp"
enum GameStatus {
    playing, win, lose
};
class Gui
{
// LstPieces *list ;
GameStatus gameStatus;
// sf::RenderWindow window;
ShapesForm shapesForm;
Color randomColor;
Shapes randomShape;
public:
    Gui(LstPieces*);
    ~Gui();
    void generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape,sf::RenderWindow&);
    void drawList(LstPieces*,ShapesForm&,sf::RenderWindow&);
    void gamePage(LstPieces*,sf::RenderWindow&);
    void winGamePage(sf::RenderWindow&);
    void loseGamePage(sf::RenderWindow&,int);
};

