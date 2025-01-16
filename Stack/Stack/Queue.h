#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;
//队列的结构
typedef struct QueueNode {
	QDataType val;
	struct QueueNode* next;
}QNode;

//存储函数内部参数的结构体
//函数内部定义两个二级指针，有重复性，可以将两个二级指针封装成结构体
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

//队尾入队列
void QueuePush(Queue* pq,QDataType data);

//队头出队列
void QueuePop(Queue* pq);

//初始化队列
void QueueInit(Queue* pq);

//查找队列有效元素个数
size_t QueueSize(Queue* pq);

//获取队列头部元素
QDataType QueueFront(Queue* pq);

//获取队列尾部元素
QDataType QueueBack(Queue* pq);

//检测队列是否为空
bool QueueEmpty(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);

