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
  STACK* node = *head_ref;
  *head_ref = (*head_ref)->next;
  int data = node->data;
  delete node;
  return data;
}

int peek(STACK* st) { return st->data; }

int evaluatePostfix(char* exp) {
  STACK* stack = nullptr;
  for (int i = 0; i < exp[i]; i++) {
    if (isdigit(exp[i])) {
      push(&stack, exp[i] - '0');
    } else {
      int val1 = pop(&stack);
      int val2 = pop(&stack);

      switch (exp[i]) {
        case '+':
          push(&stack, val2 + val1);
          break;
        case '-':
          push(&stack, val2 - val1);
          break;
        case '*':
          push(&stack, val2 * val1);
          break;
        case '/':
          push(&stack, val2 / val1);
          break;
      }
    }
  }
  return pop(&stack);
}

int main(int argc, char const* argv[]) {
  char exp[] = "231*+9-";
  printf("Value of %s is %d", exp, evaluatePostfix(exp));
  return 0;
}