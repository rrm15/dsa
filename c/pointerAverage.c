#include <stdio.h>

int main() {
  int myArr[100], mySize, i;
  float mySum = 0;

  printf("Enter array size: ");
  scanf("%d", &mySize);

  printf("Enter %d elements: ", mySize);
  for (i = 0; i < mySize; i++) {
    scanf("%d", (myArr + i));
  }

  for (i = 0; i < mySize; i++) {
    mySum = mySum + *(myArr + i);
  }

  float myAvg = mySum / mySize;
  printf("Average = %.2f\n", myAvg);

  return 0;
}
