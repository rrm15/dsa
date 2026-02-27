#include <stdio.h>

int main() {
  int firstNum, secondNum;
  int mySum, myDiff, myProduct, myQuotient;

  printf("Enter two integers: ");
  scanf("%d %d", &firstNum, &secondNum);

  mySum = firstNum + secondNum;
  myDiff = firstNum - secondNum;
  myProduct = firstNum * secondNum;
  myQuotient = firstNum / secondNum;

  printf("Sum = %d\n", mySum);
  printf("Difference = %d\n", myDiff);
  printf("Product = %d\n", myProduct);
  printf("Integer Quotient = %d\n", myQuotient);

  return 0;
}
