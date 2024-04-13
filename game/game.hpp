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
        
        LstPieces();
        ~LstPieces();
        
        void insertPieceLeft(LstPieces**, Color color, Shapes shape);
        void insertPieceRight(LstPieces**,Color color, Shapes shape) ;
        void initialInsert(LstPieces**,int );
        void vanishPiece(LstPieces**,int&);
        void printList(LstPieces*);
        int countPieces();
        // void moveLastPieceToLeft(LstPieces **list);
};

