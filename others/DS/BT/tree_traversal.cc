#include <stdio.h>

typedef struct _TREE {
  int data;
  _TREE* left;
  _TREE* right;
} TREE;

TREE* newNode(int data) {
  TREE* node = new TREE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void printPreorder(TREE* root) {
  if (root) {
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
  }
}

void printInorder(TREE* root) {
  if (root) {
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
  }
}

void printPostorder(TREE* root) {
  if (root) {
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
  }
}

int main(int argc, char const* argv[]) {
  TREE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("\nPreorder traversal of binary tree is \n");
  printPreorder(root);

  printf("\nInorder traversal of binary tree is \n");
  printInorder(root);

  printf("\nPostorder traversal of binary tree is \n");
  printPostorder(root);
  return 0;
}