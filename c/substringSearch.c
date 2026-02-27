#include <stdio.h>

int findSubstring(char mainStr[], char subStr[]) {
  int i, j;
  int mainLen = 0, subLen = 0;

  while (mainStr[mainLen] != '\0')
    mainLen++;
  while (subStr[subLen] != '\0')
    subLen++;

  for (i = 0; i <= mainLen - subLen; i++) {
    int matchFound = 1;
    for (j = 0; j < subLen; j++) {
      if (mainStr[i + j] != subStr[j]) {
        matchFound = 0;
        break;
      }
    }
    if (matchFound)
      return i;
  }

  return -1;
}

int main() {
  char mainStr[1000], subStr[100];

  printf("Enter main string: ");
  fgets(mainStr, 1000, stdin);
  int i = 0;
  while (mainStr[i] != '\0') {
    if (mainStr[i] == '\n') {
      mainStr[i] = '\0';
      break;
    }
    i++;
  }

  printf("Enter substring to find: ");
  fgets(subStr, 100, stdin);
  i = 0;
  while (subStr[i] != '\0') {
    if (subStr[i] == '\n') {
      subStr[i] = '\0';
      break;
    }
    i++;
  }

  int myResult = findSubstring(mainStr, subStr);

  if (myResult != -1)
    printf("Substring found at index %d\n", myResult);
  else
    printf("Substring not found\n");

  return 0;
}
