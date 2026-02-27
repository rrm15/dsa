#include <stdio.h>

void myStrcpy(char destStr[], char srcStr[], int maxLen) {
  int i = 0;

  while (srcStr[i] != '\0' && i < maxLen - 1) {
    destStr[i] = srcStr[i];
    i++;
  }
  destStr[i] = '\0';
}

int main() {
  char sourceStr[1000];
  char destStr[20];
  int destSize = 20;

  printf("Enter a string: ");
  fgets(sourceStr, 1000, stdin);
  int i = 0;
  while (sourceStr[i] != '\0') {
    if (sourceStr[i] == '\n') {
      sourceStr[i] = '\0';
      break;
    }
    i++;
  }

  myStrcpy(destStr, sourceStr, destSize);

  printf("Source: %s\n", sourceStr);
  printf("Copied (max %d chars): %s\n", destSize - 1, destStr);

  printf("\nNote: If source is longer than %d characters, it gets truncated.\n",
         destSize - 1);
  printf("This prevents buffer overflow which happens with regular strcpy\n");
  printf("when the destination buffer is smaller than the source string.\n");

  return 0;
}
