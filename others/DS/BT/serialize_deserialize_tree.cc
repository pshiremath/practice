#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

#define MARKER -1

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void serialize(NODE* root, FILE* fp) {
  if (root == nullptr) {
    fprintf(fp, "%d ", MARKER);
    return;
  }

  fprintf(fp, "%d ", root->data);
  serialize(root->left, fp);
  serialize(root->right, fp);
}

void deSerialize(NODE** root1, FILE* fp) {
  int val;

  if (!fscanf(fp, "%d ", &val) || val == MARKER) return;

  *root1 = newNode(val);
  deSerialize(&((*root1)->left), fp);
  deSerialize(&((*root1)->right), fp);
}

void inorder(NODE* root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(int argc, char const* argv[]) {
  // Let us construct a tree shown in the above figure
  NODE* root = newNode(20);
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
  NODE* root1 = NULL;
  fp = fopen("tree.txt", "r");
  deSerialize(&root1, fp);

  printf("Inorder Traversal of the tree constructed from file:\n");
  inorder(root1);
  return 0;
}