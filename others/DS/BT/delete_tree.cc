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

void deleteTree(NODE* root) {
  if (root == nullptr) return;

  deleteTree(root->left);
  deleteTree(root->right);
  printf("\n Deleting node: %d", root->data);
  delete root;
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  deleteTree(root);
  root = NULL;

  printf("\n Tree deleted ");
  return 0;
}