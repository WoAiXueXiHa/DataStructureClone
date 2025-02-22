#include "Queue.h"

//初始化队列
void QueueInit(Queue* pq) {
	//检查指针有效性
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//数据入队列
void QueuePush(Queue* pq, QDataType val) {
	//检查指针有效性
	assert(pq);

	//创建新节点
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	//检查内存是否申请成功
	if (newNode == NULL) {
		perror("malloc err!");
		return;
	}
	//初始化newNode
	newNode->data = val;
	newNode->next = NULL;

	//队列为空的情况
	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newNode;
	}

	//队列为空的情况
	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newNode;
	}
	else {
		// 队列不为空，尾插
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}

	//队列有效数据增加
	pq->size++;
}

//数据出队列
void QueuePop(Queue* pq) {
	//检查指针有效性
	assert(pq);
	//队列保证不能为空，暴力检查
	assert(!QueueEmpty(pq));

	//队列只有一个节点
	if (pq->phead->next == NULL) {
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	//队列有多个节点，头删
	else {
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	//队列有效元素个数减少
	pq->size--;
}
//获取队列有效元素个数
size_t QueueSize(Queue* pq){
	//检查指针有效性
	assert(pq);

	return pq->size;
}
//获取队首元素值
QDataType QueueFrontVal(Queue* pq) {
	//检查指针有效性
	assert(pq);
	// 暴力检查 
	assert(pq->phead != NULL);

	return pq->phead->data;
}

//获取队尾元素值
QDataType QueueBackVal(Queue* pq) {
	//检查指针有效性
	assert(pq);
	// 暴力检查 
	assert(pq->ptail != NULL);

	return pq->ptail->data;
}

//检查队列是否为空
bool QueueEmpty(Queue* pq) {
	//检查指针有效性
	assert(pq);

	return pq->size == 0;
}

//销毁队列
void QueueDestory(Queue* pq) {
	//检查指针有效性
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