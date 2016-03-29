#include <stdio.h>

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

void inorder(NODE* root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */

NODE* minValueNode(NODE* node) {
  NODE* current = node;
  while (current->left != nullptr) current = current->left;

  return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
NODE* deleteNode(NODE* root, int data) {
  // base case
  if (root == nullptr) return root;

  // If the key to be deleted is smaller than the root's key,
  // then it lies in left subtree
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    root->right = deleteNode(root->right, data);
  } else {
    // if key is same as root's key, then This is the node
    // to be deleted

    // node with only one child or no child
    if (root->left == nullptr) {
      NODE* temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      NODE* temp = root->left;
      delete root;
      return temp;
    }

    // node with two children: Get the inorder successor (smallest
    // in the right subtree)
    NODE* temp = minValueNode(root->right);
    // Copy the inorder successor's content to this node
    root->data = temp->data;
    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main(int argc, char const* argv[]) {
  /* Let us create following BST
            50
         /     \
        30      70
       /  \    /  \
     20   40  60   80 */
  NODE* root = nullptr;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder traversal of the given tree \n");
  inorder(root);

  printf("\nDelete 20\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);

  printf("\nDelete 30\n");
  root = deleteNode(root, 30);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);

  printf("\nDelete 50\n");
  root = deleteNode(root, 50);
  printf("Inorder traversal of the modified tree \n");
  inorder(root);
  return 0;
}