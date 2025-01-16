#include "Queue.h"

//��ʼ������
void QueueInit(Queue* pq) {
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//���ٶ���
void QueueDestory(Queue* pq) {
	assert(pq);

	QNode* cur = pq->phead;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//��β�����
void QueuePush(Queue* pq, QDataType data) {
	assert(pq);
	//�����µĽڵ㣬׼�����
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		perror("malloc() error");
		return;
	}
	//�½ڵ㴴���ɹ�
	newNode->next = NULL;
	newNode->val = data;
	//������в�Ϊ��
	if (pq->ptail) {
		// ��ԭ����β���ڵ�� next ָ��ָ���½ڵ㣬ʹ�½ڵ��Ϊ���е���β��
		pq->ptail->next = newNode;
		// ���¶��е�β��ָ�� ptail��ʹ��ָ���½ڵ�
		//newNode�Ǿֲ��������������������
		pq->ptail = newNode;
	}
	else {
		pq->phead = pq->ptail = newNode;
	}
	pq->size++;

}

//��ͷ������
void QueuePop(Queue* pq) {
	assert(pq);

	//������� �������Ϊ�� ��Ԫ�ز��ܳ�����
	assert(pq->phead != NULL);

	//���������ֻ��һ��Ԫ��
	if (pq->phead->next == NULL) {
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else {
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}


//���Ҷ�����ЧԪ�ظ���
size_t QueueSize(Queue* pq) {
	assert(pq);

	return pq->size;
}

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq) {
	assert(pq);

	return pq->size == 0;
}



