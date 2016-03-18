#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _STACK {
  unsigned capacity;
  int top;
  int* array;
} STACK;

STACK* createStack(int capacity) {
  STACK* st = new STACK();
  st->capacity = capacity;
  st->top = -1;
  st->array = static_cast<int*>(malloc(capacity * sizeof(int)));
  return st;
}

bool isFull(STACK* st) { return (st->top == (st->capacity - 1)); }

bool isEmpty(STACK* st) { return (st->top == -1); }

void push(STACK* st, int data) {
  if (isFull(st)) {
    return;
  }
  st->array[++st->top] = data;
}

int pop(STACK* st) {
  if (isEmpty(st)) {
    return INT_MIN;
  }
  return (st->array[st->top--]);
}

int peek(STACK* st) {
  if (isEmpty(st)) {
    return INT_MIN;
  }
  return (st->array[st->top]);
}

int main(int argc, char const* argv[]) {
  STACK* stack = createStack(100);

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  printf("%d popped from stack\n", pop(stack));

  printf("Top item is %d\n", peek(stack));
  return 0;
}