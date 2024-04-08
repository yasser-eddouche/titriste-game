#include "game.hpp"
#include <unordered_set>

LstPieces::LstPieces() {
    piece = nullptr;
    next = nullptr;
    // score = 0;
}

LstPieces::~LstPieces() {
    LstPieces *current = this;
    while (current != nullptr) {
        LstPieces *temp = current;
        current = current->next;
        delete temp->piece;
        delete temp;
    }
    cout << "List deleted" << endl;
}

void LstPieces::initialInsert(LstPieces **list, int numPieces) {
    for (int i = 0; i < numPieces; ++i) {
        Color randomColor = static_cast<Color>(rand() % 4);
        Shapes randomShape = static_cast<Shapes>(rand() % 4);

        Piece newPiece;
        newPiece.color = randomColor;
        newPiece.shape = randomShape;

        LstPieces *newNode = new LstPieces();
        newNode->piece = new Piece(newPiece);

        if (*list == nullptr) {
            // newNode->next = newNode;
            *list = newNode;
        } else {
            LstPieces *tail = *list;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = nullptr;
        }
    }
}

void LstPieces::insertPieceRight(Color color, Shapes shape) {
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);
    if (this->countPieces() > 10) {
        cout << "You lose" << endl;
        return;
    }
    if (this == nullptr) {
        cout << "you win" << endl;
    } else {
        LstPieces *tail = this;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = nullptr;
        
    }
    printf("Piece inserted Right\n");
}

void LstPieces::insertPieceLeft(LstPieces **list, Color color, Shapes shape) {
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);
    if (this->countPieces() > 10) {
        cout << "You lose" << endl;
        return;
    }
    if (*list == nullptr) {
        // *list = newNode;
        cout << "you win" << endl;
    } else {
        newNode->next = *list;
        *list = newNode;
    }
    printf("Piece inserted left\n");
    // Free the memory allocated for newNode
}

void LstPieces::printList(){
    LstPieces *current = this;
    if (this != NULL) {
        printf("Printing list { ");
        while (current != nullptr){
            cout << "Piece: " << current->piece->color << " " << current->piece->shape << "  ";
            current = current->next;
        }
        printf(" }\n");
    }else{
        cout<< "List is empty"<<endl;
    }}
void LstPieces::vanishPiece(LstPieces **list,int &score) {
    if (*list == NULL)
        return;

    LstPieces *beforePrev = NULL;
    LstPieces *prev = *list;
    LstPieces *current = prev->next;
    if (current == NULL)
        return;
    LstPieces *next = current->next;
    if (next == NULL)
        return;

    std::unordered_set<LstPieces*> toDelete;

    while (next != NULL) {
        if ((prev->piece->color == current->piece->color && current->piece->color == next->piece->color) ||
            (prev->piece->shape == current->piece->shape && current->piece->shape == next->piece->shape)) {

            if (beforePrev == NULL) {
                *list = next->next;
            } else {
                beforePrev->next = next->next;
            }

            toDelete.insert(prev);
            toDelete.insert(current);
            toDelete.insert(next);
            score ++;
            if (beforePrev == NULL) {
                prev = *list;
            } else {
                prev = beforePrev;
            }
            if (prev == NULL)
                break;
            current = prev->next;
            if (current == NULL)
                break;
            next = current->next;
            
        } else {
            beforePrev = prev;
            prev = current;
            current = next;
            next = next->next;
        }
    }

    for (LstPieces* node : toDelete) {
        delete node->piece;
        // delete node;
    }
    cout << "Score: " << score << endl;
    if (*list == NULL) {
        cout << "You win" << endl;
    } else {
        cout << "No three consecutive pieces with the same color or shape found in the list!!!\n";
    }
}

int LstPieces::countPieces() {
    int count = 0;
    LstPieces *current = this;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
// void LstPieces::shiftShapesByColor(Color color, Shapes shift) {
//     LstPieces *current = this;
//     while (current != nullptr) {
//         if (current->piece->color == color) {
//             current->piece->shape = shift;
//         }
//         current = current->next;
//     }
// }

// void LstPieces::shiftColorsByShape(Shapes shape, Color shift) {
//     LstPieces *current = this;
//     while (current != nullptr) {
//         if (current->piece->shape == shape) {
//             current->piece->color = shift;
//         }
//         current = current->next;
//     }
// }
Color getColorFromString(const string& colorStr) {
    if (colorStr == "r") return red;
    if (colorStr == "g") return green;
    if (colorStr == "b") return blue;
    if (colorStr == "y") return yellow;
    // Gérer le cas d'erreur ou de valeur par défaut
    return red; // Par défaut, retourne red si la couleur n'est pas valide
}

Shapes getShapeFromString(const string& shapeStr) {
    if (shapeStr == "c") return circle;
    if (shapeStr == "s") return square;
    if (shapeStr == "t") return triangle;
    if (shapeStr == "d") return diamond;
    // Gérer le cas d'erreur ou de valeur par défaut
    return square; // Par défaut, retourne square si la forme n'est pas valide
}
