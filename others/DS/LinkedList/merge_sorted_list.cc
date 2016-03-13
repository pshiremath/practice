#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

NODE* SortedMerge(NODE* a, NODE* b) {
  NODE* result = nullptr;
  if (a == nullptr) return b;

  if (b == nullptr) return a;

  if (a->data < b->data) {
    result = a;
    result->next = SortedMerge(a->next, b);
  } else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }

  return result;
}

void printList(NODE* node) {
  while (node) {
    printf("%d \n", node->data);
    node = node->next;
  }
}

int main(int argc, char const* argv[]) {
  /* Start with the empty list */
  NODE* res = nullptr;
  NODE* a = nullptr;
  NODE* b = nullptr;

  /* Let us create two sorted linked lists to test the functions
   Created lists shall be a: 5->10->15,  b: 2->3->20 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  /* Remove duplicates from linked list */
  res = SortedMerge(a, b);

  printf("Merged Linked List is: \n");
  printList(res);

  return 0;
}
