#include "Tree.h"

//�����µĽڵ�
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
//�ִ�һ����
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

// ������ǰ�����  �� �� ��
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// ������������� �� �� ��
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

// ������������� �� �� ��
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreeInOrder(root->left);
	BinaryTreeInOrder(root->right);
	printf("%d ", root->data);
}

// �������ڵ���� ����˼��
int BinaryTreeSize(BTNode* root) {
	//ֱ�ӷ����������ڵ���+�������ڵ���+�Լ�
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//�������ĸ߶�
int BinaryTreeHeight(BTNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftheight = BinaryTreeHeight(root->left);
	int rightheight = BinaryTreeHeight(root->right);

	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

//��k��ڵ����
int BinaryTreeKSize(BTNode* root, int k) {
	assert(k > 0);

	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	//��k��ڵ��� == ��������k - 1��ڵ��� + ��������k - 1��ڵ���
	//��k��ڵ��������У�ת�������������
	if (k > 1 && root != NULL) {
		return BinaryTreeKSize(root->left, k - 1) + BinaryTreeKSize(root->right, k - 1);
	}
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	//��Ϊ�� �޽ڵ�
	if (root == NULL) {
		return NULL;
	}
	//���ڵ�ֵ����Ҫ�ҵ�x
	if (root->data == x) {
		return root;
	}
	//��ʼ����������Ҫ�����������淵��ֵ
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

