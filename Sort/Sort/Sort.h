#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//默认升序

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
void QuickSort(int* arr, size_t left, size_t right);