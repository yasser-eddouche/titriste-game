#include "game.hpp"
#include <unordered_set>

LstPieces::LstPieces() {
    piece = nullptr;
    next = nullptr;
}

LstPieces::~LstPieces() {
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
            newNode->next = newNode;
            *list = newNode;
        } else {
            LstPieces *tail = *list;
            while (tail->next != *list) {
                tail = tail->next;
            }

            tail->next = newNode;
            newNode->next = *list;
        }
    }
}

void LstPieces::insertPieceRight(LstPieces **list,Color color, Shapes shape) {
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);

    if (*list == nullptr) {
        newNode->next = newNode;
        *list = newNode;
    } else {
        LstPieces *tail = *list;
        while (tail->next != *list) {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->next = *list;
    }

    printf("Piece inserted Right\n");
}

void LstPieces::insertPieceLeft(LstPieces **list, Color color, Shapes shape) {
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);
    
    if (*list == nullptr) {
        newNode->next = newNode;
        *list = newNode;
    } else {
        LstPieces *tail = *list;
        while (tail->next != *list) {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->next = *list;
    }
    *list = newNode;
    printf("Piece inserted left\n");
}

void LstPieces::printList(LstPieces *list){
    LstPieces *current = list;
    if (list != NULL) {
        printf("Printing list { ");

        do{
            cout << "Piece: " << current->piece->color << " " << current->piece->shape << "  ";
            current = current->next;
        }while (current != list);
        printf(" }\n");
    }
}

void LstPieces::vanishPiece(LstPieces **list, int &score) {
    if (*list == NULL || (*list)->next == *list || (*list)->next->next == *list)
        return;

    int count = countPieces();
    LstPieces *beforePrev = NULL;
    LstPieces *prev = *list;
    LstPieces *current = prev->next;
    LstPieces *next = current->next;

    std::unordered_set<LstPieces*> toDelete;

    do {
        if ((prev->piece->color == current->piece->color && current->piece->color == next->piece->color && next != *list) ||
            (prev->piece->shape == current->piece->shape && current->piece->shape == next->piece->shape && next != *list)) {
            cout << "3 consecutive pieces with the same color or shape" << endl;

            if (count == 3) {
                LstPieces *current = *list;
                LstPieces *next;

                do {
                    next = current->next;
                    delete current->piece;
                    delete current;
                    current = next;
                } while (current != *list);

                *list = NULL;
                break;
            }

            toDelete.insert(prev);
            toDelete.insert(current);
            toDelete.insert(next);
            score++;

            if (beforePrev == NULL) {
                *list = next->next;
                prev = *list;
            } else {
                beforePrev->next = next->next;
                prev = beforePrev;
            }
            current = prev->next;
            next = current->next;
        } else {
            beforePrev = prev;
            prev = current;
            current = next;
            next = next->next;
        }
    } while (current != *list && toDelete.find(current) == toDelete.end());

    for (LstPieces* node : toDelete) {
        cout<<node->piece->color<<" "<<node->piece->shape<<endl;

        LstPieces* current = *list;
        LstPieces* prev = NULL;
        do {
            if (current->next == node) {
                current->next = node->next;
                if (node == *list) {
                    *list = node->next;
                }
                break;
            }
            prev = current;
            current = current->next;
        } while (current != *list);

        delete node->piece;
        delete node;
    }

    if (toDelete.empty()) {
        cout << "No three consecutive pieces with the same color or shape found in the list!!!\n";
    }
}
int LstPieces::countPieces() {
    int count = 0;
    LstPieces *current = this;
    do{
        count++;
        current = current->next;
    } while (current != this);
    return count;
}
// void LstPieces::moveLastPieceToLeft(LstPieces **list) {
//     if (*list == nullptr || (*list)->next == *list) {
//         // If the list is empty or has only one node, there's nothing to do
//         return;
//     }
//     // Find the last node and the node before the last node
//     LstPieces *last = *list;
//     LstPieces *beforeLast = nullptr;
//     while (last->next != *list) {
//         beforeLast = last;
//         last = last->next;
//     }
//     cout<<last->piece->color<<" "<<last->piece->shape<<endl;
//     last->next = *list;
//     *list = last;
// }