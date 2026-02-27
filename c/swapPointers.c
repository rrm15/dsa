#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapPointers(char **firstPtr, char **secondPtr) {
  char *tempPtr = *firstPtr;
  *firstPtr = *secondPtr;
  *secondPtr = tempPtr;
}

int main() {
  char *firstStr = (char *)malloc(100 * sizeof(char));
  char *secondStr = (char *)malloc(100 * sizeof(char));

  strcpy(firstStr, "Hello");
  strcpy(secondStr, "World");

  printf("Before swap:\n");
  printf("firstStr = %s\n", firstStr);
  printf("secondStr = %s\n", secondStr);

  swapPointers(&firstStr, &secondStr);

  printf("\nAfter swap:\n");
  printf("firstStr = %s\n", firstStr);
  printf("secondStr = %s\n", secondStr);

  free(firstStr);
  free(secondStr);

  return 0;
}
