#pragma once
#include <SFML/Graphics.hpp>

class ShapesForm {
public:
    ShapesForm();
    void setCircle(float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
    void setSquare(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
    void setTriangle(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
    void setDiamond(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
    sf::CircleShape& getCircle();
    sf::RectangleShape& getSquare();
    sf::ConvexShape& getTriangle(); // Changed return type to sf::ConvexShape
    sf::ConvexShape& getDiamond(); // Changed return type to sf::ConvexShape

private:
    sf::CircleShape m_circle;
    sf::RectangleShape m_square;
    sf::ConvexShape m_triangle; // Changed data type to sf::ConvexShape
    sf::ConvexShape m_diamond; // Changed data type to sf::ConvexShape
};

