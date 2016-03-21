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

void print(STACK* st) {
  while (st) {
    printf("%d ", st->data);
    st = st->next;
  }
}

void insertAtBottom(STACK** head_ref, int data) {
  if (*head_ref == nullptr) {
    push(head_ref, data);
  } else {
    /* Hold all items in Function Call Stack until we reach end of the stack.
       When the stack becomes empty, the isEmpty(*top_ref)becomes true, the
       above if part is executed and the item is inserted at the bottom */
    int temp = pop(head_ref);
    insertAtBottom(head_ref, data);
    /* Once the item is inserted at the bottom, push all the items held in
       Function Call Stack */
    push(head_ref, temp);
  }
}

void reverse(STACK** st) {
  if (*st) {
    /* Hold all items in Function Call Stack until we
       reach end of the stack */
    int temp = pop(st);
    reverse(st);
    /* Insert all the items (held in Function Call Stack)
       one by one from the bottom to top. Every item is
       inserted at the bottom */
    insertAtBottom(st, temp);
  }
}

int main(int argc, char const* argv[]) {
  STACK* s = nullptr;
  push(&s, 4);
  push(&s, 3);
  push(&s, 2);
  push(&s, 1);

  printf("\n Original Stack ");
  print(s);
  reverse(&s);
  printf("\n Reversed Stack ");
  print(s);
  return 0;
}