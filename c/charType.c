#include <stdio.h>

int main() {
  char myChar;

  printf("Enter a character: ");
  scanf(" %c", &myChar);

  if (myChar == 'a' || myChar == 'e' || myChar == 'i' || myChar == 'o' ||
      myChar == 'u' || myChar == 'A' || myChar == 'E' || myChar == 'I' ||
      myChar == 'O' || myChar == 'U') {
    printf("%c is a vowel\n", myChar);
  } else if ((myChar >= 'a' && myChar <= 'z') ||
             (myChar >= 'A' && myChar <= 'Z')) {
    printf("%c is a consonant\n", myChar);
  } else if (myChar >= '0' && myChar <= '9') {
    printf("%c is a digit\n", myChar);
  } else {
    printf("%c is a special symbol\n", myChar);
  }

  return 0;
}
