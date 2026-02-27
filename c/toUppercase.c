#include <stdio.h>

int main() {
  char myStr[1000];
  int i = 0;

  printf("Enter a lowercase string: ");
  fgets(myStr, 1000, stdin);

  while (myStr[i] != '\0') {
    if (myStr[i] >= 'a' && myStr[i] <= 'z') {
      myStr[i] = myStr[i] - 32;
    }
    i++;
  }

  printf("Uppercase: %s\n", myStr);

  return 0;
}
