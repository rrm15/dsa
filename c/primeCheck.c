#include <math.h>
#include <stdio.h>


int main() {
  int myNum, i, isPrime = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &myNum);

  if (myNum <= 1) {
    isPrime = 0;
  } else {
    int myLimit = (int)sqrt(myNum);
    for (i = 2; i <= myLimit; i++) {
      if (myNum % i == 0) {
        isPrime = 0;
        break;
      }
    }
  }

  if (isPrime == 1)
    printf("%d is a prime number\n", myNum);
  else
    printf("%d is not a prime number\n", myNum);

  return 0;
}
