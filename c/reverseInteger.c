#include <limits.h>
#include <stdio.h>


int main() {
  int myNum, reversedNum = 0, myDigit, tempNum;

  printf("Enter an integer: ");
  scanf("%d", &myNum);

  tempNum = myNum;
  if (tempNum < 0)
    tempNum = -tempNum;

  while (tempNum > 0) {
    myDigit = tempNum % 10;
    if (reversedNum > (INT_MAX - myDigit) / 10) {
      printf(
          "Overflow detected! Reversed number is too large for 32-bit int.\n");
      printf("INT_MAX = %d\n", INT_MAX);
      return 0;
    }
    reversedNum = reversedNum * 10 + myDigit;
    tempNum = tempNum / 10;
  }

  if (myNum < 0)
    reversedNum = -reversedNum;

  printf("Original: %d\n", myNum);
  printf("Reversed: %d\n", reversedNum);

  return 0;
}
