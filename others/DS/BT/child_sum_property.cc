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

bool isSumProperty(NODE* root) {
  int left_node_data = 0;
  int right_node_data = 0;

  if (root == NULL || (root->left == NULL && root->right == NULL)) {
    return true;
  } else {
    if (root->left) {
      left_node_data = root->left->data;
    }

    if (root->right) {
      right_node_data = root->right->data;
    }

    if ((root->data == (left_node_data + right_node_data)) &&
        isSumProperty(root->left) && isSumProperty(root->right))
      return true;
    else
      return false;
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->right = newNode(2);
  if (isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
  return 0;
}