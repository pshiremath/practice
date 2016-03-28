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

bool isIsomorphic(NODE* n1, NODE* n2) {
  if (n1 == nullptr && n2 == nullptr) return true;

  if (n1 == nullptr || n2 == nullptr) return false;

  if (n1->data != n2->data) return false;

  return (
      (isIsomorphic(n1->left, n2->left) &&
       isIsomorphic(n1->right, n2->right)) ||
      (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left)));
}

int main(int argc, char const* argv[]) {
  NODE* n1 = newNode(1);
  n1->left = newNode(2);
  n1->right = newNode(3);
  n1->left->left = newNode(4);
  n1->left->right = newNode(5);
  n1->right->left = newNode(6);
  n1->left->right->left = newNode(7);
  n1->left->right->right = newNode(8);

  NODE* n2 = newNode(1);
  n2->left = newNode(3);
  n2->right = newNode(2);
  n2->right->left = newNode(4);
  n2->right->right = newNode(5);
  n2->left->right = newNode(6);
  n2->right->right->left = newNode(8);
  n2->right->right->right = newNode(7);

  if (isIsomorphic(n1, n2))
    printf("Yes \n");
  else
    printf("No \n");
  return 0;
}
