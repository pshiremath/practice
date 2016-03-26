#include <iostream>
#include <Queue>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
  bool isThreaded;
} NODE;

NODE* newNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;
  node->isThreaded = false;

  return node;
}

void FillInOrderTraversalInQueue(NODE* root, std::queue<NODE*>& q) {
  if (root == nullptr)
    return;

  if (root->left)
    FillInOrderTraversalInQueue(root->left, q);

  q.push(root);

  if (root->right)
    FillInOrderTraversalInQueue(root->right, q);
}

void createThreadedBTFromQueue(NODE* root, std::queue<NODE*>& q) {
  if (root == nullptr)
    return;

  if (root->left)
    createThreadedBTFromQueue(root->left, q);

  q.pop();

  if (root->right) {
    createThreadedBTFromQueue(root->right, q);
  } else if (!q.empty()){
    root->right = q.front();
    root->isThreaded = true;
  }
}

void createThreaded(NODE* root) {
  std::queue<NODE*> q;
  FillInOrderTraversalInQueue(root, q);
  createThreadedBTFromQueue(root, q);
}

NODE* LeftMost(NODE* root) {
  while (root != nullptr && root->left != nullptr) {
    root = root->left;
  }

  return root;
}

void inOrder(NODE* root) {
  if (root == nullptr)
    return;

  NODE* current = LeftMost(root);

  while (current != nullptr) {
    std::cout << "Data : " << current->data << " ";

    if (current->isThreaded) {
      current = current->right;
    } else {
      current = LeftMost(current->right);
    }
  }
}

int main(int argc, char const* argv[]) {
  NODE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  createThreaded(root);

  std::cout << "Inorder traversal of creeated threaded tree is\n";
  inOrder(root);
  return 0;
}