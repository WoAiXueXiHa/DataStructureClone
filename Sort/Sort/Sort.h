#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Ĭ������

//����ѵĽṹ���ײ�������
typedef int HpDataType;
typedef struct Heap {
	HpDataType* arr;
	size_t size;
	size_t capacity;
}hp;


//��ӡ����
void PrintArray(int* arr, size_t size);

//��������
void Swap(int* p1, int* p2);

//ð������
void BubbleSort(int* arr, size_t size);

//ѡ������
void SelectSort(int* arr, size_t size);

//��������
void InsertSort(int* arr, size_t size);

//ϣ������
void ShellSort(int* arr, size_t size);

//��������
void QuickSort1(int* arr, int left, int right);
void QuickSort2(int* arr, int left, int right);

//������
void AdjustDown(HpDataType* arr, size_t size, size_t parent);
void HeapSort(HpDataType* arr, int size); 