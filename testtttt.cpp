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
    cout << "List deleted" << endl;
}
void LstPieces::initialInsert(LstPieces **list, int numPieces) {
    for (int i = 0; i < numPieces; ++i) {
        Color randomColor = static_cast<Color>(rand() % 4);
        Shapes randomShape = static_cast<Shapes>(rand() % 4);

        // Create a new piece
        Piece newPiece;
        newPiece.color = randomColor;
        newPiece.shape = randomShape;

        // Create a new node for the new piece
        LstPieces *newNode = new LstPieces();
        newNode->piece = new Piece(newPiece);

        if (*list == nullptr) {
            // If the list is empty, the new node becomes the head of the list
            newNode->next = newNode;
            *list = newNode;
        } else {
            // Find the last node of the list (tail)
            LstPieces *tail = *list;
            while (tail->next != *list) {
                tail = tail->next;
            }

            // Insert the new node after the current last node
            tail->next = newNode;
            newNode->next = *list;  // The new node points to the head of the list
        }
    }
}

void LstPieces::insertPieceRight(Color color, Shapes shape) {
    // Créer une nouvelle pièce
    Piece newPiece;
    newPiece.color = color;
    newPiece.shape = shape;

    // Créer un nouveau nœud pour la nouvelle pièce
    LstPieces *newNode = new LstPieces();
    newNode->piece = new Piece(newPiece);

    if (this == nullptr) {
        // Si la liste est vide, le nouveau nœud devient la tête de la liste
            // newNode->next = newNode;
            // *list = newNode;
        cout << "you win" << endl;
        
    } else {
        // Trouver le dernier nœud de la liste (queue)
        LstPieces *tail = this;
        while (tail->next != this) {
            tail = tail->next;
        }

        // Insérer le nouveau nœud après le dernier nœud actuel
        tail->next = newNode;
        newNode->next = this;  // Le nouveau nœud pointe vers la tête de la liste
    }
    // delete newNode;
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
        // newNode->next = newNode;
        // *list = newNode;
        cout << "you win" << endl;
        
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
    // delete newNode;
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
    }else{
        cout<< "List is empty"<<endl;
        // break;
    }
    
}