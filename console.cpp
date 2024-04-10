#include <iostream>
// #include "game/game.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime> 
#include "gui/Gui.hpp"
#include <queue>
// #include <SFML/Graphics.hpp>  // For time()
using namespace std;

int main() {
    srand(time(NULL));
    int score = 0;
    std::queue<std::pair<Color, Shapes>> nextPiecesQueue;
    // Création de la liste de pièces
    LstPieces *list = NULL;
    // Gui game(list);
    int numPieces = rand() % 2 + 4; // Generates either 4 or 5
    // for (int i = 0; i < numPieces; ++i) {
    //     Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
    //     Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape

    //     list->insertPieceRight(&list, randomColor, randomShape); // Insert the random piece to the right
    // }
    list->initialInsert(&list, numPieces);
    list->printList();
    // game.gamePage(list);
    // Ajout des pièces à la liste via le clavier
     numPieces = rand() % 2 + 4; // Generates either 4 or 5
    for (int i = 0; i < numPieces; ++i) {
        Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
        Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape

        nextPiecesQueue.push(std::make_pair(randomColor, randomShape)); // Insert the random piece into the queue
    }
    while (true) {
        
        

        while (!nextPiecesQueue.empty()) {
            
       
 
        // cout<<"\nPiece: "<<randomColor<<" "<<randomShape<<endl;
        std::queue<std::pair<Color, Shapes>> copyQueue = nextPiecesQueue;
        while (!copyQueue.empty()) {
            std::pair<Color, Shapes> piece = copyQueue.front();
            copyQueue.pop();
            
            std::cout << "Color: " << piece.first << ", Shape: " << piece.second << std::endl;
        }
        std::pair<Color, Shapes> piece = nextPiecesQueue.front();
        nextPiecesQueue.pop();

        char choice;
        std::cout << "Do you want to insert to the left (l) or right (r) of the existing piece? ";
        std::cin >> choice;

        switch (choice) {
            case 'l':
                list->insertPieceLeft(&list, piece.first, piece.second); // Insert to the left
                break;
            case 'r':
                list->insertPieceRight(piece.first, piece.second); // Insert to the right
                break;
            default:
                std::cout << "Invalid choice, the piece will be added to the end." << std::endl;
                list->insertPieceRight(piece.first, piece.second); // Insert to the right
        }
        list->printList();
        cout << "befor ------------"<<endl;
        list->vanishPiece(&list,score);
        cout << "after ------------"<<endl;
        list->printList();
        Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
        Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape
        nextPiecesQueue.push(std::make_pair(randomColor, randomShape));
        }
        
    }

 

    return 0;
}