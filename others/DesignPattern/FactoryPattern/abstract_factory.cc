#include <iostream>
#include <string>

class Shape {
 public:
  virtual void draw() = 0;
};

class Rectangle : public Shape {
 public:
  void draw() override { std::cout << "Drawing Rectangle " << std::endl; }
};

class Circle : public Shape {
 public:
  void draw() override { std::cout << "Drawing Circle " << std::endl; }
};

class Color {
 public:
  virtual void fill() = 0;
};

class Red : public Color {
 public:
  void fill() override { std::cout << "Filling Red Color " << std::endl; }
};

class Green : public Color {
 public:
  void fill() override { std::cout << "Filling Green Color " << std::endl; }
};

class AbstractFactory {
 public:
  virtual Shape* GetShape(std::string) { return nullptr; }

  virtual Color* GetColor(std::string) { return nullptr; }
};

class ShapeFactory : public AbstractFactory {
 public:
  Shape* GetShape(std::string str) {
    if (str.find("Rectangle") != std::string::npos) {
      return new Rectangle();
    } else if (str.find("Circle") != std::string::npos) {
      return new Circle();
    } else {
      return nullptr;
    }
  }
};

class ColorFactory : public AbstractFactory {
 public:
  Color* GetColor(std::string str) {
    if (str.find("Red") != std::string::npos) {
      return new Red();
    } else if (str.find("Green") != std::string::npos) {
      return new Green();
    } else {
      return nullptr;
    }
  }
};

class FactoryProducer {
 public:
  static AbstractFactory* GetFactory(std::string str) {
    if (str.find("shape") != std::string::npos) {
      static ShapeFactory* factory = new ShapeFactory();
      return factory;
    } else if (str.find("color") != std::string::npos) {
      static ColorFactory* factory = new ColorFactory();
      return factory;
    } else {
      return nullptr;
    }
  }
};

int main(int argc, char const* argv[]) {
  // get shape factory
  AbstractFactory* shapeFactory = FactoryProducer::GetFactory("shape");

  // get an object of Shape Circle
  Shape* shape1 = shapeFactory->GetShape("Circle");

  // call draw method of Shape Circle
  shape1->draw();

  // get an object of Shape Rectangle
  Shape* shape2 = shapeFactory->GetShape("Rectangle");

  // call draw method of Shape Rectangle
  shape2->draw();

  // get color factory
  AbstractFactory* colorFactory = FactoryProducer::GetFactory("color");

  // get an object of Color Red
  Color* color1 = colorFactory->GetColor("Red");

  // call fill method of Red
  color1->fill();

  // get an object of Color Green
  Color* color2 = colorFactory->GetColor("Green");

  // call fill method of Green
  color2->fill();

  return 0;
}