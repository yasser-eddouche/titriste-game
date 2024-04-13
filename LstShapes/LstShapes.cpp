#include "LstShapes.hpp"

LstShapes::LstShapes() {
    piece = nullptr;
    nextShape = nullptr;
    prevShape = nullptr;
}

LstShapes::~LstShapes() {
    if(piece != nullptr) {
        LstShapes *current = this;
        while (current != nullptr) {
            LstShapes *temp = current;
            current = current->nextShape;
            delete temp->piece;
            delete temp;
        }
        cout << "List deleted" << endl;
    }
}

void LstShapes::findSameShape(LstShapes **lstShapes,LstPieces **lstPieces, Shapes shape) {
    LstPieces *currentPiece = *lstPieces;
    do{
        if(currentPiece->piece->shape == shape){
            Piece* newPiece=new Piece();
            newPiece->color = currentPiece->piece->color;
            newPiece->shape = shape;
            insertShapeRight(lstShapes, newPiece);
        }
        currentPiece = currentPiece->next;
    } while (currentPiece != *lstPieces);
}

void LstShapes::insertShapeRight(LstShapes **lstShapes, Piece *newPiece) {
    LstShapes *newNode = new LstShapes();
    newNode->piece = newPiece;

    if (*lstShapes == nullptr) {
        newNode->prevShape = newNode;
        newNode->nextShape = newNode;
        *lstShapes = newNode;
    } else {
        LstShapes *last = (*lstShapes)->prevShape;

        if (last != nullptr) {
            last->nextShape = newNode;
            newNode->prevShape = last;
            newNode->nextShape = *lstShapes;
            (*lstShapes)->prevShape = newNode;
        }
    }
}

void LstShapes::printList(LstShapes *list) {
    if (list == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    LstShapes *current = this;
    std::cout << "--------------------"<< std::endl;
    do {
        if (current->piece != nullptr) {
            std::cout << "Color: " << current->piece->color << ", Shape: " << current->piece->shape << std::endl;
        }
        current = current->nextShape;
    } while (current != list);
    std::cout << "--------------------"<< std::endl;
}

void LstShapes::shiftLeft(LstShapes **lstShapes) {
    if (*lstShapes == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    *lstShapes = (*lstShapes)->nextShape;
}

void LstShapes::adjustPositions(LstShapes **lstShapes, LstPieces **lstPieces, Shapes shape) {
    LstShapes *currentShape = *lstShapes;
    LstPieces *currentPiece = *lstPieces;

    do{
        do {
            if (currentPiece->piece->shape == shape) {
                currentPiece->piece->color = currentShape->piece->color;
                currentShape = currentShape->nextShape;
                cout<<"Color: "<<currentPiece->piece->color<<", Shape: "<<currentPiece->piece->shape<<endl;
            }
            currentPiece = currentPiece->next;
        } while (currentPiece != *lstPieces);
    }while (currentShape != *lstShapes );
}

void LstShapes::clearList(LstShapes **lstShapes) {
    if (*lstShapes == nullptr) {
        return;
    }

    LstShapes *current = *lstShapes;
    do {
        LstShapes *temp = current;
        current = current->nextShape;
        delete temp->piece;
    } while (current != *lstShapes);

    *lstShapes = nullptr;
}
