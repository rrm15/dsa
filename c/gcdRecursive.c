#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main() {
  int a, b;
  printf("Enter the numbers for calculating gcd: ");
  scanf("%d %d", &a, &b);
  printf("%d", gcd(a, b));
  return 0;
}

int gcd(int a, int b) {
  int min = a < b ? a : b;

  if (a == 0 || b == 0) {
    return 0;
  }
  int i = 2, gcd = 1;
  while (true) {
    if (a % i == 0 && b % i == 0) {
      gcd *= i;
      a /= i;
      b /= i;
    } else {
      i++;
      printf("%d %d %d\n", i, a, b);
    }
    if (i > a || i > b) {
      break;
    }
  }
  return gcd;
}