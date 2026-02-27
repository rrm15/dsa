#include <stdio.h>

int main() {
  int myYear;

  printf("Enter a year: ");
  scanf("%d", &myYear);

  int isLeap = (myYear % 4 == 0 && myYear % 100 != 0) ? 1
               : (myYear % 400 == 0)                  ? 1
                                                      : 0;

  (isLeap == 1) ? printf("%d is a leap year\n", myYear)
                : printf("%d is not a leap year\n", myYear);

  return 0;
}
