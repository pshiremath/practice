#include <stdio.h>
#include <string>

class Shape {
 public:
  virtual void draw() = 0;
};

class Rectangle : public Shape {
 public:
  void draw() override { printf("Drawing Rectangle \n"); }
};

class Square : public Shape {
 public:
  void draw() override { printf("Drawing Square \n"); }
};

class Circle : public Shape {
 public:
  void draw() override { printf("Drawing Circle \n"); }
};

class ShapeFactory {
 public:
  Shape* GetShape(std::string str) {
    if (str.find("Rectangle") != std::string::npos) {
      return new Rectangle();
    } else if (str.find("Square") != std::string::npos) {
      return new Square();
    } else if (str.find("Circle") != std::string::npos) {
      return new Circle();
    } else {
      return nullptr;
    }
  }
};

int main(int argc, char const* argv[]) {
  ShapeFactory shapeFactory;
  Shape* shape1 = shapeFactory.GetShape("Rectangle");
  shape1->draw();
  Shape* shape2 = shapeFactory.GetShape("Square");
  shape2->draw();
  Shape* shape3 = shapeFactory.GetShape("Circle");
  shape3->draw();

  return 0;
}