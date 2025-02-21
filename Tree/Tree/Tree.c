#include "Tree.h"

//创建新的节点
BTNode* BuyNode(BTDataType val) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTDataType));
	if (newnode == NULL) {
		perror("malloc err!");
		return;
	}
	newnode->data = val;
	newnode->left = newnode->right;

	return newnode;
}
//手搓一颗树
BTNode* TreeCreate(BTNode* root) {
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n2->right = NULL;
	n4->left = n5;
	n4->right = n6;

	return n1;
}

// 二叉树前序遍历  根 左 右
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历 左 根 右
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

// 二叉树后序遍历 左 右 根
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->right);
	printf("%d ", root->data);
}

// 二叉树节点个数 分治思想
int BinaryTreeSize(BTNode* root) {
	//直接返回左子树节点数+右子树节点数+自己
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//二叉树的高度
int BinaryTreeHeight(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftheight = BinaryTreeHeight(root->left);
	int rightheight = BinaryTreeHeight(root->right);

	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

//第k层节点个数
int BinaryTreeKSize(BTNode* root, int k) {
	assert(k > 0);

	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	//第k层节点数 == 左子树第k - 1层节点数 + 右子树第k - 1层节点数
	//第k层节点在子树中，转化成子问题求解
	if (k > 1 && root != NULL) {
		return BinaryTreeKSize(root->left, k - 1) + BinaryTreeKSize(root->right, k - 1);
	}
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	//根为空 无节点
	if (root == NULL) {
		return NULL;
	}
	//根节点值就是要找的x
	if (root->data == x) {
		return root;
	}
	//开始找子树，需要创建变量保存返回值
	BTNode* retLeft = BinaryTreeFind(root->left, x);
	if (retLeft != NULL) {
		return retLeft;
	}

	BTNode* retRight = BinaryTreeFind(root->right, x);
	if (retRight != NULL) {
		return retRight;
	}

	return NULL;
}

