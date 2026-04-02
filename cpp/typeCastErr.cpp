#include <iostream>
using namespace std;

int main() {

  //   int *pc, c;
  //   c = 5;
  //   pc = &c;
  //   c = 1;
  //   *pc = 5;
  //   cout << *pc << endl;
  //   cout << c << endl;

  //   int a = 5;
  //   cout << a << a++ << ++a << endl;

  char s[] = "Hello";
  char *ptr = s;
  ptr[0] = 'h';
  cout << s;
}
