#include "LstColors.hpp"

LstColors::LstColors() {
    piece = nullptr;
    nextColor = nullptr;
    prevColor = nullptr;
}

LstColors::~LstColors() {
    if(piece != nullptr) {
        LstColors *current = this;
        while (current != nullptr) {
            LstColors *temp = current;
            current = current->nextColor;
            delete temp->piece;
            delete temp;
        }
        cout << "List deleted" << endl;
    }
}

void LstColors::findSameColor(LstColors **lstColors,LstPieces **lstPieces, Color color) {
    LstPieces *currentPiece = *lstPieces;
    do{
        if(currentPiece->piece->color == color){
            Piece* newPiece=new Piece();
            newPiece->color = color;
            newPiece->shape = currentPiece->piece->shape;
            insertColorRight(lstColors, newPiece);
        }
        currentPiece = currentPiece->next;
    } while (currentPiece != *lstPieces);
}

void LstColors::insertColorRight(LstColors **lstColors, Piece *newPiece) {
    LstColors *newNode = new LstColors();
    newNode->piece = newPiece;

    if (*lstColors == nullptr) {
        newNode->prevColor = newNode;
        newNode->nextColor = newNode;
        *lstColors = newNode;
    } else {
        LstColors *last = (*lstColors)->prevColor;

        if (last != nullptr) {
            last->nextColor = newNode;
            newNode->prevColor = last;
            newNode->nextColor = *lstColors;
            (*lstColors)->prevColor = newNode;
        }
    }
}

void LstColors::printList(LstColors *list) {
    if (list == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    LstColors *current = this;
    std::cout << "--------------------"<< std::endl;
    do {
        if (current->piece != nullptr) {
            std::cout << "Color: " << current->piece->color << ", Shape: " << current->piece->shape << std::endl;
        }
        current = current->nextColor;
    } while (current != list);
    std::cout << "--------------------"<< std::endl;
}

void LstColors::shiftLeft(LstColors **lstColors) {
    if (*lstColors == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    *lstColors = (*lstColors)->nextColor;
}

void LstColors::adjustPositions(LstColors **lstColors, LstPieces **lstPieces, Color color) {
    LstColors *currentColor = *lstColors;
    LstPieces *currentPiece = *lstPieces;

    do{
        do {
            if (currentPiece->piece->color == color) {
                currentPiece->piece->shape = currentColor->piece->shape;
                currentColor = currentColor->nextColor;
                cout<<"Color: "<<currentPiece->piece->color<<", Shape: "<<currentPiece->piece->shape<<endl;
            }

            currentPiece = currentPiece->next;
        } while (currentPiece != *lstPieces);
    }while (currentColor != *lstColors );
}

void LstColors::clearList(LstColors **lstColors) {
    if (*lstColors == nullptr) {
        return;
    }

    LstColors *current = *lstColors;
    do {
        LstColors *temp = current;
        current = current->nextColor;
        delete temp->piece;
    } while (current != *lstColors);

    *lstColors = nullptr;
}