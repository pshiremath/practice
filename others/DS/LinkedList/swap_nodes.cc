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

void swapNodes(NODE** head_ref, int x, int y) {
  // if x and y are same then don;t do anything.
  if (x == y) return;

  NODE* prevX = nullptr;
  NODE* currX = *head_ref;

  // search for x, update currX and prevX.
  while (currX && currX->data != x) {
    prevX = currX;
    currX = currX->next;
  }

  NODE* prevY = nullptr;
  NODE* currY = *head_ref;

  // search for y, update currY and prevY.
  while (currY && currY->data != y) {
    prevY = currY;
    currY = currY->next;
  }

  // if we couldn't find either x or y then just return.
  if (currY == nullptr || currX == nullptr) return;

  if (prevX != nullptr) {
    prevX->next = currY;
  } else {
    *head_ref = currY;
  }

  if (prevY != nullptr) {
    prevY->next = currX;
  } else {
    *head_ref = currX;
  }

  NODE* temp = currX->next;
  currX->next = currY->next;
  currY->next = temp;
}

int main(int argc, char const* argv[]) {
  NODE* start = nullptr;
  push(&start, 7);
  push(&start, 6);
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);

  printf("Before swapping the nodes \n");
  printList(start);

  swapNodes(&start, 4, 3);

  printf("After swapping the nodes \n");
  printList(start);

  return 0;
}