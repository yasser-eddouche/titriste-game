#include "Gui.hpp"

Gui::Gui(LstPieces* list)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    window.create(sf::VideoMode(1000, 600), "Titriste");
    shapesForm = ShapesForm();

    randomColor = static_cast<Color>(rand() % 4);
    randomShape = static_cast<Shapes>(rand() % 4);
    // LstPieces *list = nullptr; // Allocate memory for the first node
    
}
Gui::~Gui()
{
}
void Gui::drawList(LstPieces* list, ShapesForm& shapesForm)
{   
    LstPieces *current = list;
    sf::Color fillColor;
    sf::Vector2f position(100.f, 500.f); // Starting position for the shapes
    if (list != nullptr) {
        do {
            // Get the color and shape information from the current node
            Color color = current->piece->color;
            Shapes shape = current->piece->shape;

            switch (color) {
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
                default:
                    fillColor = sf::Color::White; // Default color
                    break;
            }
            // Draw the shape based on its type
            switch (shape) {
                case circle:
                    shapesForm.setCircle(40.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getCircle().setPosition(position);
                    window.draw(shapesForm.getCircle());
                    break;
                case square:
                    shapesForm.setSquare(70.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getSquare().setPosition(position);
                    window.draw(shapesForm.getSquare());
                    break;
                case triangle:
                    shapesForm.setTriangle(70.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getTriangle().setPosition(position);
                    window.draw(shapesForm.getTriangle());
                    break;
                case diamond:
                    shapesForm.setDiamond(60.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getDiamond().setPosition(position);
                    window.draw(shapesForm.getDiamond());
                    break;
            }

            // Update position for the next shape
            position.x += 100.f; // Adjust as needed
            position.y += 0.f;   // Adjust as needed

            // Move to the next node in the list
            current = current->next;
        } while (current != list);
    }
}
void Gui::generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape)
{
    sf::Color fillColor;
    sf::Vector2f position(100.f, 100.f); // Starting position for the shapes

    switch (randomColor) {
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
                default:
                    fillColor = sf::Color::White; // Default color
                    break;
            }
            // Draw the shape based on its type
            switch (randomShape) {
                case circle:
                    shapesForm.setCircle(40.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getCircle().setPosition(position);
                    window.draw(shapesForm.getCircle());
                    break;
                case square:
                    shapesForm.setSquare(70.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getSquare().setPosition(position);
                    window.draw(shapesForm.getSquare());
                    break;
                case triangle:
                    shapesForm.setTriangle(70.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getTriangle().setPosition(position);
                    window.draw(shapesForm.getTriangle());
                    break;
                case diamond:
                    shapesForm.setDiamond(60.f, fillColor, sf::Color::Black, 2.f);
                    shapesForm.getDiamond().setPosition(position);
                    window.draw(shapesForm.getDiamond());
                    break;
            }
}

void Gui::gamePage(LstPieces* list){
    
    int numPieces = rand() % 2 + 4;    // Generates either 4 or 5
    for (int i = 0; i < numPieces; ++i) {
         randomColor = static_cast<Color>(rand() % 4);
         randomShape = static_cast<Shapes>(rand() % 4);
        list->insertPieceRight(&list, randomColor, randomShape);
    }
    list->vanishPiece(&list);
    while (window.isOpen()) {
        // Generate random color and shape for each iteration
        
        window.clear(sf::Color::White); // Clear window with white background
        generatePieces(shapesForm, randomColor, randomShape);
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Handle key press events here
            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::Left) {
                    list->insertPieceLeft(&list, randomColor, randomShape);
                    
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                    
                } else if (event.key.code == sf::Keyboard::Right) {
                    list->insertPieceRight(&list, randomColor, randomShape);
                    
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                }
                list->vanishPiece(&list);
            }
            
        }
        

        drawList(list, shapesForm);
        
        window.display();
    }
}