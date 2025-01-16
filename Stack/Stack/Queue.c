#include "Queue.h"

//初始化队列
void QueueInit(Queue* pq) {
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//销毁队列
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
//队尾入队列
void QueuePush(Queue* pq, QDataType data) {
	assert(pq);
	//创建新的节点，准备入队
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL) {
		perror("malloc() error");
		return;
	}
	//新节点创建成功
	newNode->next = NULL;
	newNode->val = data;
	//如果队列不为空
	if (pq->ptail) {
		// 将原队列尾部节点的 next 指针指向新节点，使新节点成为队列的新尾部
		pq->ptail->next = newNode;
		// 更新队列的尾部指针 ptail，使其指向新节点
		//newNode是局部变量，出作用域就销毁
		pq->ptail = newNode;
	}
	else {
		pq->phead = pq->ptail = newNode;
	}
	pq->size++;

}

//队头出队列
void QueuePop(Queue* pq) {
	assert(pq);

	//暴力检查 如果队列为空 则元素不能出队列
	assert(pq->phead != NULL);

	//如果队列中只有一个元素
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


//查找队列有效元素个数
size_t QueueSize(Queue* pq) {
	assert(pq);

	return pq->size;
}

//获取队列头部元素
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

//获取队列尾部元素
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

//检测队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);

	return pq->size == 0;
}



