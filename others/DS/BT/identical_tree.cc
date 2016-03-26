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

bool identicalTrees(NODE* root1, NODE* root2) {
  if (root1 == nullptr && root2 == nullptr) return true;

  if (root1 && root2) {
    return (root1->data == root2->data &&
            identicalTrees(root1->left, root2->left) &&
            identicalTrees(root1->right, root2->right));
  }

  return false;
}

int main(int argc, char const* argv[]) {
  NODE* root1 = newNode(1);
  NODE* root2 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(3);
  root1->left->left = newNode(4);
  root1->left->right = newNode(5);

  root2->left = newNode(2);
  root2->right = newNode(3);
  root2->left->left = newNode(4);
  root2->left->right = newNode(5);

  if (identicalTrees(root1, root2))
    printf("Both tree are identical.");
  else
    printf("Trees are not identical.");
  return 0;
}