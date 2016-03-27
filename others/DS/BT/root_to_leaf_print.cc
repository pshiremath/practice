#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* newnode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void printPathUtil(int* path, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", path[i]);
  }
  printf("\n");
}

void printPathRec(NODE* root, int path[], int len) {
  if (root == nullptr) return;
  path[len] = root->data;
  len++;

  if (root->left == nullptr && root->right == nullptr) {
    printPathUtil(path, len);
  } else {
    printPathRec(root->left, path, len);
    printPathRec(root->right, path, len);
  }
}

void printPaths(NODE* root) {
  int path[10];
  printPathRec(root, path, 0);
}

int main(int argc, char const* argv[]) {
  NODE* root = newnode(10);
  root->left = newnode(8);
  root->right = newnode(2);
  root->left->left = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);

  printPaths(root);
  return 0;
}