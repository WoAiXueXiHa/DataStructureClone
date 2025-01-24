#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//����һ��ջ
typedef int STDataType;
typedef struct Stack {
	size_t top;//ջ��
	size_t capacity;//����
	STDataType* arr;//��С�ɱ������
}Stack;

//��ʼ��ջ
void StackInit(Stack* ps);

//������ջ
void StackPush(Stack* ps, STDataType val);

//���ݳ�ջ
void StackPop(Stack* ps);

//����ջ��Ԫ��
STDataType StackTopVal(Stack* ps);

//���ջ����Ч���ݸ���
size_t StackSize(Stack* ps);

//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);

//����ջ
void StackDestory(Stack* ps);