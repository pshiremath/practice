#include <stdio.h>
#include <map>

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

void verticalSumUtil(NODE* root, int horizontal_dist,
                     std::map<int, int>& vMap) {
  if (root == nullptr) return;

  verticalSumUtil(root->left, horizontal_dist - 1, vMap);

  int prev_sum = 0;
  std::map<int, int>::iterator it = vMap.find(horizontal_dist);
  if (it != vMap.end()) {
    prev_sum = vMap[horizontal_dist];
  }

  vMap[horizontal_dist] = root->data + prev_sum;

  verticalSumUtil(root->right, horizontal_dist + 1, vMap);
}

void verticalSum(NODE* root) {
  if (root == nullptr) return;
  std::map<int, int> vMap;

  verticalSumUtil(root, 0, vMap);

  while (!vMap.empty()) {
    printf("vertical line : %d vertical sum : %d \n", vMap.begin()->first,
           vMap.begin()->second);
    vMap.erase(vMap.begin());
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

  verticalSum(root);
  return 0;
}