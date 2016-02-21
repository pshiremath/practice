#include <stdlib.h>

#include <iostream>
#include <map>

typedef struct _NODE {
  int data;
  _NODE* left;
  _NODE* right;
} NODE;

NODE* NewNode(int data) {
  NODE* node = static_cast<NODE*>(malloc(sizeof(NODE)));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void VerticalSumTreeUtil(NODE* tree,
                         int distance,
                         std::map<int, int>& sum_map) {
  if (tree == NULL)
    return;

  VerticalSumTreeUtil(tree->left, distance - 1, sum_map);

  int prev_sum = sum_map[distance];
  sum_map[distance] = prev_sum + tree->data;

  VerticalSumTreeUtil(tree->right, distance + 1, sum_map);
}

void VerticalSumTree(NODE* tree) {
  std::map<int, int> sum_map;
  VerticalSumTreeUtil(tree, 0, sum_map);
  std::map<int, int>::iterator it;

  for (it = sum_map.begin(); it != sum_map.end(); it++) {
    std::cout << it->second << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  NODE* tree = NewNode(1);
  tree->left = NewNode(2);
  tree->right = NewNode(3);
  tree->left->left = NewNode(4);
  tree->left->right = NewNode(5);
  tree->right->left = NewNode(6);
  tree->right->right = NewNode(7);

  VerticalSumTree(tree);

  return 0;
}