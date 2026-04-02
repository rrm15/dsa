#include <iostream>
using namespace std;

class Counter {
  int value;

public:
  Counter(int v = 0) : value(v) {}

  // prefix ++c: increment then return reference
  Counter &operator++() {
    ++value;
    return *this;
  }

  // postfix c++: save old, increment, return old by value
  Counter operator++(int) {
    Counter old = *this;
    ++value;
    return old;
  }

  int getValue() const { return value; }
};

int main() {
  Counter c(5);
  cout << "Initial: c = " << c.getValue() << endl;

  // prefix: increment first, then use the value
  Counter result1 = ++c;
  cout << "\nAfter '++c':" << endl;
  cout << "  c       = " << c.getValue() << endl;       // 6
  cout << "  result1 = " << result1.getValue() << endl;  // 6

  // postfix: use old value, then increment
  Counter result2 = c++;
  cout << "\nAfter 'c++':" << endl;
  cout << "  c       = " << c.getValue() << endl;       // 7
  cout << "  result2 = " << result2.getValue() << endl;  // 6 (old value)

  // demonstrating difference in expression context
  cout << "\n--- Expression context demo ---" << endl;
  Counter a(10);

  int x = (++a).getValue();  // a becomes 11, x = 11
  cout << "int x = (++a).getValue()  =>  a = " << a.getValue()
       << ", x = " << x << endl;

  int y = (a++).getValue();  // y gets 11 (old), a becomes 12
  cout << "int y = (a++).getValue()  =>  a = " << a.getValue()
       << ", y = " << y << endl;

  return 0;
}
