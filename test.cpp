#include <SFML/Graphics.hpp>
#include <iostream>
#include "shapes/shapes.hpp"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Example");

    // Create an instance of the Shapes class
    ShapesForm shapes;

    // Set properties for each shape
    shapes.setCircle(60.f, sf::Color::Red, sf::Color::Black, 2.f);
    shapes.setSquare(100.f, sf::Color::Green, sf::Color::Black, 2.f);
    shapes.setTriangle(100.f, sf::Color::Blue, sf::Color::Black, 2.f);
    shapes.setDiamond(90.f, sf::Color::Yellow, sf::Color::Black, 2.f);

    // Set positions for each shape
    shapes.getCircle().setPosition(100.f, 100.f);
    shapes.getSquare().setPosition(300.f, 100.f);
    shapes.getTriangle().setPosition(500.f, 100.f);
    shapes.getDiamond().setPosition(700.f, 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Draw all shapes
        window.draw(shapes.getCircle());
        window.draw(shapes.getSquare());
        window.draw(shapes.getTriangle());
        window.draw(shapes.getDiamond());

        window.display();
    }

    return 0;
}
