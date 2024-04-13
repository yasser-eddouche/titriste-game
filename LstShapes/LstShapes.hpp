#pragma once
#include "../game/game.hpp"
#include <iostream>

class LstShapes{
    
    Piece *piece;
    LstShapes *nextShape;
    LstShapes *prevShape;
    
    public:
        LstShapes();
        ~LstShapes();
        void findSameShape(LstShapes**,LstPieces **,Shapes);
        void insertShapeRight(LstShapes**,Piece*);
        void clearList(LstShapes **lstShapes);
        void printList(LstShapes*);
        void shiftLeft(LstShapes **);
        void adjustPositions(LstShapes **lstShapes, LstPieces **lstPieces, Shapes shape);
};
