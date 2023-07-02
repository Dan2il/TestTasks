#include "painter.h"

Circle::Circle(const double radius) : circle(radius){};

Circle::Circle(const double radius, const sf::Color& color_fill)
    : circle(radius) {
  SetColorFill(color_fill);
}

sf::CircleShape& Circle::Get() { return circle; }

const sf::CircleShape& Circle::Get() const { return circle; }

void Circle::SetColorFill(const sf::Color& color) {
  circle.setFillColor(color);
}

void Circle::SetContour(const size_t size_contour, const sf::Color& color) {
  circle.setOutlineThickness(size_contour);
  circle.setOutlineColor(color);
}

void Circle::SetPosition(const int x, const int y) { circle.setPosition(x, y); }

void Circle::SetTexture(const std::string& path) {
  texture_.loadFromFile(path);
  circle.setTexture(&texture_);
}

Rectangle::Rectangle(const double x, const double y)
    : rectangle(sf::Vector2f(x, y)) {}

Rectangle::Rectangle(const double x, const double y,
                     const sf::Color& color_fill)
    : rectangle(sf::Vector2f(x, y)) {
  SetColorFill(color_fill);
}

sf::RectangleShape& Rectangle::Get() { return rectangle; }

const sf::RectangleShape& Rectangle::Get() const { return rectangle; };

void Rectangle::SetColorFill(const sf::Color& color) {
  rectangle.setFillColor(color);
}

void Rectangle::SetContour(const size_t size_contour, const sf::Color& color) {
  rectangle.setOutlineThickness(size_contour);
  rectangle.setOutlineColor(color);
}

void Rectangle::SetPosition(const int x, const int y) {
  rectangle.setPosition(x, y);
}

void Rectangle::SetTexture(const std::string& path) {
  texture_.loadFromFile(path);
  rectangle.setTexture(&texture_);
}

Polygon::Polygon(const double radius, const size_t num_corners)
    : Circle(radius) {
  sf::CircleShape buffer(radius, num_corners);
  circle = std::move(buffer);
}
Polygon::Polygon(const double radius, const size_t num_corners,
                 const sf::Color& color_fill)
    : Polygon(radius, num_corners) {
  SetColorFill(color_fill);
}