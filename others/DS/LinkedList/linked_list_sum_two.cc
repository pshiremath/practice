#include <stdio.h>
#include <cstdlib>

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

int getSize(NODE* node) {
  int count = 0;

  while (node) {
    count++;
    node = node->next;
  }
  return count;
}

NODE* addEqualList(NODE* first, NODE* second, int* carry) {
  if (first == nullptr) return nullptr;

  NODE* res = new NODE();

  res->next = addEqualList(first->next, second->next, carry);
  int sum = first->data + second->data + *carry;
  *carry = sum / 10;
  sum = sum % 10;
  res->data = sum;

  return res;
}

void swapPointers(NODE** a, NODE** b) {
  NODE* temp = *a;
  *a = *b;
  *b = temp;
}

void addCarryToList(NODE* current, NODE* first, NODE** result, int* carry) {
  if (current != first) {
    addCarryToList(current, first->next, result, carry);
    int sum = first->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    push(result, sum);
  }
}

void addList(NODE* first, NODE* second, NODE** result) {
  int carry = 0;
  if (first == nullptr) {
    *result = second;
    return;
  } else if (second == nullptr) {
    *result = first;
    return;
  }
  int size1 = getSize(first);
  int size2 = getSize(second);

  if (size1 == size2) {
    *result = addEqualList(first, second, &carry);
  } else {
    int diff = std::abs(size1 - size2);
    if (size1 < size2) swapPointers(&first, &second);
    NODE* current = nullptr;
    for (current = first; diff--; current = current->next) {
    }
    *result = addEqualList(current, second, &carry);
    addCarryToList(current, first, result, &carry);
  }

  if (carry) push(result, carry);
}

void printList(NODE* node) {
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main(int argc, char const* argv[]) {
  NODE* head1 = nullptr;
  NODE* head2 = nullptr;
  NODE* result = nullptr;

  int arr1[] = {9, 9, 9};
  int arr2[] = {1, 8};

  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  // Create first list as 9->9->9
  int i;
  for (i = size1 - 1; i >= 0; --i) push(&head1, arr1[i]);

  // Create second list as 1->8
  for (i = size2 - 1; i >= 0; --i) push(&head2, arr2[i]);

  addList(head1, head2, &result);

  printList(result);
  return 0;
}