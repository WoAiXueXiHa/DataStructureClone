#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack{
	STDataType* arr;
	int size;
	int capacity;
}ST;

//��ʼ��ջ
void STInit(ST* ps);
//����ջ
void STDestory(ST* ps);
//ѹջ
void STPush(ST* ps, STDataType data);
//��ջ
void STPop(ST* ps);
//���ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps);
//ջ�Ĵ�С����ȡջ����ЧԪ�ظ���
int STSize(ST* ps);
//��ȡջ��Ԫ��
STDataType STTop(ST* ps);

