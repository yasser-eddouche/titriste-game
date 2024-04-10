#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Include <cstdlib> for rand() function
#include "../game/game.hpp"
#include "../shapes/shapes.hpp"
#include <queue> 
enum GameStatus {
    playing, win, lose
};
class Gui
{
std::queue<std::pair<Color, Shapes>> nextPiecesQueue;
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
    // void generateNextPiece(std::vector<std::pair<Color, Shapes>>& nextPieces);
    // void generateNextPieces();
    void printAllPieces();
    void drawNextPieces( ShapesForm& shapesForm, sf::RenderWindow& window);
};

