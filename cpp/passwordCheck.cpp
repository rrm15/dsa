#include <iostream>
#include <string>
using namespace std;

int main() {
  string password;

  cout << "Enter a password: ";
  cin >> password;

  if (password.length() > 8)
    cout << "Password is strong (length > 8)" << endl;
  else
    cout << "Password is weak (length <= 8)" << endl;

  return 0;
}
