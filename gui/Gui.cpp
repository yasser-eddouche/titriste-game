#include "Gui.hpp"

Gui::Gui(LstPieces* list)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    shapesForm = ShapesForm();

    randomColor = static_cast<Color>(rand() % 4);
    randomShape = static_cast<Shapes>(rand() % 4);
    // LstPieces *list = nullptr; // Allocate memory for the first node
    
}
Gui::~Gui()
{
}
void Gui::drawList(LstPieces* list, ShapesForm& shapesForm, sf::RenderWindow& window)
{   
    LstPieces *current = list;
    sf::Color fillColor;
    sf::Vector2f position(100.f, 550.f); // Starting position for the shapes
    if (list != NULL) {
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
            position.x += 95.f; // Adjust as needed
            position.y += 0.f;   // Adjust as needed

            // Move to the next node in the list
            current = current->next;
        } while (current != NULL);
    }
}
void Gui::generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape, sf::RenderWindow& window)
{
    sf::Color fillColor;
    sf::Vector2f position(100.f, 200.f); // Starting position for the shapes

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

void Gui::gamePage(LstPieces* list, sf::RenderWindow& window){
    FILE* ScoreFile;
    int score = 0;
    sf::Font font;
    
    int numPieces = rand() % 2 + 4;    // Generates either 4 or 5
    list->initialInsert(&list, numPieces); // Insert the initial pieces to the list
    gameStatus = GameStatus::playing;
    sf::RectangleShape exit(sf::Vector2f(80, 60));
    exit.setFillColor(sf::Color(0, 0, 0, 128)); // semi-transparent green
    exit.setPosition(1070, 60);
    sf::Text exitText("exit", font, 30);
    exitText.setPosition(1080, 62);
    ScoreFile = fopen("score.txt", "a+");
    while (window.isOpen()) {
       
        
        window.clear(); // Clear window with white background
        if (gameStatus == GameStatus::playing) {
        generatePieces(shapesForm, randomColor, randomShape,window);
       
        sf::Event event;
        while (window.pollEvent(event)) {
            
            // Handle key press events here
            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::Left) {
                    list->insertPieceLeft(&list,randomColor, randomShape);
                    
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                    
                } else if (event.key.code == sf::Keyboard::Right) {
                    list->insertPieceRight(randomColor, randomShape);
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                }
                
                if (event.type == sf::Event::Closed)
                window.close();
                if (list==nullptr)
                {
                    gameStatus = GameStatus::win;
                }
                
               if (list->countPieces() > 15) {
                    gameStatus = GameStatus::lose;
                }
                // Call vanishPiece after each insertion
                list->vanishPiece(&list,score);
                
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (exit.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
                        // Quit the game
                        window.close();
                        // break;
                    }
                }
            }
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (exitText.getGlobalBounds().contains(window.mapPixelToCoords(mouse))) {
            exitText.setFillColor(sf::Color::Red); // change color to red
            } else {
                exitText.setFillColor(sf::Color::White); // change color back to white
            }
            
        }
         if (!font.loadFromFile("Raillinc.otf")) {
            std::cerr << "Error loading font" << std::endl;
        }
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString(std::to_string(score));
        scoreText.setCharacterSize(50);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(950.f, 50.f);
        window.draw(scoreText);
        window.draw(exit);
        
        window.draw(exitText);
        drawList(list, shapesForm,window);
        }else if (gameStatus == GameStatus::lose) {
        if(score>0){
        fprintf(ScoreFile, "\n%d", score);
        fclose(ScoreFile);}
        gameStatus = GameStatus::lose;
        
        loseGamePage(window,score);
        break;
        }else if (gameStatus == GameStatus::win) {
            fprintf(ScoreFile, "\n%d", score);
            fclose(ScoreFile);
            winGamePage(window);
            break;
        }
        
        window.display();
    }
}

void Gui::loseGamePage(sf::RenderWindow& window,int score){
    sf::Font font;
    // font.loadFromFile("font/arial.ttf");
    if (!font.loadFromFile("Raillinc.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: "+std::to_string(score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(550.f, 100.f);
    text.setFont(font);
    text.setString("Game Over!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(500.f, 300.f);

   
    window.draw(text);
    window.draw(scoreText);
    window.display();
    sf::sleep(sf::seconds(2));
}

void Gui::winGamePage(sf::RenderWindow& window){
    sf::Font font;
    // font.loadFromFile("font/arial.ttf");
    if (!font.loadFromFile("Raillinc.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Winner!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(500.f, 300.f);

   
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(2));
}