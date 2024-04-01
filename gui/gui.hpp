#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> // Include <cstdlib> for rand() function
#include "../game/game.hpp"
#include "../shapes/shapes.hpp"
class gui
{
// LstPieces *list ;
sf::RenderWindow window;
ShapesForm shapesForm;
Color randomColor;
Shapes randomShape;
public:
    gui(LstPieces*);
    ~gui();
    void generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape);
    void drawList(LstPieces*,ShapesForm&);
    void gamePage(LstPieces*);
};

