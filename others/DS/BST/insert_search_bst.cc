#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = node->right = nullptr;

  return node;
}

NODE* insert(NODE* root, int data) {
  if (root == nullptr) return newNode(data);

  if (root->data < data) {
    root->right = insert(root->right, data);
  } else {
    root->left = insert(root->left, data);
  }

  return root;
}

void inorder(NODE* root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = nullptr;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // print inoder traversal of the BST
  inorder(root);
  return 0;
}