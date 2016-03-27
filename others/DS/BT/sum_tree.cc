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

int sum(NODE* root) {
  if (root == nullptr) return 0;

  return (sum(root->left) + root->data + sum(root->right));
}

bool isSumTree(NODE* root) {
  if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    return true;
  int left_sum = sum(root->left);
  int right_sum = sum(root->right);

  if ((root->data == left_sum + right_sum) &&
      (isSumTree(root->left) && isSumTree(root->right)))
    return true;

  return false;
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(26);
  root->left = newNode(10);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(6);
  root->right->right = newNode(3);
  if (isSumTree(root))
    printf("The given tree is a SumTree ");
  else
    printf("The given tree is not a SumTree ");
  return 0;
}