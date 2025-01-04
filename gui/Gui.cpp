#include "Gui.hpp"

Gui::Gui(LstPieces* list)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    shapesForm = ShapesForm();

    randomColor = static_cast<Color>(rand() % 4);
    randomShape = static_cast<Shapes>(rand() % 4);
    
    
}
Gui::~Gui()
{
}
void Gui::drawList(LstPieces* list, ShapesForm& shapesForm, sf::RenderWindow& window)
{   
    LstPieces *current = list;
    sf::Color fillColor;
    sf::Vector2f position(100.f, 650.f);
    if (list != nullptr) {
        do {
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
                    fillColor = sf::Color::White;
                    break;
            }
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

            position.x += 95.f;
            position.y += 0.f;

            current = current->next;
        } while (current != list);
    }
}
void Gui::generatePieces(ShapesForm& shapesForm,Color randomColor,Shapes randomShape, sf::RenderWindow& window)
{   
    randomColor = static_cast<Color>(rand() % 4);
    randomShape = static_cast<Shapes>(rand() % 4);

    nextPiecesQueue.push(std::make_pair(randomColor, randomShape));
}

void Gui::printAllPieces() {
    std::queue<std::pair<Color, Shapes>> copyQueue = nextPiecesQueue;

    while (!copyQueue.empty()) {
        std::pair<Color, Shapes> piece = copyQueue.front();
        copyQueue.pop();

        std::cout << "Color: " << piece.first << ", Shape: " << piece.second << std::endl;
    }
}
void Gui::drawNextPieces(ShapesForm& shapesForm, sf::RenderWindow& window) {
    sf::Vector2f position(100.f, 100.f);

    std::queue<std::pair<Color, Shapes>> copyQueue = nextPiecesQueue;

    while (!copyQueue.empty()) {
        std::pair<Color, Shapes> nextPiece = copyQueue.front();
        copyQueue.pop();

        sf::Color fillColor;

        switch (nextPiece.first) {
            case 0:
                fillColor = sf::Color::Red;
                break;
            case 1:
                fillColor = sf::Color::Green;
                break;
            case 2:
                fillColor = sf::Color::Blue;
                break;
            case 3:
                fillColor = sf::Color::Yellow;
                break;
            default:
                break;
        }

        switch (nextPiece.second) {
            case 0:
                shapesForm.setCircle(40.f, fillColor, sf::Color::Black, 2.f);
                shapesForm.getCircle().setPosition(position);
                window.draw(shapesForm.getCircle());
                break;
            case 1:
                shapesForm.setSquare(70.f, fillColor, sf::Color::Black, 2.f);
                shapesForm.getSquare().setPosition(position);
                window.draw(shapesForm.getSquare());
                break;
            case 2:
                shapesForm.setTriangle(70.f, fillColor, sf::Color::Black, 2.f);
                shapesForm.getTriangle().setPosition(position);
                window.draw(shapesForm.getTriangle());
                break;
            case 3:
                shapesForm.setDiamond(60.f, fillColor, sf::Color::Black, 2.f);
                shapesForm.getDiamond().setPosition(position);
                window.draw(shapesForm.getDiamond());
                break;
        }

        position.x += 100.f;
    }
}


void Gui::gamePage(LstPieces* list, sf::RenderWindow& window){
    FILE* ScoreFile;
    int score = 0;
    sf::Font font;
    LstShapes *lstCircle = nullptr;
    LstShapes *lstSquare = nullptr;
    LstShapes *lstTriangle = nullptr;
    LstShapes *lstDiamond = nullptr;
    LstColors *lstRed = nullptr;
    LstColors *lstGreen = nullptr;
    LstColors *lstBlue = nullptr;
    LstColors *lstYellow = nullptr;

    sf::Clock clock; // start the clock
    float timeLimit = 30.0f; // set the time limit in seconds
    // sf::Font font;
    if (!font.loadFromFile("Raillinc.otf")) {
        // handle error
    }
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(50); // in pixels
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(1000.f, 50.f); // adjust position as needed

    int numPieces = rand() % 2 + 4;
    for (int i = 0; i < numPieces; ++i) {
         randomColor = static_cast<Color>(rand() % 4);
         randomShape = static_cast<Shapes>(rand() % 4);
        list->insertPieceRight(&list, randomColor, randomShape);
    }
    gameStatus = GameStatus::playing;
    sf::RectangleShape exit(sf::Vector2f(80, 60));
    exit.setFillColor(sf::Color(0, 0, 0, 0));
    exit.setPosition(1370, 63);
    sf::Text exitText("exit", font, 30);
    exitText.setPosition(1380, 67);
    ScoreFile = fopen("score.txt", "a+");
    for (int i = 0; i < 5; i++)
    {
        generatePieces(shapesForm, randomColor, randomShape,window);
    }
    while (window.isOpen()) {
        window.clear();
        if (gameStatus == GameStatus::playing) {
            float elapsedTime = clock.getElapsedTime().asSeconds(); // get elapsed time
        float timeRemaining = timeLimit - elapsedTime;
        timerText.setString(std::to_string(static_cast<int>(timeRemaining)));
        if (timeRemaining <= 0) {
            gameStatus = GameStatus::lose; // end the game if time limit is reached
            loseGamePage(window,score);
            break;
        }
        drawNextPieces(shapesForm, window);
        sf::Event event;
        while (window.pollEvent(event)) {
             std::pair<Color, Shapes> piece = nextPiecesQueue.front();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    nextPiecesQueue.pop();
                    list->insertPieceLeft(&list,piece.first, piece.second);
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                    generatePieces(shapesForm, randomColor, randomShape,window);
                } else if (event.key.code == sf::Keyboard::Right) {
                    nextPiecesQueue.pop();
                    list->insertPieceRight(&list,piece.first, piece.second);
                     randomColor = static_cast<Color>(rand() % 4);
                     randomShape = static_cast<Shapes>(rand() % 4);
                     generatePieces(shapesForm, randomColor, randomShape,window);
                }else if (event.key.code == sf::Keyboard::S)
                {   lstCircle->findSameShape(&lstCircle,&list,circle);
                    lstSquare->findSameShape(&lstSquare,&list,square);
                    lstTriangle->findSameShape(&lstTriangle,&list,triangle);
                    lstDiamond->findSameShape(&lstDiamond,&list,diamond);
                    
                    lstCircle->shiftLeft(&lstCircle);
                    lstSquare->shiftLeft(&lstSquare);
                    lstTriangle->shiftLeft(&lstTriangle);
                    lstDiamond->shiftLeft(&lstDiamond);

                    lstCircle->adjustPositions(&lstCircle,&list,circle);
                    lstSquare->adjustPositions(&lstSquare,&list,square);
                    lstTriangle->adjustPositions(&lstTriangle,&list,triangle);
                    lstDiamond->adjustPositions(&lstDiamond,&list,diamond);
                }else if (event.key.code == sf::Keyboard::C)
                {
                    lstRed->findSameColor(&lstRed,&list,red);
                    lstGreen->findSameColor(&lstGreen,&list,green);
                    lstBlue->findSameColor(&lstBlue,&list,blue);
                    lstYellow->findSameColor(&lstYellow,&list,yellow);
                    
                    lstRed->shiftLeft(&lstRed);
                    lstGreen->shiftLeft(&lstGreen);
                    lstBlue->shiftLeft(&lstBlue);
                    lstYellow->shiftLeft(&lstYellow);

                    lstRed->adjustPositions(&lstRed,&list,red);
                    lstGreen->adjustPositions(&lstGreen,&list,green);
                    lstBlue->adjustPositions(&lstBlue,&list,blue);
                    lstYellow->adjustPositions(&lstYellow,&list,yellow);
                }
                if (event.type == sf::Event::Closed)
                window.close();
               if (list->countPieces() > 15) {
                    gameStatus = GameStatus::lose;
                }
                list->vanishPiece(&list,score);
                list->printList(list);
                if (list != nullptr)
                {
                cout<<list->countPieces()<<endl;
                }else{
                    cout<<"List is empty"<<endl;
                    gameStatus = GameStatus::win;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (exit.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))) {
                        return;
                    }
                }
            }
            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (exitText.getGlobalBounds().contains(window.mapPixelToCoords(mouse))) {
            exitText.setFillColor(sf::Color::Red);
            } else {
                exitText.setFillColor(sf::Color::White);
            }
            
        }
        lstCircle->clearList(&lstCircle);
        lstSquare->clearList(&lstSquare);
        lstTriangle->clearList(&lstTriangle);
        lstDiamond->clearList(&lstDiamond);
        lstRed->clearList(&lstRed);
        lstGreen->clearList(&lstGreen);
        lstBlue->clearList(&lstBlue);
        lstYellow->clearList(&lstYellow);
        if (!font.loadFromFile("Raillinc.otf")) {
            std::cerr << "Error loading font" << std::endl;
        }
        sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setString(std::to_string(score));
        scoreText.setCharacterSize(50);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(1170.f, 50.f);
        sf::Texture texture;
        if (!texture.loadFromFile("./images/keys.png")) {
            std::cerr << "Error loading image" << std::endl;
        }

        sf::Sprite sprite;
        sprite.setTexture(texture);

        // Position the sprite
        sprite.setPosition(sf::Vector2f(1100.f, 170.f));

        // Scale the sprite
        float scaleFactorX = 0.3f;  // replace with your desired scale factor
        float scaleFactorY = 0.3f;  // replace with your desired scale factor
        sprite.setScale(scaleFactorX, scaleFactorY);

        // Draw the sprite to the window
        window.draw(timerText); // draw the timer text
        window.draw(sprite);
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
            winGamePage(window,score);
            break;
        }
        window.display();
    }
    delete list;
    delete lstCircle;
    delete lstSquare;
    delete lstTriangle;
    delete lstDiamond;
    delete lstRed;
    delete lstGreen;
    delete lstBlue;
    delete lstYellow;
}

void Gui::loseGamePage(sf::RenderWindow& window,int score){
    sf::Font font;
    if (!font.loadFromFile("Raillinc.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: "+std::to_string(score));
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(710.f, 100.f);
    text.setFont(font);
    text.setString("Game Over!");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(600.f, 300.f);

   
    window.draw(text);
    window.draw(scoreText);
    window.display();
    sf::sleep(sf::seconds(2));
}

void Gui::winGamePage(sf::RenderWindow& window,int score){
    sf::Font font;
    if (!font.loadFromFile("Raillinc.otf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    sf::Text text;
    // sf::Text scoreText;
    // scoreText.setFont(font);
    // scoreText.setString("Score: "+std::to_string(score));
    // scoreText.setCharacterSize(50);
    // scoreText.setFillColor(sf::Color::White);
    // scoreText.setPosition(710.f, 100.f);
    text.setFont(font);
    text.setString("Winner!");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);
    text.setPosition(600.f, 300.f);

   
    window.draw(text);
    // window.draw(scoreText);
    window.display();
    sf::sleep(sf::seconds(2));
}
