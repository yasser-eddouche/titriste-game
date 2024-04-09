#include <iostream>
// #include "game/game.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime> 
#include "gui/Gui.hpp"
// #include <SFML/Graphics.hpp>  // For time()
using namespace std;

int main() {
    srand(time(NULL));

    // Création de la liste de pièces
    LstPieces *list = NULL;
    // Gui game(list);
    // int numPieces = rand() % 2 + 4; // Generates either 4 or 5
    // for (int i = 0; i < numPieces; ++i) {
    //     Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
    //     Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape

    //     list->insertPieceRight(&list, randomColor, randomShape); // Insert the random piece to the right
    // }
    list->initialInsert(&list, numPieces);
    list->printList(list);
    game.gamePage(list);
    // Ajout des pièces à la liste via le clavier
    while (true) {
        

        Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
    Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape

 
        cout<<"\nPiece: "<<randomColor<<" "<<randomShape<<endl;

        char choice;
        cout << "Voulez-vous inserer a gauche (l) ou a droite (r) de la piece existante ? ";
        cin >> choice;

        switch (choice) {
            case 'l':
                list->insertPieceLeft(&list,randomColor,randomShape); // Insérer à gauche
                
                break;
            case 'r':
                list->insertPieceRight(randomColor,randomShape); // Insérer à droite
                
                break;
            default:
                cout << "Choix invalide, la pièce sera ajoutée à la fin." << endl;
                list->insertPieceRight(randomColor,randomShape); // Insérer à droite
        }
        list->printList(list);
        cout << "befor ------------"<<endl;
        list->vanishPiece(&list);
        cout << "after ------------"<<endl;
        list->printList(list);
        

    }

 

    return 0;
}