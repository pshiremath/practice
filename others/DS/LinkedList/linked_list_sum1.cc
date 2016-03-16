#include <stdio.h>

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
    printf("%d ", node->data);
    node = node->next;
  }
}

NODE* NewNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = nullptr;
  return node;
}

NODE* addTwoLists(NODE* first, NODE* second) {
  NODE* res = nullptr;
  int sum, carry = 0;
  NODE* prev = nullptr;
  NODE* temp = nullptr;

  while (first != nullptr || second != nullptr) {
    sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
    carry = sum / 10;
    sum = sum % 10;

    temp = NewNode(sum);

    if (res != nullptr) {
      prev->next = temp;
    } else {
      res = temp;
    }

    prev = temp;

    if (first) first = first->next;
    if (second) second = second->next;
  }

  if (carry > 0) temp = NewNode(carry);

  return res;
}

int main(int argc, char const* argv[]) {
  NODE* res = nullptr;
  NODE* first = nullptr;
  NODE* second = nullptr;

  // create first list 7->5->9->4->6
  push(&first, 6);
  push(&first, 4);
  push(&first, 9);
  push(&first, 5);
  push(&first, 7);
  printf("First List is ");
  printList(first);

  // create second list 8->4
  push(&second, 4);
  push(&second, 8);
  printf("Second List is ");
  printList(second);

  // Add the two lists and see result
  res = addTwoLists(first, second);
  printf("Resultant list is ");
  printList(res);
  return 0;
}