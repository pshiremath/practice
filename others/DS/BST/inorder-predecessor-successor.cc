#include <iostream>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = node->right = nullptr;

  return node;
}

NODE* insert(NODE* root, int data) {
  if (root == nullptr) return newNode(data);

  if (root->data < data) {
    root->right = insert(root->right, data);
  } else {
    root->left = insert(root->left, data);
  }

  return root;
}

void findPredessorSuccessor(NODE* root, NODE** pre, NODE** suc, int key) {
  if (root == nullptr) return;

  if (root->data == key) {
    // the maximum value in left subtree is predecessor
    if (root->left != nullptr) {
      NODE* temp = root->left;
      while (temp->right)
      	temp = temp->right;
      *pre = temp;
    }

    // the minimum value in right subtree is successor
    if (root->right != nullptr) {
      NODE* temp = root->right;
      while (temp->left)
      	temp = temp->left;
      *suc = temp;
    }

    return;
  }

  if (root->data < key) {
    *pre = root;
    findPredessorSuccessor(root->right, pre, suc, key);
  } else {
    *suc = root;
    findPredessorSuccessor(root->left, pre, suc, key);
  }
}

int main(int argc, char const* argv[]) {
  int key = 65;  // Key to be searched in BST

  /* Let us create following BST
             50
          /     \
         30      70
        /  \    /  \
      20   40  60   80 */
  NODE* root = nullptr;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  NODE *pre = nullptr, *suc = nullptr;

  findPredessorSuccessor(root, &pre, &suc, key);
  if (pre != nullptr)
    std::cout << "Predecessor is " << pre->data << std::endl;
  else
    std::cout << "No Predecessor";

  if (suc != nullptr)
    std::cout << "Successor is " << suc->data;
  else
    std::cout << "No Successor";
  return 0;
}