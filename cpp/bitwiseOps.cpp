#include <iostream>
using namespace std;

int main() {
  int a, b;

  cout << "Enter two integers: ";
  cin >> a >> b;

  cout << "a = " << a << " (binary representation)" << endl;
  cout << "b = " << b << " (binary representation)" << endl;
  cout << endl;

  cout << "a AND b  = " << (a & b) << endl;
  cout << "a OR b   = " << (a | b) << endl;
  cout << "a XOR b  = " << (a ^ b) << endl;
  cout << endl;

  int shift;
  cout << "Enter number of positions to shift: ";
  cin >> shift;

  cout << "a << " << shift << " = " << (a << shift) << endl;
  cout << "a >> " << shift << " = " << (a >> shift) << endl;
  cout << "b << " << shift << " = " << (b << shift) << endl;
  cout << "b >> " << shift << " = " << (b >> shift) << endl;

  return 0;
}
