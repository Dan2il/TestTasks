#include <SFML/Graphics.hpp>

#include "source/button.h"
#include "source/painter.h"

void MenuProcessing(sf::RenderWindow& window, sf::Event& event);

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes", sf::Style::Close);

  Button button_circle("ButtonTexture/button_sozdat-krug.png", 600, 100);
  Button button_square("ButtonTexture/button_kvadrat.png", 600, 150);
  Button button_rectangle("ButtonTexture/button_pryamougolnik.png", 600, 200);
  Button button_triangle("ButtonTexture/button_treugolnik.png", 600, 250);
  Button button_polygon("ButtonTexture/button_mnogougolnik.png", 600, 300);
  Button button_clear("ButtonTexture/button_ochistit-pole.png", 600, 500);

  bool update_display = true;

  while (window.isOpen()) {
    window.clear(sf::Color::White);

    window.draw(button_circle.Get());
    window.draw(button_square.Get());
    window.draw(button_rectangle.Get());
    window.draw(button_triangle.Get());
    window.draw(button_polygon.Get());
    window.draw(button_clear.Get());

    sf::Event event;
    while (window.pollEvent(event)) {
      MenuProcessing(window, event);
    }

    if (update_display == true) {
      window.display();
      update_display = false;
    }
  }
}

void MenuProcessing(sf::RenderWindow& window, sf::Event& event) {
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
                 event.mouseButton.y > 200 && event.mouseButton.y < 250) {
        Rectangle shape(200, 400, sf::Color::Black);
        shape.SetPosition(10, 10);
        window.draw(shape.Get());
        window.display();
      } else if (event.mouseButton.x > 600 && event.mouseButton.x < 800 &&
                 event.mouseButton.y > 250 && event.mouseButton.y < 300) {
        Polygon shape(200, 3, sf::Color::Black);
        shape.SetPosition(10, 10);
        window.draw(shape.Get());
        window.display();
      } else if (event.mouseButton.x > 600 && event.mouseButton.x < 800 &&
                 event.mouseButton.y > 300 && event.mouseButton.y < 350) {
        Polygon shape(200, 7, sf::Color::Black);
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