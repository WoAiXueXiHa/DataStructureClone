#include "Sort.h"

void TestBubbleSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,12,65,45,33,14};
	PrintArray(arr, sizeof(arr) / sizeof(int));
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestSelectSort() {
	int arr[] = { 2,4,1,3,6,7,9,11,8,5,0};
	PrintArray(arr, sizeof(arr) / sizeof(int));
	SelectSort1(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestInsertSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}
void TestShellSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0,41,14,36,12,33 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	ShellSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestQuickSort1() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0,41,14,36,12,33 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	QuickSort1(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestQuickSort2() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0,41,14,36,12,33 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	QuickSort2(arr, 0, sizeof(arr) / sizeof(int) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestHeapSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0,41,14,36,12,33 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	HeapSort(arr,  sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestMergeSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5,0,41,14,36,12,33 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	MergeSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

int main() {
	/*TestBubbleSort();*/
	/*TestSelectSort();*/
	/*TestInsertSort();*/
	/*TestShellSort();*/
	/*TestQuickSort();*/
	/*TestHeapSort();*/
	/*TestQuickSort2();*/
	TestMergeSort();
	return 0;
}