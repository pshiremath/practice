#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

int Height(NODE* root) {
  if (root == nullptr) {
    return 0;
  } else {
    int lheight = Height(root->left);
    int rheight = Height(root->right);

    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

void printGivenLevel(NODE* root, int level, bool ltr) {
  if (root == nullptr) return;

  if (level == 1) {
    printf("%d ", root->data);
  } else if (level > 1) {
    if (ltr) {
      printGivenLevel(root->left, level - 1, ltr);
      printGivenLevel(root->right, level - 1, ltr);
    } else {
      printGivenLevel(root->right, level - 1, ltr);
      printGivenLevel(root->left, level - 1, ltr);
    }
  }
}

void printSpiral(NODE* root) {
  int height = Height(root);
  bool ltr = true;
  for (int i = 0; i <= height; i++) {
    printGivenLevel(root, i, ltr);
    ltr = !ltr;
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(7);
  root->left->right = newNode(6);
  root->right->left = newNode(5);
  root->right->right = newNode(4);
  printf("Spiral Order traversal of binary tree is \n");
  printSpiral(root);
  return 0;
}