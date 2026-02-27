#include <stdio.h>

int addNums(int a, int b) { return a + b; }

int subtractNums(int a, int b) { return a - b; }

int multiplyNums(int a, int b) { return a * b; }

int divideNums(int a, int b) { return a / b; }

int main() {
  int (*operations[4])(int, int) = {addNums, subtractNums, multiplyNums,
                                    divideNums};
  char opNames[4][15] = {"Addition", "Subtraction", "Multiplication",
                         "Division"};

  int firstNum, secondNum, myChoice;

  while (1) {
    printf("\n--- Calculator Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &myChoice);

    if (myChoice == 5) {
      printf("Goodbye!\n");
      break;
    }

    if (myChoice < 1 || myChoice > 4) {
      printf("Invalid choice, try again\n");
      continue;
    }

    printf("Enter two integers: ");
    scanf("%d %d", &firstNum, &secondNum);

    if (myChoice == 4 && secondNum == 0) {
      printf("Cannot divide by zero!\n");
      continue;
    }

    int myResult = operations[myChoice - 1](firstNum, secondNum);
    printf("%s result: %d\n", opNames[myChoice - 1], myResult);
  }

  return 0;
}
