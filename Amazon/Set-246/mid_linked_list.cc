#include <stdlib.h>
#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

void Add(NODE** list, int data) {
  if (*list == NULL) {
    NODE* node = static_cast<NODE*>(malloc(sizeof(NODE)));
    node->data = data;
    node->next = NULL;
    *list = node;
  } else {
    NODE* node = static_cast<NODE*>(malloc(sizeof(NODE)));
    node->data = data;
    node->next = *list;
    *list = node;
  }
}

int MidElement(NODE* list) {
  NODE* slow = list;
  NODE* fast = list;

  if (list != NULL) {
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->data;
  }
  return -1;
}

int main() {
  NODE* list = NULL;
  Add(&list, 1);
  Add(&list, 2);
  Add(&list, 3);
  Add(&list, 4);
  Add(&list, 5);

  std::cout << MidElement(list) << std::endl;
  return 0;
}