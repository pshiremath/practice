#include <iostream>

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

NODE* findLCA(NODE* root, int n1, int n2) {
  if (root == nullptr) return nullptr;

  if (root->data == n1 || root->data == n2) return root;

  NODE* left_lca = findLCA(root->left, n1, n2);
  NODE* right_lca = findLCA(root->right, n1, n2);

  if (left_lca && right_lca)
  	return root;

  return (left_lca ? left_lca : right_lca);
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  //std::cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
  std::cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
  // std::cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
  // std::cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
  return 0;
}