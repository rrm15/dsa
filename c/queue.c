#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
  if (rear == MAX - 1) {
    printf("Queue Overflow\n");
  } else {
    if (front == -1) {
      front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued %d\n", value);
  }
}

void dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue Underflow\n");
  } else {
    printf("Dequeued %d\n", queue[front]);
    front++;
  }
}

void display() {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  display();
  dequeue();
  display();
  return 0;
}
