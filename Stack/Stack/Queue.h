#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;
//���еĽṹ
typedef struct QueueNode {
	QDataType val;
	struct QueueNode* next;
}QNode;

//�洢�����ڲ������Ľṹ��
//�����ڲ�������������ָ�룬���ظ��ԣ����Խ���������ָ���װ�ɽṹ��
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

//��β�����
void QueuePush(Queue* pq,QDataType data);

//��ͷ������
void QueuePop(Queue* pq);

//��ʼ������
void QueueInit(Queue* pq);

//���Ҷ�����ЧԪ�ظ���
size_t QueueSize(Queue* pq);

//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq);

//��ȡ����β��Ԫ��
QDataType QueueBack(Queue* pq);

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���ٶ���
void QueueDestory(Queue* pq);

