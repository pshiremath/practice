#include <stdio.h>
#include <stdlib.h>

#define MARKER -1

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void serialize(Node* root, FILE* fp) {
  if (root == NULL) {
    fprintf(fp, "%d", MARKER);
    return;
  }

  fprintf(fp, "%d", root->data);
  serialize(root->left, fp);
  serialize(root->right, fp);
}

void inorder(Node* root) {
  if (root) {
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
  }
}

void deSerialize(Node** root, FILE* fp) {
  int val;
  if (!fscanf(fp, "%d", &val) || val == MARKER)
    return;
  *root = newNode(val);
  deSerialize(&((*root)->left), fp);
  deSerialize(&((*root)->right), fp);
}

int main(int argc, char const* argv[]) {
  // Let us construct a tree shown in the above figure
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
  deSerialize(&root1, fp);
  printf("Inorder Traversal of the tree constructed from file:\n");
  inorder(root);
  return 0;
}