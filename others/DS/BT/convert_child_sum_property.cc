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

void printInorder(NODE* root) {
  if (root) {
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
  }
}

void increment(NODE* root, int diff) {
  if (root->left != nullptr) {
    root->left->data = root->left->data + diff;
    increment(root->left, diff);
  } else if (root->right != nullptr) {
    root->right->data = root->right->data + diff;
    increment(root->right, diff);
  }
}

void convertTree(NODE* root) {
  int left_node_data = 0;
  int right_node_data = 0;

  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    return;
  } else {
    convertTree(root->left);
    convertTree(root->right);

    if (root->left != nullptr) left_node_data = root->left->data;

    if (root->right != nullptr) right_node_data = root->right->data;

    int diff = left_node_data + right_node_data - root->data;

    if (diff > 0) {
      root->data = root->data + diff;
    } else if (diff < 0) {
      increment(root, -diff);
    }
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(50);
  root->left = newNode(7);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(1);
  root->right->right = newNode(30);

  printf("\n Inorder traversal before conversion ");
  printInorder(root);

  convertTree(root);

  printf("\n Inorder traversal after conversion ");
  printInorder(root);
  return 0;
}