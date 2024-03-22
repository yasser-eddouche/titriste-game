#include "game.hpp"

LstPieces::LstPieces() {
    piece = nullptr; // La première pièce est initialisée à nullptr
    next = nullptr;
    head = this; // Initialise head avec la référence à cette instance de LstPieces
}

LstPieces::~LstPieces() {
    // Libère la mémoire allouée pour chaque pièce de la liste
    LstPieces *current = head;
    while (current != nullptr) {
        LstPieces *temp = current;
        current = current->next;
        delete temp->piece; // Supprime la pièce
        delete temp; // Supprime le nœud
    }
}

void LstPieces::addPiece(const Piece& newPiece) {
    if (head->piece == nullptr) {
        // Si la liste est vide, la nouvelle pièce devient la tête de la liste
        head->piece = new Piece(newPiece);
    } else {
        // Sinon, ajoute la nouvelle pièce à la fin de la liste
        LstPieces *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new LstPieces();
        current->next->piece = new Piece(newPiece);
    }
}

void LstPieces::insertPiece(const Piece& newPiece, bool left) {
    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);

    if (left) {
        // Insère la nouvelle pièce avant la tête de la liste
        newNode->next = head;
        head = newNode;
    } else {
        // Ajoute la nouvelle pièce à la fin de la liste
        addPiece(newPiece);
    }
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
