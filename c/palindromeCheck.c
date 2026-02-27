#include <stdio.h>

char toLowerChar(char ch) {
  if (ch >= 'A' && ch <= 'Z')
    return ch + 32;
  return ch;
}

int isAlphaNum(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9'))
    return 1;
  return 0;
}

int main() {
  char myStr[1000];
  char cleanStr[1000];
  int i, j = 0, myLen, isPalin = 1;

  printf("Enter a string: ");
  fgets(myStr, 1000, stdin);

  i = 0;
  while (myStr[i] != '\0' && myStr[i] != '\n') {
    if (isAlphaNum(myStr[i])) {
      cleanStr[j] = toLowerChar(myStr[i]);
      j++;
    }
    i++;
  }
  cleanStr[j] = '\0';
  myLen = j;

  int leftIdx = 0;
  int rightIdx = myLen - 1;
  while (leftIdx < rightIdx) {
    if (cleanStr[leftIdx] != cleanStr[rightIdx]) {
      isPalin = 0;
      break;
    }
    leftIdx++;
    rightIdx--;
  }

  if (isPalin)
    printf("It is a palindrome\n");
  else
    printf("It is not a palindrome\n");

  return 0;
}
