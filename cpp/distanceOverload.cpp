#include <cmath>
#include <iostream>
using namespace std;

class Point {
public:
  double x, y;

  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
};

// overload 1: between two raw coordinates
double distance(double x1, double y1, double x2, double y2) {
  cout << "  [overload: two coordinate pairs]" << endl;
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// overload 2: between two Point objects
double distance(Point a, Point b) {
  cout << "  [overload: two Points]" << endl;
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// overload 3: between a Point and the origin (single parameter)
double distance(Point p) {
  cout << "  [overload: Point to origin]" << endl;
  return sqrt(p.x * p.x + p.y * p.y);
}

int main() {
  cout << "=== Distance Overloads ===" << endl;

  cout << "d(0,0 -> 3,4) = " << distance(0.0, 0.0, 3.0, 4.0) << endl;

  Point p1(1, 2), p2(4, 6);
  cout << "d(p1, p2)     = " << distance(p1, p2) << endl;

  Point p3(3, 4);
  cout << "d(p3, origin) = " << distance(p3) << endl;

  return 0;
}
