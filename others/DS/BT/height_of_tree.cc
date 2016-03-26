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

int maxDepth(NODE* root) {
  if (root == nullptr) {
    return 0;
  } else {
    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);

    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);

  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Hight of tree is %d", maxDepth(root));
  return 0;
}