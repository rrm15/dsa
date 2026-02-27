#include <stdio.h>

int main() {
  int myNum, i;
  long long myFactorial = 1;

  printf("Enter a number: ");
  scanf("%d", &myNum);

  if (myNum < 0) {
    printf("Factorial is not defined for negative numbers\n");
    return 0;
  }

  for (i = 1; i <= myNum; i++) {
    myFactorial = myFactorial * i;
  }

  printf("Factorial of %d = %lld\n", myNum, myFactorial);

  return 0;
}
