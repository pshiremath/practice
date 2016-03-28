#include <stdio.h>

typedef struct _TREE {
  int data;
  _TREE* left;
  _TREE* right;
} TREE;

TREE* newNode(int data) {
  TREE* node = new TREE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

int heightOfTree(TREE* node) {
  if (node == nullptr) {
    return 0;
  } else {
    int lheight = heightOfTree(node->left);
    int rheight = heightOfTree(node->right);

    if (lheight > rheight) {
      return (lheight + 1);
    } else {
      return (rheight + 1);
    }
  }
}

void printGivenLevel(TREE* root, int level) {
  if (root == nullptr) return;
  if (level == 1)
    printf("%d ", root->data);
  else if (level > 1) {
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
  }
}

void printLevelOrder(TREE* node) {
  int height = heightOfTree(node);
  for (int i = height; i >= 1; i--) {
    printGivenLevel(node, i);
  }
}

int main(int argc, char const* argv[]) {
  TREE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
  return 0;
}