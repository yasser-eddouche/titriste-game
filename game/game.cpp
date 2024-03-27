#include "game.h"

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




// LstPieces* LstPieces::insertPieceLeft(LstPieces *list, Color color, Shapes shape) {
//     // Crée une nouvelle pièce
//     Piece newPiece;
//     newPiece.color = color;
//     newPiece.shape = shape;

//     // Crée un nouveau nœud pour la nouvelle pièce
//     LstPieces *newNode = new LstPieces();
//     newNode->piece = new Piece(newPiece);

//     // Vérifie si la liste est vide
//     if (list == nullptr) {
//         newNode->next = newNode; // Nouveau nœud pointe vers lui-même car il est le seul nœud dans la liste
//         return newNode; // Retourne le nouveau nœud car c'est maintenant la tête de la liste
//     }

//     // Si la liste n'est pas vide, insère le nouveau nœud à gauche de la pièce actuelle
//     LstPieces *current = list;
//     // while (current->next != list) {
//         current = current->next; // Avance jusqu'au dernier nœud de la liste
//     // }
//     // Insère le nouveau nœud après le dernier nœud actuel
//     list=newNode;// Nouveau nœud pointe vers la tête de la liste
//     newNode->next=current;

//     printf("Piece inserted left\n");
//     return newNode; // Retourne le nouveau nœud inséré
// }

// LstPieces *LstPieces::insertPieceRight(LstPieces *list, Color color, Shapes shape) {
//     // Crée une nouvelle pièce
//     Piece newPiece;
//     newPiece.color = color;
//     newPiece.shape = shape;

//     // Crée un nouveau nœud pour la nouvelle pièce
//     LstPieces *newNode = new LstPieces();
//     newNode->piece = new Piece(newPiece);

//     // Vérifie si la liste est vide
//     if (list == nullptr) {
//         newNode->next = newNode; // Nouveau nœud pointe vers lui-même car il est le seul nœud dans la liste
//         return newNode; // Retourne le nouveau nœud car c'est maintenant la tête de la liste
//     }

//     // Si la liste n'est pas vide, insère le nouveau nœud à droite de la pièce actuelle
//    // Trouve le dernier nœud de la liste (queue)
//     LstPieces *tail = list;
//     while (tail->next != list) {
//         tail = tail->next;
//     }

//     // Insère le nouveau nœud après le dernier nœud actuel
//     tail->next =newNode;
//     newNode->next = list; 

//     printf("Piece inserted Right\n");
//     return newNode; // Retourne le nouveau nœud inséré
// }
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
        do{
        cout << "Piece: " << current->piece->color << " " << current->piece->shape << endl;
        current = current->next;
        }while (current != list);
        
    }
    printf("Printing list\n");

    //  cout << "Piece: " << current->piece->color << " " << current->piece->shape << endl;
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
