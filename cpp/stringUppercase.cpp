#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;

  cout << "Enter a string: ";
  getline(cin, str);

  cout << "Length: " << str.length() << endl;

  // convert to uppercase without built-in functions
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - 32;
  }

  cout << "Uppercase: " << str << endl;

  return 0;
}
