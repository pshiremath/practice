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

  return root->data;
}

int isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}

void infixToPostfix(char* exp) {
  int i, k;
  STACK* stack = nullptr;

  for (i = 0, k = -1; exp[i]; i++) {
    if (isOperand(exp[i])) {
      exp[++k] = exp[i];
    }

    else if (exp[i] == '(') {
      push(&stack, exp[i]);
    }

    else if (exp[i] == ')') {
      while (stack && peek(stack) != '(') {
        exp[++k] = pop(&stack);
      }
      if (stack && peek(stack) != '(') {
        return;
      } else {
        pop(&stack);
      }
    } else {
      while (stack && Prec(exp[i]) <= Prec(peek(stack))) {
        exp[++k] = pop(&stack);
      }
      push(&stack, exp[i]);
    }
  }
  // pop all the operators from the stack
  while (stack) {
    exp[++k] = pop(&stack);
  }
  exp[++k] = '\0';
  printf("%s\n", exp);
}

int main(int argc, char const* argv[]) {
  char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
  infixToPostfix(exp);
  return 0;
}