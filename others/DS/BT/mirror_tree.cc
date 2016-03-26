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

void inOrder(NODE* root) {
  if (root) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

void mirror(NODE* root) {
  if (root == nullptr) {
    return;
  } else {
    mirror(root->left);
    mirror(root->right);

    NODE* temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  /* Print inorder traversal of the input tree */
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);

  /* Convert tree to its mirror */
  mirror(root);

  /* Print inorder traversal of the mirror tree */
  printf("\n Inorder traversal of the mirror tree is \n");
  inOrder(root);
  return 0;
}