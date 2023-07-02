#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

class Shape {
 public:
  virtual void SetColorFill(const sf::Color& color) = 0;
  virtual void SetContour(const size_t size_contour,
                          const sf::Color& color) = 0;
  virtual void SetTexture(const std::string& path) = 0;
  virtual void SetPosition(const int x, const int y) = 0;

 protected:
  sf::Texture texture_;
};

class Circle : public Shape {
 public:
  Circle(const double radius);
  Circle(const double radius, const sf::Color& color_fill);

  sf::CircleShape& Get();
  const sf::CircleShape& Get() const;

  void SetColorFill(const sf::Color& color);
  void SetContour(const size_t size_contour, const sf::Color& color);
  void SetTexture(const std::string& path);

  void SetPosition(const int x, const int y);

  //   void Resize();

 protected:
  sf::CircleShape circle;
};

class Polygon : public Circle {
 public:
  Polygon(const double radius, const size_t num_corners);
  Polygon(const double radius, const size_t num_corners,
          const sf::Color& color_fill);
};

class Rectangle : public Shape {
 public:
  Rectangle(const double x, const double y);
  Rectangle(const double x, const double y, const sf::Color& color_fill);

  sf::RectangleShape& Get();
  const sf::RectangleShape& Get() const;

  void SetColorFill(const sf::Color& color);
  void SetContour(const size_t size_contour, const sf::Color& color);
  void SetTexture(const std::string& path);

  void SetPosition(const int x, const int y);

  //   void Resize();

 private:
  sf::RectangleShape rectangle;
};