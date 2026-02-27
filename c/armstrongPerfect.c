#include <math.h>
#include <stdio.h>


int checkArmstrong(int myNum) {
  int tempNum = myNum, digitCount = 0, myDigit;
  int armSum = 0;

  while (tempNum > 0) {
    digitCount++;
    tempNum = tempNum / 10;
  }

  tempNum = myNum;
  while (tempNum > 0) {
    myDigit = tempNum % 10;
    armSum = armSum + (int)pow(myDigit, digitCount);
    tempNum = tempNum / 10;
  }

  if (armSum == myNum)
    return 1;
  else
    return 0;
}

int checkPerfect(int myNum) {
  int i, mySum = 0;

  if (myNum <= 1)
    return 0;

  for (i = 1; i <= myNum / 2; i++) {
    if (myNum % i == 0)
      mySum = mySum + i;
  }

  if (mySum == myNum)
    return 1;
  else
    return 0;
}

int main() {
  int myNum;

  printf("Enter a number: ");
  scanf("%d", &myNum);

  if (checkArmstrong(myNum))
    printf("%d is an Armstrong number\n", myNum);
  else
    printf("%d is not an Armstrong number\n", myNum);

  if (checkPerfect(myNum))
    printf("%d is a Perfect number\n", myNum);
  else
    printf("%d is not a Perfect number\n", myNum);

  return 0;
}
