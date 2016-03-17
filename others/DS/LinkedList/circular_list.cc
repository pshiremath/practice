#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void push(NODE** head_ref, int data) {
  NODE* temp = *head_ref;
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;

  if (*head_ref != nullptr) {
    while (temp->next != *head_ref) {
      temp = temp->next;
    }
    temp->next = node;
  } else {
    node->next = node;
  }

  *head_ref = node;
}

void printList(NODE* node) {
  NODE* temp = node;

  if (node != nullptr) {
    do {
      printf("%d ", node->data);
      node = node->next;
    } while (node != temp);
  }
}

int main(int argc, char const* argv[]) {
  NODE* head = nullptr;

  /* Created linked list will be 11->2->56->12 */
  push(&head, 12);
  push(&head, 56);
  push(&head, 2);
  push(&head, 11);

  printf("Contents of Circular Linked List\n ");
  printList(head);
  return 0;
}