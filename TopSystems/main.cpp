#include <SFML/Graphics.hpp>

#include "source/painter.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes",
                          sf::Style::Default);

  // Rectangle shape(50, 10);
  // shape.SetContour(20, sf::Color::White);
  // shape.SetPosition(35, 50);
  // shape.SetTexture("Texture/1.png");
  // shape.SetPosition(100, 100);

  // Polygon shape(200, 10, sf::Color::Blue);
  // shape.SetContour(20, sf::Color::Black);
  // shape.SetPosition(50, 50);
  // shape.SetTexture("Texture/1.png");

  sf::Texture for_button_circle;
  for_button_circle.loadFromFile("ButtonTexture/button_sozdat-krug.png");
  sf::Sprite button_circle(for_button_circle);
  button_circle.setPosition(600, 100);

  sf::Texture for_button_rectangle;
  for_button_rectangle.loadFromFile("ButtonTexture/button_kvadrat.png");
  sf::Sprite button_rectangle(for_button_rectangle);
  button_rectangle.setPosition(600, 150);

  sf::Texture for_button_clear;
  for_button_clear.loadFromFile("ButtonTexture/button_ochistit-pole.png");
  sf::Sprite button_clear(for_button_clear);
  button_clear.setPosition(600, 500);

  bool update_display = true;

  while (window.isOpen()) {
    window.clear(sf::Color::White);
    button_circle.setColor(sf::Color::White);

    window.draw(button_circle);
    window.draw(button_rectangle);
    window.draw(button_clear);

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (event.mouseButton.x > 600 && event.mouseButton.x < 800 &&
              event.mouseButton.y > 100 && event.mouseButton.y < 150) {
            Circle shape(200, sf::Color::Black);
            shape.SetPosition(10, 10);
            window.draw(shape.Get());
            window.display();
          } else if (event.mouseButton.x > 600 && event.mouseButton.x < 800 &&
                     event.mouseButton.y > 150 && event.mouseButton.y < 200) {
            Rectangle shape(200, 200, sf::Color::Black);
            shape.SetPosition(10, 10);
            window.draw(shape.Get());
            window.display();
          } else if (event.mouseButton.x > 600 && event.mouseButton.x < 800 &&
                     event.mouseButton.y > 500 && event.mouseButton.y < 550) {
            window.display();
          }
        }
      }
    }

    if (update_display == true) {
      window.display();
      update_display = false;
    }
  }
}
