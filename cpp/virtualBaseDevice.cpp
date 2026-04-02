#include <iostream>
#include <string>
using namespace std;

// virtual base class to solve the diamond problem
class Device {
public:
  string brand;
  int year;

  Device(string b, int y) : brand(b), year(y) {
    cout << "  [Device constructed]" << endl;
  }

  void showDevice() {
    cout << "  Brand: " << brand << " | Year: " << year << endl;
  }
};

class Phone : virtual public Device {
public:
  string carrier;

  Phone(string b, int y, string c) : Device(b, y), carrier(c) {
    cout << "  [Phone constructed]" << endl;
  }

  void showPhone() {
    cout << "  Carrier: " << carrier << endl;
  }
};

class Camera : virtual public Device {
public:
  double megapixels;

  Camera(string b, int y, double mp) : Device(b, y), megapixels(mp) {
    cout << "  [Camera constructed]" << endl;
  }

  void showCamera() {
    cout << "  Camera: " << megapixels << " MP" << endl;
  }
};

class SmartPhone : public Phone, public Camera {
public:
  string os;

  SmartPhone(string b, int y, string c, double mp, string o)
      : Device(b, y), Phone(b, y, c), Camera(b, y, mp), os(o) {
    cout << "  [SmartPhone constructed]" << endl;
  }

  void showAll() {
    cout << "--- SmartPhone Details ---" << endl;
    showDevice(); // no ambiguity because of virtual inheritance
    showPhone();
    showCamera();
    cout << "  OS: " << os << endl;
  }
};

int main() {
  cout << "=== Construction order ===" << endl;
  SmartPhone sp("Apple", 2025, "Verizon", 48.0, "iOS 19");

  cout << "\n";
  sp.showAll();

  // without virtual, showDevice() would be ambiguous
  // Device is constructed only ONCE thanks to virtual inheritance
  return 0;
}
