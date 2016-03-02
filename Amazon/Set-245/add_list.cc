#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void Push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *(head_ref) = node;
}

int GetSize(NODE* node) {
  int count = 0;

  while (node) {
    count++;
    node = node->next;
  }

  return count;
}

NODE* AddEqualList(NODE* head1, NODE* head2, int* carry) {
  if (head1 == NULL) return NULL;

  NODE* result = new NODE();
  result->next = AddEqualList(head1->next, head2->next, carry);
  int sum = head1->data + head2->data + *carry;
  *carry = sum / 10;
  sum = sum % 10;
  result->data = sum;

  return result;
}

void SwapPointers(NODE** a, NODE** b) {
  NODE* temp = *a;
  *a = *b;
  *b = temp;
}

void AddCarryToRemaining(NODE* head1, NODE* current, int* carry,
                         NODE** result) {
  int sum = 0;

  if (head1 != current) {
    AddCarryToRemaining(head1, current, carry, result);
    sum = head1->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    Push(result, sum);
  }
}

void AddList(NODE* head1, NODE* head2, NODE** result) {
  if (head1 == NULL) {
    *result = head2;
    return;
  }

  if (head2 == NULL) {
    *result = head1;
    return;
  }

  int size1 = GetSize(head1);
  int size2 = GetSize(head2);

  int carry = 0;

  if (size1 == size2) {
    *result = AddEqualList(head1, head2, &carry);
  } else {
    int diff = abs(size1 - size2);
    if (size1 < size2) SwapPointers(&head1, &head2);

    NODE* current = NULL;

    for (current = head1; diff--; current = current->next) {
    }

    *result = AddEqualList(current, head2, &carry);
    AddCarryToRemaining(head1, current, &carry, result);
  }

  if (carry) Push(result, carry);
}

void PrintList(NODE* node) {
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

int main(int argc, char const* argv[]) {
  NODE* head1 = NULL;
  NODE* head2 = NULL;
  NODE* result = NULL;

  Push(&head1, 7);
  Push(&head1, 8);
  Push(&head1, 9);

  Push(&head2, 7);
  Push(&head2, 8);
  Push(&head2, 9);

  AddList(head1, head2, &result);
  PrintList(result);
  return 0;
}