#include <stdio.h>

int main() {
  int firstNum, secondNum;

  printf("Enter two integers: ");
  scanf("%d %d", &firstNum, &secondNum);

  printf("Before swap: firstNum = %d, secondNum = %d\n", firstNum, secondNum);

  firstNum = firstNum + secondNum;
  secondNum = firstNum - secondNum;
  firstNum = firstNum - secondNum;

  printf("After swap: firstNum = %d, secondNum = %d\n", firstNum, secondNum);

  return 0;
}
