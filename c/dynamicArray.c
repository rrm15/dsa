#include <stdio.h>
#include <stdlib.h>

int myData[4];
int mySize = 0;
int myCapacity = 4;
int *myArr;

void initArray() {
  myArr = (int *)malloc(myCapacity * sizeof(int));
  mySize = 0;
}

void resizeArray() {
  myCapacity = myCapacity * 2;
  int *newArr = (int *)malloc(myCapacity * sizeof(int));
  int i;
  for (i = 0; i < mySize; i++) {
    newArr[i] = myArr[i];
  }
  free(myArr);
  myArr = newArr;
  printf("Resized! New capacity = %d\n", myCapacity);
}

void pushElement(int val) {
  if (mySize == myCapacity) {
    resizeArray();
  }
  myArr[mySize] = val;
  mySize++;
}

int popElement() {
  if (mySize == 0) {
    printf("Array is empty, cannot pop!\n");
    return -1;
  }
  mySize--;
  return myArr[mySize];
}

void printArray() {
  int i;
  printf("Array [size=%d, capacity=%d]: ", mySize, myCapacity);
  for (i = 0; i < mySize; i++) {
    printf("%d ", myArr[i]);
  }
  printf("\n");
}

int main() {
  int myChoice, myVal;

  initArray();

  while (1) {
    printf("\n1. Push\n2. Pop\n3. Print\n4. Exit\n");
    printf("Choice: ");
    scanf("%d", &myChoice);

    if (myChoice == 1) {
      printf("Enter value: ");
      scanf("%d", &myVal);
      pushElement(myVal);
      printf("Pushed %d\n", myVal);
    } else if (myChoice == 2) {
      myVal = popElement();
      if (myVal != -1)
        printf("Popped %d\n", myVal);
    } else if (myChoice == 3) {
      printArray();
    } else if (myChoice == 4) {
      free(myArr);
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid choice\n");
    }
  }

  return 0;
}
