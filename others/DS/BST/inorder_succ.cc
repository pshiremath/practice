#include <stdio.h>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* insert(NODE* root, int data) {

}

int main(int argc, char const* argv[]) {
  NODE *root = nullptr, *temp, *succ, *min;

  // creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  temp = root->left->right->right;

  succ = inOrderSuccessor(root, temp);
  if (succ != nullptr)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
  else
    printf("\n Inorder Successor doesn't exit");
  return 0;
}