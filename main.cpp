#include <iostream>
#include "game/game.h"

using namespace std;

int main() {
    // Création de la liste de pièces
    LstPieces *list = NULL;

    // Ajout des pièces à la liste via le clavier
    while (true) {
        string colorStr, shapeStr;
        cout << "Entrez la couleur de la piece (red, green, blue, yellow) ou 'exit' pour quitter : ";
        cin >> colorStr;
        if (colorStr == "exit") break;
        cout << "Entrez la forme de la piece (circle, square, triangle, diamond) : ";
        cin >> shapeStr;

        Color color = getColorFromString(colorStr);
        Shapes shape = getShapeFromString(shapeStr);

        // Piece newPiece;
        // newPiece.color = color;
        // newPiece.shape = shape;

        char choice;
        cout << "Voulez-vous inserer a gauche (l) ou a droite (r) de la piece existante ? ";
        cin >> choice;

        switch (choice) {
            case 'l':
                list->insertPieceLeft(&list,color,shape); // Insérer à gauche
                break;
            case 'r':
                list->insertPieceRight(&list,color,shape); // Insérer à droite
                break;
            default:
                cout << "Choix invalide, la pièce sera ajoutée à la fin." << endl;
                list->insertPieceRight(&list,color,shape); // Insérer à droite
        }
        list->printList(list);
        

    }

 

    return 0;
}