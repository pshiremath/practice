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

bool isIdentical(NODE* T, NODE* S) {
  if (T == nullptr && S == nullptr) return true;

  if (T == nullptr || S == nullptr) return false;

  if (T->data == S->data && isIdentical(T->left, S->left) &&
      isIdentical(T->right, S->right))
    return true;

  return false;
}

bool isSubtree(NODE* T, NODE* S) {
  if (S == nullptr) return true;

  if (T == nullptr) return false;

  if (isIdentical(T, S)) return true;

  return isSubtree(T->left, S) || isSubtree(T->right, S);
}

int main(int argc, char const* argv[]) {
  NODE* T = newNode(26);
  T->right = newNode(3);
  T->right->right = newNode(3);
  T->left = newNode(10);
  T->left->left = newNode(4);
  T->left->left->right = newNode(30);
  T->left->right = newNode(6);

  NODE* S = newNode(10);
  S->right = newNode(6);
  S->left = newNode(4);
  S->left->right = newNode(30);

  if (isSubtree(T, S))
    printf("Tree 2 is subtree of Tree 1");
  else
    printf("Tree 2 is not a subtree of Tree 1");
  return 0;
}