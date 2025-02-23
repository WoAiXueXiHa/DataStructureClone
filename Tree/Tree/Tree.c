#include "Tree.h"
#include "Queue.h"
//�����µĽڵ�
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

//�ִ�һ���� ����1 2 4 3 N 5 6
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

// �������ڵ����
int BinaryTreeSize(BTNode* root) {
	//�޽ڵ�
	if (root == NULL) {
		return 0;
	}

	//���ε�˼�� �ֱ�ͳ���������ڵ�������������ڵ���� �����ϸ��ڵ��Լ�
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ��������k��ڵ����
//��������k-1��ڵ��� + ��������k-1��ڵ���
int BinaryTreeLevelKSize(BTNode* root, int k) {
	//���� �޽ڵ�
	if (root == NULL) {
		return 0;
	}
	//k == 1 ָ����ڵ�
	if (root != NULL && k == 1) {
		return 1;
	}
	//��ʼ������
	if (k > 1) {
		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	//����
	if (root == NULL) {
		return NULL;
	}
	//������������ �������ڵ�
	// �������
	if (root->data == x) {
		return root;
	}
	
	//���� ���������� �ҵ���ֱ�ӷ��� û�ҵ�����������
	BTNode* findLeft = BinaryTreeFind(root->left, x);
	if (findLeft != NULL) {
		return findLeft;
	}
	BTNode* findRight = BinaryTreeFind(root->right, x);
	if (findRight != NULL) {
		return findRight;
	}
}

// ������ǰ����� �� �� ��
void BinaryTreePrevOrder(BTNode* root) {
	//N�����
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
	//N�����
	if (root == NULL) {
		printf("N ");
		return;
	}

	BinaryTreePrevOrder(root->left);
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->right);
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

// ������� ���ö�������
void BinaryTreeLevelOrder(BTNode* root) {
	Queue helpQueue;
	QueueInit(&helpQueue);
	//���������Ľڵ������� ��ȡ������

	if (root != NULL)
		QueuePush(&helpQueue, root);
	while (!QueueEmpty) {
		BTNode* front = QueueFrontVal(&helpQueue);
		QueuePop(&helpQueue);
		//������һ��
		if (front != NULL) {
			printf("%d ", front->data);
			QueuePush(&helpQueue, root->left);
			QueuePush(&helpQueue, root->right);
		}
	}
	printf("\n");

	QueueDestory(&helpQueue);
}

//�������ĸ߶�
int BinaryTreeHeight(BTNode* root) {
	//����
	if (root == NULL) {
		return 0;
	}
	//���� �ֱ�������������߶�
	int leftHeight = BinaryTreeHeight(root->left);
	int rightHeight = BinaryTreeHeight(root->right);
	//��ļӸ��ڵ�߶� ���Ƕ������ĸ߶�
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// ����������
void BinaryTreeDestory(BTNode** root) {
	assert(*root);
	//���� �Ȱ������������� ���ͷŸ��ڵ� ���ǰ�� һ�������ٸ��ڵ� ����������Ҫ��ǰ���� �鷳
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root) {
	Queue helpQueue;
	QueueInit(&helpQueue);
	//���������Ľڵ������� ��ȡ������

	if (root != NULL)
		QueuePush(&helpQueue, root);

	while (!QueueEmpty) {
		BTNode* front = QueueFrontVal(&helpQueue);
		printf("%d ", front->data);
		//������һ��
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

