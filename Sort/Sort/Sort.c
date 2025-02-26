#include "Sort.h"

//打印数组
void PrintArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换两数
void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//冒泡排序
void BubbleSort(int* arr, size_t size) {
	// 外层循环 总共size个数据 需要冒size-1次
	for (size_t i = 0; i < size - 1; i++)
	{
		bool exchange = 0;
		//内层循环 索引0和1的先开始比较 比较次数成等差数列递减
		for (size_t j = 0; j < size - 1 - i; j++)

		{
			if (arr[j] >= arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0) break;
	}
}


//选择排序
void SelectSort(int* arr, size_t size) {
	size_t left = 0, right = size - 1;

	while (left <= right) {
		size_t mini = left, maxi = right;
		for (size_t i = 0; i < size - 1; i++)
		{
			if (arr[i] < arr[mini])	mini = i;
			if (arr[i] > arr[maxi]) maxi = i;
		}
		Swap(&arr[left], &arr[mini]);
		if (maxi == left) maxi = mini;
		Swap(&arr[right], &arr[maxi]);
		left++;
		right--;
	}
}