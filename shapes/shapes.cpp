#include "shapes.hpp"
#include <cmath>
ShapesForm::ShapesForm() {}

void ShapesForm::setCircle(float radius, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness) {
    m_circle.setRadius(radius);
    m_circle.setFillColor(fillColor);
    m_circle.setOutlineColor(outlineColor);
    m_circle.setOutlineThickness(outlineThickness);
    // Center the m_circle
    m_circle.setOrigin(radius, radius);
}

void ShapesForm::setSquare(float sideLength, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness) {
    m_square.setSize(sf::Vector2f(sideLength, sideLength));
    m_square.setFillColor(fillColor);
    m_square.setOutlineColor(outlineColor);
    m_square.setOutlineThickness(outlineThickness);
    // Center the m_square
    m_square.setOrigin(sideLength / 2.f, sideLength / 2.f);
}

void ShapesForm::setTriangle(float sideLength, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness) {
    m_triangle.setPointCount(3);
    float height = sqrt(3.f) / 2.f * sideLength; // Calculate height of equilateral m_triangle
    m_triangle.setPoint(0, sf::Vector2f(0.f, -height / 2.f));
    m_triangle.setPoint(1, sf::Vector2f(-sideLength / 2.f, height / 2.f));
    m_triangle.setPoint(2, sf::Vector2f(sideLength / 2.f, height / 2.f));
    m_triangle.setFillColor(fillColor);
    m_triangle.setOutlineColor(outlineColor);
    m_triangle.setOutlineThickness(outlineThickness);
}

void ShapesForm::setDiamond(float sideLength, const sf::Color& fillColor, const sf::Color& outlineColor, float outlineThickness) {
    m_diamond.setPointCount(4);
    float halfDiagonal = sideLength * sqrt(2.f) / 2.f; // Calculate half of the diagonal length
    m_diamond.setPoint(0, sf::Vector2f(0.f, -halfDiagonal));
    m_diamond.setPoint(1, sf::Vector2f(-sideLength / 2.f, 0.f));
    m_diamond.setPoint(2, sf::Vector2f(0.f, halfDiagonal));
    m_diamond.setPoint(3, sf::Vector2f(sideLength / 2.f, 0.f));
    m_diamond.setFillColor(fillColor);
    m_diamond.setOutlineColor(outlineColor);
    m_diamond.setOutlineThickness(outlineThickness);
}

sf::CircleShape& ShapesForm::getCircle() {
    return m_circle;
}

sf::RectangleShape& ShapesForm::getSquare() {
    return m_square;
}

sf::ConvexShape& ShapesForm::getTriangle() {
    return m_triangle;
}

sf::ConvexShape& ShapesForm::getDiamond() {
    return m_diamond;
}
