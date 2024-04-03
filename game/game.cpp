#include "game.hpp"
// #include <vector>
#include <unordered_set>
LstPieces::LstPieces() {
    piece = nullptr; // La première pièce est initialisée à nullptr
    next = this;
    // head = this; // Initialise head avec la référence à cette instance de LstPieces
    // last = this; // Initialise tail avec la référence à cette instance de LstPieces
   
}

LstPieces::~LstPieces() {
    // // Libère la mémoire allouée pour chaque pièce de la liste
    LstPieces *current ;
    while (current != nullptr) {
        LstPieces *temp = current;
        current = current->next;
        delete temp->piece; // Supprime la pièce
        delete temp; // Supprime le nœud
    }
}


void LstPieces::insertPieceRight(LstPieces **list, Color color, Shapes shape) {
    // Créer une nouvelle pièce
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
    // Créer une nouvelle pièce
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
}
//printlistpiece
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

void LstPieces::vanishPiece(LstPieces **list) {
    if (*list == NULL || (*list)->next == *list || (*list)->next->next == *list)
        return;

    LstPieces *beforePrev = NULL;
    LstPieces *prev = *list;
    LstPieces *current = prev->next;
    LstPieces *next = current->next;

    // Create a set to hold the nodes that need to be deleted
    std::unordered_set<LstPieces*> toDelete;

    do {
        if (prev->piece->color == current->piece->color && current->piece->color == next->piece->color||prev->piece->shape == current->piece->shape && current->piece->shape == next->piece->shape) {
            cout << prev->piece->color << " " << prev->piece->shape << endl;
            cout << current->piece->color << " " << current->piece->shape << endl;
            cout << next->piece->color << " " << next->piece->shape << endl;
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
    for (LstPieces* node : toDelete) {
        cout<<node->piece->color<<" "<<node->piece->shape<<endl;
        delete node->piece;
        // delete node;
    }

    cout << "No three consecutive pieces with the same color found in the list!!!\n";
}

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
