#include <iostream>
#include <string>
#include <vector>
using namespace std;

// specific overloads (chosen over generic template)
void printDiag(int val) { cout << "[int]    " << val << endl; }

void printDiag(double val) { cout << "[double] " << val << endl; }

void printDiag(const string &val) { cout << "[string] " << val << endl; }

void printDiag(const vector<int> &val) {
  cout << "[vector] { ";
  for (int i = 0; i < val.size(); i++) {
    cout << val[i];
    if (i < val.size() - 1)
      cout << ", ";
  }
  cout << " }" << endl;
}

// generic template - only matched when no specific overload fits
template <typename T> void printDiag(const T &val) {
  cout << "[generic] " << val << endl;
}

int main() {
  cout << "=== printDiag Overloads ===" << endl;

  printDiag(42);           // matches int overload
  printDiag(3.14);         // matches double overload
  printDiag(string("Hi")); // matches string overload

  vector<int> v = {10, 20, 30};
  printDiag(v); // matches vector<int> overload (not generic)

  cout << "\n--- Generic template fallback ---" << endl;
  printDiag('A');  // no char overload → generic template
  printDiag(true); // no bool overload → generic template

  return 0;
}
