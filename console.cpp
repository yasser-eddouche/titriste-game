#include <iostream>
// #include "game/game.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime> 
#include "gui/Gui.hpp"
#include <queue>
#include "LstShapes/LstShapes.hpp"
// #include <SFML/Graphics.hpp>  // For time()
using namespace std;

int main() {
    srand(time(NULL));
    int score = 0;
    std::queue<std::pair<Color, Shapes>> nextPiecesQueue;
    // Création de la liste de pièces
    char shift ;
    LstPieces *list = NULL;
    LstShapes *lstCircle =NULL; 
    // lstCircle = new LstShapes(circle);
    // list = new LstPieces();
    int numPieces = rand() % 2 + 4; // Generates either 4 or 5
    
    list->initialInsert(&list, numPieces);
    list->printList(list);
    
    
    // Ajout des pièces à la liste via le clavier
    numPieces = rand() % 2 + 4; // Generates either 4 or 5
    for (int i = 0; i < numPieces; ++i) {
        Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
        Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape

        nextPiecesQueue.push(std::make_pair(randomColor, randomShape)); // Insert the random piece into the queue
    }
    while (true) {
        
        while (!nextPiecesQueue.empty()) {
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
                list->insertPieceRight(&list,piece.first, piece.second); // Insert to the right
                break;
            default:
                std::cout << "Invalid choice, the piece will be added to the end." << std::endl;
                list->insertPieceRight(&list,piece.first, piece.second); // Insert to the right
        }
        list->printList(list);
        cout << "befor ------------"<<endl;
        list->vanishPiece(&list,score);
        cout << "after ------------"<<endl;
        list->printList(list);
        cout << "same shape ------------"<<endl;
        
        
        lstCircle->printSameShape(&lstCircle,&list,circle);
        lstCircle->printList(lstCircle);
        std::cout << "same shape ------------"<<endl;
        if (lstCircle!= nullptr)
        {
            cout << "shift :";
            cin >> shift;
            if (shift == 's'&& lstCircle != nullptr) {
                lstCircle->shiftLeft(&lstCircle);
                lstCircle->printList(lstCircle);
                lstCircle->adjustPositions(&lstCircle, &list,circle);
            }
        }
        
        
        lstCircle->clearList(&lstCircle);
        list->printList(list);
        // lstCircle==nullptr;
        Color randomColor = static_cast<Color>(rand() % 4);   // Generates a random color
        Shapes randomShape = static_cast<Shapes>(rand() % 4); // Generates a random shape
        nextPiecesQueue.push(std::make_pair(randomColor, randomShape));
        }
        
    }

 
    
    delete list;
    return 0;
}