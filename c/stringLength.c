#include <stdio.h>

int main() {
  char myStr[1000];
  int myLen = 0;

  printf("Enter a string: ");
  fgets(myStr, 1000, stdin);

  while (myStr[myLen] != '\0' && myStr[myLen] != '\n') {
    myLen++;
  }

  printf("Length of string = %d\n", myLen);

  return 0;
}
