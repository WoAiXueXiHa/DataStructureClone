#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//����һ������
//���е�һ���ڵ�
typedef int QDataType;
typedef struct QNode {
	struct QNode* next;
	QDataType data;
}QNode;
//���нṹ
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

//��ʼ������
void QueueInit(Queue* pq);

//���������
void QueuePush(Queue* pq, QDataType val);

//���ݳ�����
void QueuePop(Queue* pq);

//��ȡ������ЧԪ�ظ���
size_t QueueSize(Queue* pq);

//��ȡ����Ԫ��ֵ
QDataType QueueFrontVal(Queue* pq);

//��ȡ��βԪ��ֵ
QDataType QueueBackVal(Queue* pq);

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���ٶ���
void QueueDestory(Queue* pq);