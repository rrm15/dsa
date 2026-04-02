#include <iostream>
#include <string>
using namespace std;

// strong types for Meters, Seconds, MetersPerSecond
class Seconds;
class MetersPerSecond;

class Meters {
public:
  double value;
  explicit Meters(double v) : value(v) {}
};

class Seconds {
public:
  double value;
  explicit Seconds(double v) : value(v) {}
};

class MetersPerSecond {
public:
  double value;
  explicit MetersPerSecond(double v) : value(v) {}
};

// dividing Meters by Seconds yields MetersPerSecond
MetersPerSecond operator/(Meters m, Seconds s) {
  return MetersPerSecond(m.value / s.value);
}

// print helpers
ostream &operator<<(ostream &os, Meters m) {
  os << m.value << " m";
  return os;
}

ostream &operator<<(ostream &os, Seconds s) {
  os << s.value << " s";
  return os;
}

ostream &operator<<(ostream &os, MetersPerSecond mps) {
  os << mps.value << " m/s";
  return os;
}

// NOTE: We intentionally do NOT define:
//   Meters / Meters       → would give dimensionless, not defined
//   Seconds / Meters      → meaningless
//   Meters + Seconds      → incompatible units
// This ensures type safety by omitting incompatible overloads.

int main() {
  Meters dist(100.0);
  Seconds time(9.58);

  MetersPerSecond speed = dist / time;

  cout << "Distance: " << dist << endl;
  cout << "Time:     " << time << endl;
  cout << "Speed:    " << speed << endl;

  // The following would cause compile errors (type safety):
  // MetersPerSecond bad = time / dist;   // ERROR: no operator/(Seconds, Meters)
  // auto bad2 = dist + time;             // ERROR: no operator+(Meters, Seconds)
  cout << "\n(Incompatible operations like m+s or s/m won't compile)" << endl;

  return 0;
}
