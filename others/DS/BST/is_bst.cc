#include <bits/stdc++.h>

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

bool isBSTUtil(NODE* root, int min, int max) {
  if (root == nullptr) return true;

  if (root->data < min || root->data > max) return false;

  return (isBSTUtil(root->left, min, root->data - 1) &&
          isBSTUtil(root->right, root->data + 1, max));
}

bool isBST(NODE* root) { return isBSTUtil(root, INT_MIN, INT_MAX); }

int main(int argc, char const* argv[]) {
  NODE* root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);

  if (isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
  return 0;
}