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

int toSumTree(NODE* root) {
  if (root == nullptr) return 0;

  int old_value = root->data;
  printf("old_value : [%d] \n", old_value);

  root->data = toSumTree(root->left) + toSumTree(root->right);

  printf("root->data : [%d] \n", root->data);
  return root->data + old_value;
}

void printInorder(NODE* node) {
  if (node) {
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
  }
}

#if 0
                  10
               /      \
              -2        6
           /   \      /  \ 
         8     -4    7    5
#endif
int main(int argc, char const* argv[]) {
  NODE* root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);

  toSumTree(root);

  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
  return 0;
}