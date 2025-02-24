#include "Tree.h"
#include "Queue.h"

int main() {
	BTNode* root = TreeCreate();
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
}