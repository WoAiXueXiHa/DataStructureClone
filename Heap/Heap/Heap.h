#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//����ѵĽṹ���ײ�������
typedef int HpDataType;
typedef struct Heap {
	HpDataType* arr;
	size_t size;
	size_t capacity;
}hp;

void HeapInit(hp* ph);
void HeapCreate(hp* ph,HpDataType* arr, size_t size);

void HeapPush(hp* ph, HpDataType val);
void HeapPop(hp* ph);

HpDataType HeapTop(hp* ph);

void HeapDestory(hp* ph);
bool HeapEmpty(hp* ph);

Swap(HpDataType* pa, HpDataType* pb);
AdjustUp(HpDataType* arr, size_t child);
AdjustDown(HpDataType* arr, size_t size, size_t parent);

void HeapSort(HpDataType* arr, size_t size);

void DataCreate();
void HeapTopK();


