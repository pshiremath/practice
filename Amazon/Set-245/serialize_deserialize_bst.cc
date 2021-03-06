#include <stdio.h>

#define MARKER -1

typedef struct _Node {
  int data;
  _Node* left;
  _Node* right;
} Node;

Node* newNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void serialize(Node* node, FILE* fp) {
  if (node == NULL) {
    fprintf(fp, "%d ", MARKER);
    return;
  }

  fprintf(fp, "%d ", node->data);
  serialize(node->left, fp);
  serialize(node->right, fp);
}

void deserialize(Node** root, FILE* fp) {
  int val;

  if (!fscanf(fp, "%d ", &val) || val == MARKER) return;

  *root = newNode(val);
  deserialize(&((*root)->left), fp);
  deserialize(&((*root)->right), fp);
}

void inorder(Node* root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(int argc, char const* argv[]) {
  Node* root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);

  // Let us open a file and serialize the tree into the file
  FILE* fp = fopen("tree.txt", "w");
  if (fp == NULL) {
    puts("Could not open file");
    return 0;
  }
  serialize(root, fp);
  fclose(fp);

  // Let us deserialize the storeed tree into root1
  Node* root1 = NULL;
  fp = fopen("tree.txt", "r");
  deserialize(&root1, fp);

  printf("Inorder Traversal of the tree constructed from file:\n");
  inorder(root1);

  return 0;
}
