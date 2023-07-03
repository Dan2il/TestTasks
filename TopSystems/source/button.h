#include <SFML/Graphics.hpp>
#include <string>

class Button {
 public:
  Button(const std::string path, const size_t x, const size_t y);

  sf::Sprite& Get();
  const sf::Sprite& Get() const;

 private:
  sf::Sprite button_;
  sf::Texture texture_;
};