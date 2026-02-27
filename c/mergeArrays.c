#include <stdio.h>

int main() {
  int firstArr[100], secondArr[100], mergedArr[200];
  int firstSize, secondSize, i, j, k;

  printf("Enter size of first sorted array: ");
  scanf("%d", &firstSize);
  printf("Enter %d elements (sorted): ", firstSize);
  for (i = 0; i < firstSize; i++)
    scanf("%d", &firstArr[i]);

  printf("Enter size of second sorted array: ");
  scanf("%d", &secondSize);
  printf("Enter %d elements (sorted): ", secondSize);
  for (i = 0; i < secondSize; i++)
    scanf("%d", &secondArr[i]);

  i = 0;
  j = 0;
  k = 0;

  while (i < firstSize && j < secondSize) {
    if (firstArr[i] <= secondArr[j]) {
      mergedArr[k] = firstArr[i];
      i++;
    } else {
      mergedArr[k] = secondArr[j];
      j++;
    }
    k++;
  }

  while (i < firstSize) {
    mergedArr[k] = firstArr[i];
    i++;
    k++;
  }

  while (j < secondSize) {
    mergedArr[k] = secondArr[j];
    j++;
    k++;
  }

  printf("Merged sorted array: ");
  for (i = 0; i < k; i++)
    printf("%d ", mergedArr[i]);
  printf("\n");

  return 0;
}
