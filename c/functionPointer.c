#include <stdio.h>

int addNums(int a, int b) { return a + b; }

int subtractNums(int a, int b) { return a - b; }

int multiplyNums(int a, int b) { return a * b; }

int divideNums(int a, int b) { return a / b; }

int main() {
  int firstNum, secondNum, myChoice, myResult;
  int (*myOperation)(int, int);

  printf("Enter two integers: ");
  scanf("%d %d", &firstNum, &secondNum);

  printf("Select operation:\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("Your choice: ");
  scanf("%d", &myChoice);

  if (myChoice == 1)
    myOperation = addNums;
  else if (myChoice == 2)
    myOperation = subtractNums;
  else if (myChoice == 3)
    myOperation = multiplyNums;
  else if (myChoice == 4)
    myOperation = divideNums;
  else {
    printf("Invalid choice\n");
    return 1;
  }

  myResult = myOperation(firstNum, secondNum);
  printf("Result = %d\n", myResult);

  return 0;
}
