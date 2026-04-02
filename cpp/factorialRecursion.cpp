#include <iostream>
using namespace std;

// recursive approach
long long factorialRecursive(int n) {
  if (n <= 1)
    return 1;
  return n * factorialRecursive(n - 1);
}

// iterative approach
long long factorialIterative(int n) {
  long long result = 1;
  for (int i = 2; i <= n; i++)
    result *= i;
  return result;
}

int main() {
  int num;

  cout << "Enter a non-negative integer: ";
  cin >> num;

  if (num < 0) {
    cout << "Factorial not defined for negative numbers" << endl;
    return 1;
  }

  long long recResult = factorialRecursive(num);
  long long iterResult = factorialIterative(num);

  cout << "Factorial (recursive):  " << num << "! = " << recResult << endl;
  cout << "Factorial (iterative):  " << num << "! = " << iterResult << endl;

  if (recResult == iterResult)
    cout << "Both methods agree." << endl;

  return 0;
}
