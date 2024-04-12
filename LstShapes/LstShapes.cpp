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
    // this->shape = shape;
    // shape=shape;
    LstPieces *currentPiece = *lstPieces;
    // cout<<"Shape: "<<shape<<endl;
    do{
        if(currentPiece->piece->shape == shape){
            Piece* newPiece=new Piece();
            newPiece->color = currentPiece->piece->color;
            newPiece->shape = shape;
            // cout<<"Color: "<<currentPiece->piece->color<<", Shape: "<<currentPiece->piece->shape<<endl;
            insertShapeRight(lstShapes, newPiece);
        }
        currentPiece = currentPiece->next;
    } while (currentPiece != *lstPieces);
    
}

void LstShapes::insertShapeRight(LstShapes **lstShapes, Piece *newPiece) {
    // Create a new node
    LstShapes *newNode = new LstShapes();
    newNode->piece = newPiece;

    // If the list is empty, make the new node the head and tail
    if (*lstShapes == nullptr) {
        newNode->prevShape = newNode;  // The new node's prevShape points to itself
        newNode->nextShape = newNode;  // The new node's nextShape points to itself
        *lstShapes = newNode;
    } else {
        // If the list is not empty, find the last node
        LstShapes *last = (*lstShapes)->prevShape;

        // Check if last is not nullptr before trying to access its members
        if (last != nullptr) {
            // Insert the new node at the end of the list
            last->nextShape = newNode;
            newNode->prevShape = last;

            // Make the new node's nextShape point to the first node
            newNode->nextShape = *lstShapes;

            // Make the first node's prevShape point to the new node
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

    // Shift the head pointer to the next node
    *lstShapes = (*lstShapes)->nextShape;
}

void LstShapes::adjustPositions(LstShapes **lstShapes, LstPieces **lstPieces, Shapes shape) {
    LstShapes *currentShape = *lstShapes;
    LstPieces *currentPiece = *lstPieces;

    // Iterate over the LstShapes list
    do{
        // Iterate over the LstPieces list
        do {
            // If the shapes match, replace the piece's color and shape
            if (currentPiece->piece->shape == shape) {
                currentPiece->piece->color = currentShape->piece->color;

                // Move to the next shape
                currentShape = currentShape->nextShape;

                // Break the loop as we found a matching piece
                cout<<"Color: "<<currentPiece->piece->color<<", Shape: "<<currentPiece->piece->shape<<endl;
            }

            // Move to the next piece
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
        // delete temp;
    } while (current != *lstShapes);

    *lstShapes = nullptr;
}