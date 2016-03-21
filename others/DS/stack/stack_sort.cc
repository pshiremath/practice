#include <bits/stdc++.h>

typedef struct _STACK {
  int data;
  _STACK* next;
} STACK;

void push(STACK** head_ref, int data) {
  STACK* node = new STACK();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

int pop(STACK** head_ref) {
  STACK* temp = *head_ref;
  *head_ref = (*head_ref)->next;
  int data = temp->data;
  delete temp;
  return data;
}

int peek(STACK* st) { return st->data; }

void printStack(STACK* st) {
  while (st) {
    printf("%d ", st->data);
    st = st->next;
  }
}

void sortedInsert(STACK** st, int data) {
  if (*st == nullptr || data > peek(*st)) {
    push(st, data);
    return;
  } else {
    int temp = pop(st);
    sortedInsert(st, data);
    push(st, temp);
  }
}

void sortStack(STACK** head_ref) {
  if (*head_ref) {
    int x = pop(head_ref);
    sortStack(head_ref);
    sortedInsert(head_ref, x);
  }
}

int main(int argc, char const* argv[]) {
  STACK* top = nullptr;

  push(&top, 30);
  push(&top, -5);
  push(&top, 18);
  push(&top, 14);
  push(&top, -3);

  printf("Stack elements before sorting:\n");
  printStack(top);

  sortStack(&top);
  printf("\n\n");

  printf("Stack elements after sorting:\n");
  printStack(top);
  return 0;
}