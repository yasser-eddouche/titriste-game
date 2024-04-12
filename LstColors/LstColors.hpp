#pragma once
#include "../game/game.hpp"
#include <iostream>

class LstColors{
    
    Piece *piece;
    LstColors *nextColor;
    LstColors *prevColor;
    // LstPieces *correspondingPiece;
    public:
        LstColors();
        ~LstColors();
        void findSameColor(LstColors**,LstPieces **,Color);
        void insertColorRight(LstColors**,Piece*);
        void clearList(LstColors **lstColors);
        void printList(LstColors*);
        void shiftLeft(LstColors **);
        void adjustPositions(LstColors **lstColors, LstPieces **lstPieces, Color color);
        

};