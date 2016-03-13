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
    printf("%d \n", node->data);
    node = node->next;
  }
}

NODE* SortedMerge(NODE* a, NODE* b) {
  NODE* result = nullptr;

  if (a == nullptr) return b;

  if (b == nullptr) return a;

  if (a->data <= b->data) {
    result = a;
    result->next = SortedMerge(a->next, b);
  } else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return result;
}

void FrontAndBackSplit(NODE* source, NODE** front_ref, NODE** back_ref) {
  NODE* fast = nullptr;
  NODE* slow = nullptr;

  if (source == nullptr || source->next == nullptr) {
    *front_ref = source;
    *back_ref = nullptr;
  } else {
    slow = source;
    fast = source->next;

    while (fast) {
      fast = fast->next;
      if (fast) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = nullptr;
  }
}

void MergeSort(NODE** head_ref) {
  NODE* head = *head_ref;
  NODE* a = nullptr;
  NODE* b = nullptr;

  if (head == nullptr || head->next == nullptr) return;

  FrontAndBackSplit(head, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *head_ref = SortedMerge(a, b);
}

int main(int argc, char const* argv[]) {
  /* Start with the empty list */
  NODE* res = nullptr;
  NODE* a = nullptr;

  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  /* Sort the above created Linked List */
  MergeSort(&a);

  printf("Sorted Linked List is: \n");
  printList(a);

  return 0;
}
