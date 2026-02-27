#include <stdio.h>

int fibRecursive(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
  int totalTerms, i;

  printf("Enter number of Fibonacci terms: ");
  scanf("%d", &totalTerms);

  printf("Fibonacci (Iterative): ");
  int firstTerm = 0, secondTerm = 1, nextTerm;
  for (i = 0; i < totalTerms; i++) {
    printf("%d ", firstTerm);
    nextTerm = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = nextTerm;
  }
  printf("\n");

  printf("Fibonacci (Recursive): ");
  for (i = 0; i < totalTerms; i++) {
    printf("%d ", fibRecursive(i));
  }
  printf("\n");

  return 0;
}
