#include "Sort.h"

//交换两数
void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//打印数组
void PrintArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//冒泡排序
void BubbleSort(int* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		bool exchange = 0;
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0) break;
	}
}

//简单选择排序
void SelectSort1(int* arr, size_t size) {
	//外层循环：[0,size-1]
	for (size_t i = 0; i < size - 1; i++)
	{
		//记录最小值的索引
		size_t mini = i;
		//内层循环：找到未排序区间[1,size-1]的最小值
		//需要找size-1个数
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[mini] > arr[j])
				mini = j;
		}
			Swap(&arr[i], &arr[mini]);
	}
}

void SelectSort2(int* arr, size_t size) {
	size_t left = 0, right = size - 1;

	while (left <= right) {
		//假设第一个索引的值既是最大值也是最小值
		size_t mini = left, maxi = left;
		//只需要从第二个值开始遍历 找新的最大值最小值
		for (size_t i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[maxi]) 
				maxi = i;
			if (arr[i] < arr[mini]) 
				mini = i;
		}
		//交换值
		Swap(&arr[left], &arr[mini]);
		//这里需要多个判断 如果maxi == left 两数交换两次相当于没有交换
		if (maxi == left) maxi = mini;
		Swap(&arr[right], &arr[maxi]);

		left++;
		right--;
	}
}

//插入排序
void InsertSort(int* arr, int size) {
	//end走到倒数第二个就停下，无需再做比较
	for (size_t i = 0; i < size - 1; i++)
	{
		//[0,end],end+1
		int end = i;
		int insertVal = arr[end + 1];
		while (end >= 0) {
			if (insertVal < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else {
				break;
			}
		}
		arr[end + 1] = insertVal;
	}
	
}


//希尔排序
void ShellSort(int* arr, size_t size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			//[0,end],end+1
			int end = i;
			int insertVal = arr[end + gap];
			while (end >= 0) {
				if (insertVal < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			arr[end + gap] = insertVal;
		}
	}
} 


//堆排序
//向下调整算法，参数：数组 数组元素个数 开始向下调整的父节点索引
void AdjustDown(HpDataType* arr, size_t size, size_t parent) {
	//找较大的子节点，假设左子节点较大
	size_t child = 2 * parent + 1;
	//child索引不断增大，但不会超过数组元素个数
	while (child < size) {
		//假设错误，右子节点更大，更新索引
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child++;
		}
		//如果父节点小于等于子节点，交换两节点的值
		if (arr[parent] <= arr[child]) {
			Swap(&arr[parent], &arr[child]);
			//更新父节点的索引，现在变成儿子了
			parent = child;
			//继续找儿子比较
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(HpDataType* arr, int size) {
	// 建堆 升序建大根堆 降序建小根堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(arr, size, i);
	}

	// 排序
	int end = size - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
//双指针法快排
void QuickSort1(int* arr, int left, int right) {
	if (left >= right)
		return;

	int prev = left, keyi = left;
	int cur = left + 1;

	while (cur <= right) {
		if (arr[cur] < arr[keyi] && prev++ != cur) {
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[prev], &arr[keyi]);
	keyi = prev;
	//[left, keyi - 1] keyi [keyi + 1, right]
	QuickSort1(arr, left, keyi - 1);
	QuickSort1(arr, keyi + 1, right);
}