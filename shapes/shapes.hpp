#pragma once
#include <SFML/Graphics.hpp>

class ShapesForm {
    private:
        sf::CircleShape m_circle;
        sf::RectangleShape m_square;
        sf::ConvexShape m_triangle; 
        sf::ConvexShape m_diamond; 
    public:
        ShapesForm();
        void setCircle(float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
        void setSquare(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
        void setTriangle(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
        void setDiamond(float size, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness);
        sf::CircleShape& getCircle();
        sf::RectangleShape& getSquare();
        sf::ConvexShape& getTriangle();
        sf::ConvexShape& getDiamond(); 
};

