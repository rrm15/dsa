#include <stdio.h>

int main() {
  char myStr[1000];
  char removeThis;
  int i, j;

  printf("Enter a string: ");
  fgets(myStr, 1000, stdin);

  printf("Enter character to remove: ");
  scanf(" %c", &removeThis);

  i = 0;
  j = 0;
  while (myStr[i] != '\0') {
    if (myStr[i] != removeThis) {
      myStr[j] = myStr[i];
      j++;
    }
    i++;
  }
  myStr[j] = '\0';

  printf("After removal: %s\n", myStr);

  return 0;
}
