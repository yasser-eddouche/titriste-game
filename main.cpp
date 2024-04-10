#include <SFML/Graphics.hpp>
#include "ParticalSystem.cpp"
#include "shapes/shapes.hpp"
// #include "game/game.hpp"
#include "gui/Gui.hpp"
int main()
{   
    LstPieces *list = NULL;
    int score ;
    int maxScore = 0;
    ShapesForm shapesForm;
    // create the window
    sf::RenderWindow window(sf::VideoMode(1600, 650), "Titriste");

    // create the particle system
    ParticleSystem particles(1000);

    // create a clock to track the elapsed time
    sf::Clock clock;

    // create a font
    sf::Font font;
    if (!font.loadFromFile("Raillinc.otf")) {
        // handle error
    }

    // create a title
    sf::Text title("Titriste", font, 80);
    title.setPosition(650, 20);

    // create two buttons
    sf::RectangleShape button1(sf::Vector2f(170, 70));
    button1.setFillColor(sf::Color(0, 0, 0, 0)); // semi-transparent green
    button1.setPosition(730, 280);

    sf::Text button1Text("Start", font, 50);
    button1Text.setPosition(740, 270);

    sf::RectangleShape button2(sf::Vector2f(170, 70));
    button2.setFillColor(sf::Color(0, 0, 0,0)); // semi-transparent red
    button2.setPosition(730, 370);

    sf::Text button2Text("Quit", font, 50);
    button2Text.setPosition(740, 370);

    shapesForm.setCircle(60.f, sf::Color::Red, sf::Color::Black, 2.f);
    shapesForm.getCircle().setPosition(350,200);

    shapesForm.setSquare(100.f, sf::Color::Yellow, sf::Color::Black, 2.f);
    shapesForm.getSquare().setPosition(1250,250);

    shapesForm.setTriangle(100.f, sf::Color::Blue, sf::Color::Black, 2.f);
    shapesForm.getTriangle().setPosition(200,500);

    shapesForm.setDiamond(80.f, sf::Color::Green, sf::Color::Black, 2.f);
    shapesForm.getDiamond().setPosition(1300,400);
    
    
    

    while (window.isOpen())
    {
        FILE *scoreFile = fopen("score.txt", "r");
            if (scoreFile == NULL) {
            printf("Could not open file scores.txt\n");
            } else {
                while (fscanf(scoreFile, "%d", &score) != EOF) {
                    if (score > maxScore) {
                        maxScore = score;
                    }
                }
                cout << "Score: " << maxScore << endl;
            }
        fclose(scoreFile);
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if(event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (button1Text.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
                        Gui game(list);
                        game.gamePage(list, window);
                    }
                    if (button2Text.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
                        // Quit the game
                        window.close();
                    }
                }
            }
            
            // window.draw(scoreText);
            // cout << "Score: " << maxScore << endl;
        
        }

        // make the particle system emitter follow the mouse
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));

        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (button1Text.getGlobalBounds().contains(window.mapPixelToCoords(mouse))) {
            button1Text.setFillColor(sf::Color::Green); // change color to red
        } else {
            button1Text.setFillColor(sf::Color::White); // change color back to white
        }

        if (button2Text.getGlobalBounds().contains(window.mapPixelToCoords(mouse))) {
            button2Text.setFillColor(sf::Color::Red); // change color to red
        } else {
            button2Text.setFillColor(sf::Color::White); // change color back to white
        }
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString("Best Score: "+std::to_string(maxScore));
        scoreText.setCharacterSize(30);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(700.f, 580.f);
        // draw it
        window.clear();
        window.draw(shapesForm.getCircle());
        window.draw(shapesForm.getSquare());
        window.draw(shapesForm.getTriangle());
        window.draw(shapesForm.getDiamond());
        window.draw(particles);
        window.draw(title);
        window.draw(button1);
        window.draw(button1Text);
        window.draw(button2);
        window.draw(button2Text);
        window.draw(scoreText);
        window.display();
    }
    
    return 0;
}