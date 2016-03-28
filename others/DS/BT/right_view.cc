#include <stdio.h>

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

void rightSideViewUtil(NODE* root, int level, int* max_level) {
  if (root == nullptr) return;

  if (level > *max_level) {
    printf("%d ", root->data);
    *max_level = level;
  }

  rightSideViewUtil(root->right, level + 1, max_level);
  rightSideViewUtil(root->left, level + 1, max_level);
}

void rightSideView(NODE* root) {
  int max_level = 0;
  rightSideViewUtil(root, 1, &max_level);
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(12);
  root->left = newNode(10);
  root->right = newNode(30);
  root->right->left = newNode(25);
  root->right->right = newNode(40);

  rightSideView(root);

  return 0;
}