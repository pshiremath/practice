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

NODE* lca(NODE* root, int n1, int n2) {
  if (root == nullptr) return nullptr;

  if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2);

  if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2);

  return root;
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);

  int n1 = 10, n2 = 14;
  NODE* t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);

  n1 = 14, n2 = 8;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);

  n1 = 10, n2 = 22;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);
  return 0;
}