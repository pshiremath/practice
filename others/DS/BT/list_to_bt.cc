#include <stdio.h>
#include <queue>

typedef struct _NODE {
  int data;
  _NODE* next;
} NODE;

typedef struct _TREE {
  int data;
  _TREE* left;
  _TREE* right;
} TREE;

void push(NODE** head_ref, int data) {
  NODE* node = new NODE();
  node->data = data;
  node->next = *head_ref;
  *head_ref = node;
}

void printInOrderTraversal(TREE* root) {
  if (root) {
    printInOrderTraversal(root->left);
    printf("%d \n", root->data);
    printInOrderTraversal(root->right);
  }
}

TREE* newNode(int data) {
  TREE* node = new TREE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void ConvertList2Binary(NODE* head, TREE** root) {
  std::queue<TREE*> q;

  if (head == nullptr) {
    *root = nullptr;
    return;
  }

  *root = newNode(head->data);
  q.push(*root);

  head = head->next;

  while (head) {
    TREE* parent = q.front();
    q.pop();

    TREE* left_node = nullptr;
    TREE* right_node = nullptr;

    left_node = newNode(head->data);
    q.push(left_node);

    head = head->next;

    if (head) {
      right_node = newNode(head->data);
      q.push(right_node);
      head = head->next;
    }

    parent->left = left_node;
    parent->right = right_node;
  }
}

int main(int argc, char const* argv[]) {
  NODE* head = nullptr;
  push(&head, 36); /* Last node of Linked List */
  push(&head, 30);
  push(&head, 25);
  push(&head, 15);
  push(&head, 12);
  push(&head, 10);

  TREE* root = nullptr;
  ConvertList2Binary(head, &root);

  printInOrderTraversal(root);
  return 0;
}