#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fileObj;

  fileObj = fopen("abc.txt", "a");

  if (fileObj == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  for (int i = 0; i < 9; i++) {
    fprintf(fileObj, "%d\n", i);
  }

  fclose(fileObj);
  printf("Successfully wrote to abc.txt\n");

  return 0;
}
