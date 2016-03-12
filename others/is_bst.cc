#include <iostream>
#include <limits>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* NewNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

bool BSTUtil(NODE* root, int min, int max) {
  if (root == nullptr) return true;

  if (root->data < min || root->data > max) return false;

  return BSTUtil(root->left, min, root->data - 1) &&
         BSTUtil(root->right, root->data + 1, max);
}

bool isBST(NODE* root) {
  return BSTUtil(root, std::numeric_limits<int>::min(),
                 std::numeric_limits<int>::max());
}

int main(int argc, char const* argv[]) {
  NODE* root = NewNode(4);
  root->left = NewNode(2);
  root->right = NewNode(5);
  root->left->left = NewNode(1);
  root->left->right = NewNode(3);

  if (isBST(root))
    std::cout << "It's a binary tree \n";
  else
    std::cout << "It's not binary tree \n";
  return 0;
}