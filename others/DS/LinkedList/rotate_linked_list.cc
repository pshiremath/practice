#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void printList(NODE* node) {
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

void rotate(NODE** head_ref, int count) {
  if (*head_ref == nullptr) return;
  if (count == 0) return;

  NODE* current = *head_ref;
  int k = 1;

  while (k < count && current) {
    current = current->next;
    k++;
  }

  if (current == nullptr) return;
  NODE* kthNode = current;

  while (current->next != nullptr) current = current->next;

  current->next = *head_ref;
  *head_ref = kthNode->next;
  kthNode->next = nullptr;
}

int main(int argc, char const* argv[]) {
  /* Start with the empty list */
  NODE* head = nullptr;

  // create a list 10->20->30->40->50->60
  for (int i = 60; i > 0; i -= 10) {
    push(&head, i);
  }

  printf("Given linked list \n");
  printList(head);
  rotate(&head, 4);

  printf("\nRotated Linked list \n");
  printList(head);
  return 0;
}