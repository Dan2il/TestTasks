#include "painter.h"

Circle::Circle(const double radius) : circle_(radius){};

Circle::Circle(const double radius, const sf::Color& color_fill)
    : circle_(radius) {
  SetColorFill(color_fill);
}

sf::CircleShape& Circle::Get() { return circle_; }

const sf::CircleShape& Circle::Get() const { return circle_; }

void Circle::SetColorFill(const sf::Color& color) {
  circle_.setFillColor(color);
}

void Circle::SetContour(const size_t size_contour, const sf::Color& color) {
  circle_.setOutlineThickness(size_contour);
  circle_.setOutlineColor(color);
}

void Circle::SetPosition(const int x, const int y) {
  circle_.setPosition(x, y);
}

void Circle::SetTexture(const std::string& path) {
  texture_.loadFromFile(path);
  circle_.setTexture(&texture_);
}

Rectangle::Rectangle(const double x, const double y)
    : rectangle_(sf::Vector2f(x, y)) {}

Rectangle::Rectangle(const double x, const double y,
                     const sf::Color& color_fill)
    : rectangle_(sf::Vector2f(x, y)) {
  SetColorFill(color_fill);
}

sf::RectangleShape& Rectangle::Get() { return rectangle_; }

const sf::RectangleShape& Rectangle::Get() const { return rectangle_; };

void Rectangle::SetColorFill(const sf::Color& color) {
  rectangle_.setFillColor(color);
}

void Rectangle::SetContour(const size_t size_contour, const sf::Color& color) {
  rectangle_.setOutlineThickness(size_contour);
  rectangle_.setOutlineColor(color);
}

void Rectangle::SetPosition(const int x, const int y) {
  rectangle_.setPosition(x, y);
}

void Rectangle::SetTexture(const std::string& path) {
  texture_.loadFromFile(path);
  rectangle_.setTexture(&texture_);
}

Polygon::Polygon(const double radius, const size_t num_corners)
    : Circle(radius) {
  sf::CircleShape buffer(radius, num_corners);
  circle_ = std::move(buffer);
}
Polygon::Polygon(const double radius, const size_t num_corners,
                 const sf::Color& color_fill)
    : Polygon(radius, num_corners) {
  SetColorFill(color_fill);
}