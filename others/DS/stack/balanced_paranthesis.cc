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

bool isMatching(char a, char b) {
  if (a == '{' && b == '}')
    return true;
  else if (a == '[' && b == ']')
    return true;
  else if (a == '(' && b == ')')
    return true;
  else
    return false;
}

bool areParenthesisBalanced(char* exp) {
  STACK* st = nullptr;
  int length = strlen(exp);
  int i = 0;

  while (i < length) {
    if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
      push(&st, exp[i]);
    } else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
      if (st == nullptr) return false;

      if (!isMatching(pop(&st), exp[i])) return false;
    } else {
      return false;
    }
    i++;
  }
  return true;
}

int main(int argc, char const* argv[]) {
  char exp[100] = "{()}[]";
  if (areParenthesisBalanced(exp))
    printf("\n Balanced ");
  else
    printf("\n Not Balanced ");
  return 0;
}