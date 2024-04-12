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

        // Créer un nouveau nœud pour la nouvelle pièce
        LstPieces *newNode = new LstPieces();
        newNode->piece = new Piece(newPiece);

        if (*list == nullptr) {
            // Si la liste est vide, le nouveau nœud devient la tête de la liste
            newNode->next = newNode;
            *list = newNode;
        } else {
            // Trouver le dernier nœud de la liste (queue)
            LstPieces *tail = *list;
            while (tail->next != *list) {
                tail = tail->next;
            }

            // Insérer le nouveau nœud après le dernier nœud actuel
            tail->next = newNode;
            newNode->next = *list;  // Le nouveau nœud pointe vers la tête de la liste
        }
    }
}

void LstPieces::insertPieceRight(LstPieces **list,Color color, Shapes shape) {
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    // Créer un nouveau nœud pour la nouvelle pièce
    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);

    if (*list == nullptr) {
        // Si la liste est vide, le nouveau nœud devient la tête de la liste
        newNode->next = newNode;
        *list = newNode;
    } else {
        // Trouver le dernier nœud de la liste (queue)
        LstPieces *tail = *list;
        while (tail->next != *list) {
            tail = tail->next;
        }

        // Insérer le nouveau nœud après le dernier nœud actuel
        tail->next = newNode;
        newNode->next = *list;  // Le nouveau nœud pointe vers la tête de la liste
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
        // Si la liste est vide, le nouveau nœud devient la tête de la liste
        newNode->next = newNode;
        *list = newNode;
    } else {
        // Trouver le dernier nœud de la liste (queue)
        LstPieces *tail = *list;
        while (tail->next != *list) {
            tail = tail->next;
        }

        // Insérer le nouveau nœud après le dernier nœud actuel
        tail->next = newNode;
        newNode->next = *list;  // Le nouveau nœud pointe vers la tête de la liste
    }
    *list = newNode;
    printf("Piece inserted left\n");
    // Free the memory allocated for newNode
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

void LstPieces::vanishPiece(LstPieces **list,int &score) {
    if (*list == NULL )
        return;

    LstPieces *beforePrev = NULL;
    LstPieces *prev = *list;
    LstPieces *current = prev->next;
    if (current == NULL)
            return;
    LstPieces *next = current->next; 
    if (next == NULL)
        return;
    // Create a set to hold the nodes that need to be deleted
    std::unordered_set<LstPieces*> toDelete;

    do {
        if ((prev->piece->color == current->piece->color && current->piece->color == next->piece->color && next != *list) ||
            (prev->piece->shape == current->piece->shape && current->piece->shape == next->piece->shape && next != *list)) {
            cout << "3 consecutive pieces with the same color" << endl;

            if (beforePrev == NULL) {
                // The sequence starts at the head of the list
                *list = next->next;
            } else {
                beforePrev->next = next->next;
            }

            // Add the nodes to the set instead of deleting them immediately
            toDelete.insert(prev);
            toDelete.insert(current);
            toDelete.insert(next);
            score ++;
            if (beforePrev == NULL) {
                prev = *list;
            } else {
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
    } while (current != *list);

    // Now delete all the nodes in the set
    // Now delete all the nodes in the set
    for (LstPieces* node : toDelete) {
        cout<<node->piece->color<<" "<<node->piece->shape<<endl;

        // Find the node that points to this node and update its next pointer
        LstPieces* current = *list;
        do {
            if (current->next == node) {
                current->next = node->next;
                break;
            }
            current = current->next;
        } while (current != *list);

        delete node->piece;
        // delete node;
    }

    if (*list == NULL) {
        cout << "You win" << endl;
    } else {
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
void LstPieces::moveLastPieceToLeft(LstPieces **list) {
    if (*list == nullptr || (*list)->next == *list) {
        // If the list is empty or has only one node, there's nothing to do
        return;
    }
    // Find the last node and the node before the last node
    LstPieces *last = *list;
    LstPieces *beforeLast = nullptr;
    while (last->next != *list) {
        beforeLast = last;
        last = last->next;
    }
    cout<<last->piece->color<<" "<<last->piece->shape<<endl;
    last->next = *list;
    *list = last;
}