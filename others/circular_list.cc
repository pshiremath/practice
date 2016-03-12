#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void Push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  NODE* temp = *head_ref;
  node->next = *head_ref;

  if (*head_ref != nullptr) {
    while (temp->next != *head_ref) {
      temp = temp->next;
    }
    temp->next = node;
  } else {
    node->next = node;
  }
  *head_ref = node;
}

void PrintList(NODE* root) {
  NODE* start = root;
  if (start) {
    do {
      std::cout << start->data;
      start = start->next;
    } while (start != root);
  }
}

int main(int argc, char const* argv[]) {
  NODE* head = nullptr;
  Push(&head, 5);
  Push(&head, 4);
  Push(&head, 3);
  Push(&head, 2);
  Push(&head, 1);

  PrintList(head);
  return 0;
}