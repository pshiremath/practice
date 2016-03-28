#include <stdio.h>
#include <map>
#include <vector>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* NewNode(int data) {
  NODE* node = new NODE();
  node->data = data;
  node->left = node->right = nullptr;

  return node;
}

void PrintTopViewUtil(NODE* node, int level, std::map<int, int>& map) {
  if (node) {
    PrintTopViewUtil(node->left, level - 1, map);
    PrintTopViewUtil(node->right, level + 1, map);
    map[level] = node->data;
  }
}

void PrintTopView(NODE* node) {
  std::map<int, int> map;

  PrintTopViewUtil(node, 0, map);

  std::map<int, int>::iterator it;

  for (it = map.begin(); it != map.end(); it++) {
    printf("%d ", it->second);
  }
}

int main(int argc, char** argv) {
  NODE* root = NewNode(1);
  root->left = NewNode(2);
  root->right = NewNode(3);
  root->left->right = NewNode(4);
  root->left->right->right = NewNode(5);
  root->left->right->right->right = NewNode(6);

  PrintTopView(root);

  return 0;
}
