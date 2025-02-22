#include "Queue.h"

//��ʼ������
void QueueInit(Queue* pq) {
	//���ָ����Ч��
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//���������
void QueuePush(Queue* pq, QDataType val) {
	//���ָ����Ч��
	assert(pq);

	//�����½ڵ�
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	//����ڴ��Ƿ�����ɹ�
	if (newNode == NULL) {
		perror("malloc err!");
		return;
	}
	//��ʼ��newNode
	newNode->data = val;
	newNode->next = NULL;

	//����Ϊ�յ����
	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newNode;
	}

	//����Ϊ�յ����
	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newNode;
	}
	else {
		// ���в�Ϊ�գ�β��
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}

	//������Ч��������
	pq->size++;
}

//���ݳ�����
void QueuePop(Queue* pq) {
	//���ָ����Ч��
	assert(pq);
	//���б�֤����Ϊ�գ��������
	assert(!QueueEmpty(pq));

	//����ֻ��һ���ڵ�
	if (pq->phead->next == NULL) {
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	//�����ж���ڵ㣬ͷɾ
	else {
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	//������ЧԪ�ظ�������
	pq->size--;
}
//��ȡ������ЧԪ�ظ���
size_t QueueSize(Queue* pq){
	//���ָ����Ч��
	assert(pq);

	return pq->size;
}
//��ȡ����Ԫ��ֵ
QDataType QueueFrontVal(Queue* pq) {
	//���ָ����Ч��
	assert(pq);
	// ������� 
	assert(pq->phead != NULL);

	return pq->phead->data;
}

//��ȡ��βԪ��ֵ
QDataType QueueBackVal(Queue* pq) {
	//���ָ����Ч��
	assert(pq);
	// ������� 
	assert(pq->ptail != NULL);

	return pq->ptail->data;
}

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq) {
	//���ָ����Ч��
	assert(pq);

	return pq->size == 0;
}

//���ٶ���
void QueueDestory(Queue* pq) {
	//���ָ����Ч��
	assert(pq);


	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);

		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}