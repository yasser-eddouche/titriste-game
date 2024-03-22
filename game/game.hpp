#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
using namespace std;

enum Color {
    red, green, blue, yellow
};

enum Shapes {
    circle, square, triangle, diamond
};

class Piece {
public:
    Color color;
    Shapes shape;
};

class LstPieces {
    public:
        Piece *piece;
        LstPieces *next;
        LstPieces *head; // Pointeur de tête pour la liste

        LstPieces();
        ~LstPieces();
        void addPiece(const Piece& newPiece);
        void insertPiece(const Piece& newPiece, bool left);
};

Color getColorFromString(const string& colorStr);
Shapes getShapeFromString(const string& shapeStr);

#endif // GAME_HPP
