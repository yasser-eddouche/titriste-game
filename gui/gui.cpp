#include <SFML/Graphics.hpp>
#include <iostream>
#include "game/game.hpp"

using namespace std;

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Creation of the list of pieces
    LstPieces *list = NULL;

    // Add pieces to the list via keyboard input
    while (true) {
        string colorStr, shapeStr;
        cout << "Enter the color of the piece (red, green, blue, yellow) or 'exit' to quit: ";
        cin >> colorStr;
        if (colorStr == "exit") break;
        cout << "Enter the shape of the piece (circle, square, triangle, diamond): ";
        cin >> shapeStr;

        Color color = getColorFromString(colorStr);
        Shapes shape = getShapeFromString(shapeStr);

        char choice;
        cout << "Do you want to insert to the left (l) or to the right (r) of the existing piece? ";
        cin >> choice;

        switch (choice) {
            case 'l':
                list->insertPieceLeft(&list, color, shape); // Insert to the left
                break;
            case 'r':
                list->insertPieceRight(&list, color, shape); // Insert to the right
                break;
            default:
                cout << "Invalid choice, the piece will be added to the end." << endl;
                list->insertPieceRight(&list, color, shape); // Insert to the right
        }
        
        // Clear the window
        window.clear(sf::Color::White);

        // Draw the shapes onto the window
        LstPieces* current = list;
        while (list != nullptr) {
            do{
            // Create SFML shape based on the color and shape of the current piece
            sf::Color fillColor;
            switch (current->piece->color) {
                case red:
                    fillColor = sf::Color::Red;
                    break;
                case green:
                    fillColor = sf::Color::Green;
                    break;
                case blue:
                    fillColor = sf::Color::Blue;
                    break;
                case yellow:
                    fillColor = sf::Color::Yellow;
                    break;
            }

            sf::Shape* sfShape;
            switch (current->piece->shape) {
                case circle:
                    sfShape = new sf::CircleShape(100);
                    break;
                case square:
                    sfShape = new sf::RectangleShape(sf::Vector2f(100, 100));
                    break;
                // Add cases for other shapes if needed
            }

            // Set position of the shape
            sfShape->setPosition(/* set x and y coordinates here */);

            // Set fill color of the shape
            sfShape->setFillColor(fillColor);

            // Draw the shape onto the window
            window.draw(*sfShape);

            // Move to the next piece in the list
            current = current->next;

            // Free dynamically allocated memory
            delete sfShape;
            }while (current != list);
        }

        // Display the window
        window.display();
    }

    return 0;
}
