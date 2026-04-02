#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
  string brand;
  int year;

public:
  Device(string b, int y) : brand(b), year(y) {}

  void showDevice() {
    cout << "Brand: " << brand << " | Year: " << year << endl;
  }
};

class Mobile : public Device {
protected:
  string os;

public:
  Mobile(string b, int y, string o) : Device(b, y), os(o) {}

  void showMobile() {
    showDevice();
    cout << "OS:    " << os << endl;
  }
};

class Smartphone : public Mobile {
  double screenSize;

public:
  Smartphone(string b, int y, string o, double s)
      : Mobile(b, y, o), screenSize(s) {}

  void showSmartphone() {
    showMobile();
    cout << "Screen: " << screenSize << " inches" << endl;
  }
};

int main() {
  cout << "--- Device ---" << endl;
  Device d("Sony", 2023);
  d.showDevice();

  cout << "\n--- Mobile ---" << endl;
  Mobile m("Nokia", 2024, "Android");
  m.showMobile();

  cout << "\n--- Smartphone ---" << endl;
  Smartphone s("Samsung", 2025, "Android 15", 6.7);
  s.showSmartphone();

  // derived class accessing base class members
  cout << "\n--- Derived accessing base members ---" << endl;
  cout << "Smartphone brand (from Device): ";
  s.showDevice();

  return 0;
}
