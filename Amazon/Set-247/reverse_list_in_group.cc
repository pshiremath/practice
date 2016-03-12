#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

void printList(NODE* node) {
  while (node) {
    std::cout << node->data << "->";
    node = node->next;
  }
  std::cout << std::endl;
}

NODE* reverse(NODE* head, int k) {
  NODE* current = head;
  NODE* prev = nullptr;
  NODE* next = nullptr;
  int count = 0;

  while (current && count < k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }

  if (next != nullptr) {
    head->next = reverse(next, k);
  }

  return prev;
}

int main(int argc, char const* argv[]) {
  NODE* head = nullptr;

  /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
  push(&head, 9);
  push(&head, 8);
  push(&head, 7);
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  std::cout << "Given linked list is \n";
  printList(head);
  head = reverse(head, 3);

  std::cout << "reversed linked list is \n";
  printList(head);

  return 0;
}