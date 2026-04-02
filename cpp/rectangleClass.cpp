#include <iostream>
using namespace std;

class Rectangle {
  double width;
  double height;

public:
  Rectangle() : width(1), height(1) {}

  void setWidth(double w) {
    if (w <= 0) {
      cout << "  [Warning] Width must be positive. Clamping to 1." << endl;
      width = 1;
    } else {
      width = w;
    }
  }

  void setHeight(double h) {
    if (h <= 0) {
      cout << "  [Warning] Height must be positive. Clamping to 1." << endl;
      height = 1;
    } else {
      height = h;
    }
  }

  double getWidth() { return width; }
  double getHeight() { return height; }
  double area() { return width * height; }
  double perimeter() { return 2 * (width + height); }

  void display() {
    cout << "Rectangle [" << width << " x " << height << "]"
         << " | Area: " << area() << " | Perimeter: " << perimeter() << endl;
  }
};

int main() {
  Rectangle r;
  cout << "Default rectangle:" << endl;
  r.display();

  cout << "\nSetting valid dimensions (5 x 3):" << endl;
  r.setWidth(5);
  r.setHeight(3);
  r.display();

  cout << "\nAttempting to set negative width (-2):" << endl;
  r.setWidth(-2);
  r.display();

  cout << "\nAttempting to set zero height (0):" << endl;
  r.setHeight(0);
  r.display();

  return 0;
}
