#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;

  cout << "Enter a string: ";
  getline(cin, str);

  // manual palindrome check without built-in functions
  int len = str.length();
  bool isPalin = true;

  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      isPalin = false;
      break;
    }
  }

  if (isPalin)
    cout << "\"" << str << "\" is a palindrome" << endl;
  else
    cout << "\"" << str << "\" is not a palindrome" << endl;

  return 0;
}
