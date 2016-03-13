#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void printList(NODE* node) {
  while (node) {
    printf("%d\n", node->data);
    node = node->next;
  }
}

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

void reverse(NODE** head_ref) {
  NODE* prev = nullptr;
  NODE* curr = *head_ref;
  NODE* next = nullptr;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head_ref = prev;
}

int main(int argc, char const* argv[]) {
  /* Start with the empty list */
  NODE* head = nullptr;

  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 85);

  printf("Linked List before reversing \n");

  printList(head);

  reverse(&head);

  printf("Reversed Linked list \n");

  printList(head);

  return 0;
}
