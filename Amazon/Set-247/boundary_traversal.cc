#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->left = nullptr;
  node->right = nullptr;
  node->data = data;

  return node;
}

void printBoundaryLeft(NODE* root) {
  if (root) {
    if (root->left) {
      printf("%d ", root->data);
      printBoundaryLeft(root->left);
    } else if (root->right) {
      printf("%d ", root->data);
      printBoundaryLeft(root->right);
    }
  }
}

void printBoundaryRight(NODE* root) {
  if (root) {
    if (root->right) {
      printBoundaryRight(root->right);
      printf("%d ", root->data);
    } else if (root->left) {
      printBoundaryRight(root->left);
      printf("%d ", root->data);
    }
  }
}

void printLeaves(NODE* root) {
  if (root) {
    printLeaves(root->left);

    if (!(root->left) && !(root->right)) {
      printf("%d ", root->data);
    }

    printLeaves(root->right);
  }
}

void printBoundary(NODE* root) {
  if (root) {
    printBoundaryLeft(root);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(20);
  root->left = newNode(8);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  root->right = newNode(22);
  root->right->right = newNode(25);

  printBoundary(root);
  return 0;
}