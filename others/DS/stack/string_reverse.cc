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

void reverse(char* str) {
  STACK* stack = nullptr;
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    push(&stack, str[i]);
  }

  for (int i = 0; i < length; i++) {
    str[i] = pop(&stack);
  }
}

int main(int argc, char const* argv[]) {
  char str[] = "GeeksQuiz";

  reverse(str);
  printf("Reversed string is %s", str);
  return 0;
}