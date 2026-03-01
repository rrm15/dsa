#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

void display() {
  struct Node *temp = head;
  if (temp == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("Doubly Linked List (forward): ");
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  display();
  return 0;
}
