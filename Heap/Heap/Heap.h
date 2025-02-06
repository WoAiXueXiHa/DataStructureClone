#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//����ѵĽṹ���ײ�������
typedef int HpDataType;
typedef struct Heap {
	HpDataType* arr;
	size_t size;
	size_t capacity;
}hp;

void HeapInit(hp* ph);
void HeapPush(hp* ph, HpDataType val);
void HeapPop(hp* ph);
HpDataType HeapTop(hp* ph);
void HeapDestory(hp* ph);
bool HeapEmpty(hp* ph);
