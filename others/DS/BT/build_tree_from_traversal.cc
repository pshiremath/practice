#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

void printInorder(NODE* root) {
  if (root) {
    printInorder(root->left);
    printf("%c ", root->data);
    printInorder(root->right);
  }
}

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

int search(char* inOrder, int start, int end, int data) {
  for (int i = start; i <= end; i++) {
    if (inOrder[i] == data) {
      return i;
    }
  }
  return -1;
}

NODE* buildTree(char* inOrder, char* preOder, int start, int end) {
  static int preIndex = 0;

  printf("start : [%d] end : [%d] \n", start, end);

  if (start > end) return nullptr;

  NODE* temp = newNode(preOder[preIndex++]);

  if (start == end) return temp;

  int inIndex = search(inOrder, start, end, temp->data);

  printf("Got the index in inOrder array at : [%d] \n", inIndex);

  if (inIndex >= 0) {
    temp->left = buildTree(inOrder, preOder, start, inIndex - 1);

    temp->right = buildTree(inOrder, preOder, inIndex + 1, end);
  }
  return temp;
}

int main(int argc, char const* argv[]) {
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in) / sizeof(in[0]);
  NODE* root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  return 0;
}