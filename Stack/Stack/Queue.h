#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//定义一个队列
//队列的一个节点
typedef int QDataType;
typedef struct QNode {
	struct QNode* next;
	QDataType data;
}QNode;
//队列结构
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//数据入队列
void QueuePush(Queue* pq, QDataType val);

//数据出队列
void QueuePop(Queue* pq);

//获取队列有效元素个数
size_t QueueSize(Queue* pq);

//获取队首元素值
QDataType QueueFrontVal(Queue* pq);

//获取队尾元素值
QDataType QueueBackVal(Queue* pq);

//检查队列是否为空
bool QueueEmpty(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);