#include "Sort.h"

void TestBubbleSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestSelectSort() {
	int arr[] = { 2,4,1,3,6,7,9,8,5 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}

int main() {
	/*TestBubbleSort();*/
	TestSelectSort();
	return 0;
}