#include <stdlib.h>

#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void Push(NODE** head_ref, int data) {
  if (*head_ref == NULL) {
    NODE* node = static_cast<NODE*>(malloc(sizeof(NODE)));
    node->data = data;
    node->next = NULL;
    *head_ref = node;
  } else {
    NODE* node = static_cast<NODE*>(malloc(sizeof(NODE)));
    node->data = data;
    node->next = *head_ref;
    *(head_ref) = node;
  }
}

int Peek(NODE* head_ref) {
  return head_ref->data;
}

int Pop(NODE** head_ref) {
  NODE* temp = *head_ref;
  *head_ref = temp->next;
  int data = temp->data;
  free(temp);
  return data;
}

int main() {
  NODE* stack = NULL;
  Push(&stack, 1);
  Push(&stack, 2);
  Push(&stack, 3);
  Push(&stack, 4);

  std::cout << Peek(stack) << std::endl;

  std::cout << Pop(&stack) << std::endl;
  std::cout << Pop(&stack) << std::endl;

  return 0;
}