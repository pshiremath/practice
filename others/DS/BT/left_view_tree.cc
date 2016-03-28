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

void leftViewUtil(NODE* root, int level, int* max_level) {
  if (root == nullptr) return;

  printf("level : [%d] max_level : [%d] \n", level, *max_level);
  if (*max_level < level) {
    printf("%d \n", root->data);
    *max_level = level;
  }

  leftViewUtil(root->left, level + 1, max_level);
  leftViewUtil(root->right, level + 1, max_level);
}

void leftView(NODE* root) {
  int max_level = 0;
  leftViewUtil(root, 1, &max_level);
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(12);
  root->left = newNode(10);
  root->right = newNode(30);
  root->right->left = newNode(25);
  root->right->right = newNode(40);

  leftView(root);
  return 0;
}