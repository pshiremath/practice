#include <stdio.h>
#include <Queue>

typedef struct _TREE {
  int data;
  _TREE* left;
  _TREE* right;
} TREE;

TREE* newNode(int data) {
  TREE* node = new TREE();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

void printLevelOrder(TREE* root) {
	std::queue<TREE*> temp;
	temp.push(root);

	while (!temp.empty()) {
		TREE* node = temp.front();
		temp.pop();
		printf("%d ", node->data);

		if (node->left) {
			temp.push(node->left);
		}

		if (node->right) {
			temp.push(node->right);
		}
	}
}

int main(int argc, char const* argv[]) {
  TREE* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
  return 0;
}