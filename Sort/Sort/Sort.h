#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//默认升序

//定义堆的结构，底层是数组
typedef int HpDataType;
typedef struct Heap {
	HpDataType* arr;
	size_t size;
	size_t capacity;
}hp;


//打印数组
void PrintArray(int* arr, size_t size);

//交换两数
void Swap(int* p1, int* p2);

//冒泡排序
void BubbleSort(int* arr, size_t size);

//选择排序
void SelectSort(int* arr, size_t size);

//插入排序
void InsertSort(int* arr, size_t size);

//希尔排序
void ShellSort(int* arr, size_t size);

//快速排序
void QuickSort1(int* arr, int left, int right);
void QuickSort2(int* arr, int left, int right);

//堆排序
void AdjustDown(HpDataType* arr, size_t size, size_t parent);
void HeapSort(HpDataType* arr, int size); 