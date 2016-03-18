#include <stdio.h>
#include <limits.h>

typedef struct _STACK {
  int data;
  _STACK* next;
} STACK;

void push(STACK** root, int data) {
  STACK* node = new STACK();
  node->data = data;
  node->next = *root;
  *root = node;
}

int pop(STACK** root) {
  if (*root == nullptr) {
    return INT_MIN;
  }

  STACK* temp = *root;
  *root = (*root)->next;
  int data = temp->data;
  delete temp;

  return data;
}

int peek(STACK* root) {
  if (root == nullptr) {
    return INT_MIN;
  }

  return (root->data);
}

int main(int argc, char const* argv[]) {
  STACK* root = nullptr;

  push(&root, 10);
  push(&root, 20);
  push(&root, 30);

  printf("%d popped from stack\n", pop(&root));

  printf("Top element is %d\n", peek(root));
  return 0;
}