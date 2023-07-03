#include "button.h"

Button::Button(const std::string path, const size_t x, const size_t y) {
  texture_.loadFromFile(path);
  sf::Sprite buffer(texture_);
  button_ = std::move(buffer);
  button_.setPosition(x, y);
}

sf::Sprite& Button::Get() { return button_; }

const sf::Sprite& Button::Get() const { return button_; }