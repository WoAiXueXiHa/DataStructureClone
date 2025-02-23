#include "Tree.h"
#include "Queue.h"
//创建新的节点
BTNode* BuyNode(BTDataType val) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL) {
		perror("malloc() err!");
		return;
	}
	newnode->data = val;
	newnode->left = newnode->right;

	return newnode;
}

//手搓一颗树 层序：1 2 4 3 N 5 6
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
	n4->left = n5;
	n4->right = n6;

	return n1;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root) {
	//无节点
	if (root == NULL) {
		return 0;
	}

	//分治的思想 分别统计左子树节点个数和右子树节点个数 最后加上根节点自己
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树第k层节点个数
//左子树第k-1层节点数 + 右子树第k-1层节点数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	//空树 无节点
	if (root == NULL) {
		return 0;
	}
	//k == 1 指向根节点
	if (root != NULL && k == 1) {
		return 1;
	}
	//开始找子树
	if (k > 1) {
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	//空树
	if (root == NULL) {
		return NULL;
	}
	//分治找左子树 右子树节点
	// 这个方法
	if (root->data == x) {
		return root;
	}
	
	//分治 先找左子树 找到了直接返回 没找到在找右子树
	BTNode* findLeft = BinaryTreeFind(root->left, x);
	if (findLeft != NULL) {
		return findLeft;
	}
	BTNode* findRight = BinaryTreeFind(root->right, x);
	if (findRight != NULL) {
		return findRight;
	}
}

// 二叉树前序遍历 根 左 右
void BinaryTreePrevOrder(BTNode* root) {
	//N代表空
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
	//N代表空
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->right);
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

// 层序遍历 利用队列性质
void BinaryTreeLevelOrder(BTNode* root) {
	Queue helpQueue;
	QueueInit(&helpQueue);
	//将二叉树的节点放入队列 再取出即可

	if (root != NULL)
		QueuePush(&helpQueue, root);
	while (!QueueEmpty) {
		BTNode* front = QueueFrontVal(&helpQueue);
		QueuePop(&helpQueue);
		//带入下一层
		if (front != NULL) {
			printf("%d ", front->data);
			QueuePush(&helpQueue, root->left);
			QueuePush(&helpQueue, root->right);
		}
	}
	printf("\n");

	QueueDestory(&helpQueue);
}

//二叉树的高度
int BinaryTreeHeight(BTNode* root) {
	//空树
	if (root == NULL) {
		return 0;
	}
	//分治 分别求解左右子树高度
	int leftHeight = BinaryTreeHeight(root->left);
	int rightHeight = BinaryTreeHeight(root->right);
	//大的加根节点高度 即是二叉树的高度
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
	assert(*root);
	//后序 先把左右子树销毁 再释放根节点 如果前序 一上来销毁根节点 左右子树需要提前保存 麻烦
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root) {
	Queue helpQueue;
	QueueInit(&helpQueue);
	//将二叉树的节点放入队列 再取出即可

	if (root != NULL)
		QueuePush(&helpQueue, root);

	while (!QueueEmpty) {
		BTNode* front = QueueFrontVal(&helpQueue);
		printf("%d ", front->data);
		//带入下一层
		if (front != NULL) {
			if (root->left != NULL) {
				QueuePush(&helpQueue, root->left);
			}
			if (root->right != NULL) {
				QueuePush(&helpQueue, root->right);
			}
		}
	}
	printf("\n");

	QueueDestory(&helpQueue);
}

