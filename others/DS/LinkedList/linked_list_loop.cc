#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = nullptr;
  return node;
}

void detectAndRemoveLoop(NODE* head) {
  NODE* slow = head;
  NODE* fast = head->next;

  while (fast && fast->next) {
    if (slow == fast) break;
    slow = slow->next;
    fast = fast->next->next;
  }

  if (slow == fast) {
    slow = head;

    while (slow != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    fast->next = nullptr;
  }
}

void printList(NODE* node) {
  while (node) {
    printf("%d\n", node->data);
    node = node->next;
  }
}

int main(int argc, char const* argv[]) {
  NODE* head = newNode(50);
  head->next = newNode(20);
  head->next->next = newNode(15);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(10);

  /* Create a loop for testing */
  head->next->next->next->next->next = head->next->next;

  detectAndRemoveLoop(head);

  printf("Linked List after removing loop \n");
  printList(head);
  return 0;
}
