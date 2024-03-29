#pragma once
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
        // LstPieces *head; // Pointeur de tête pour la liste
        // LstPieces *last; // Pointeur de queue pour la liste
        LstPieces();
        ~LstPieces();
        
        void insertPieceLeft(LstPieces**, Color color, Shapes shape);
        void insertPieceRight(LstPieces**, Color color, Shapes shape) ;

        void printList(LstPieces*);
};

Color getColorFromString(const string& colorStr);
Shapes getShapeFromString(const string& shapeStr);


