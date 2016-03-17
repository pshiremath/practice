#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
  int data;
  _NODE* next;
  _NODE* prev;
} NODE;

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  node->prev = NULL;

  if (*head_ref != nullptr) {
    (*head_ref)->prev = node;
  }

  *head_ref = node;
}

void printList(NODE* node) {
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

void deleteNode(NODE** head_ref, NODE* dNode) {
  if (*head_ref == nullptr || dNode == nullptr) {
    return;
  }

  if (*head_ref == dNode) {
    *head_ref = dNode->next;
  }

  if (dNode->next != nullptr) {
    dNode->next->prev = dNode->prev;
  }

  if (dNode->prev != nullptr) {
    dNode->prev->next = dNode->next;
  }

  free(dNode);
}

int main(int argc, char const* argv[]) {
  /* Start with the empty list */
  NODE* head = nullptr;

  /* Let us create the doubly linked list 10<->8<->4<->2 */
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);

  printf("\n Original Linked list ");
  printList(head);

  /* delete nodes from the doubly linked list */
  deleteNode(&head, head);       /*delete first node*/
  deleteNode(&head, head->next); /*delete middle node*/
  deleteNode(&head, head->next); /*delete last node*/

  /* Modified linked list will be NULL<-8->NULL */
  printf("\n Modified Linked list ");
  printList(head);
  return 0;
}