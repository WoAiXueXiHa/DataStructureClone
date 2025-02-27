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
void SelectSort1(int* arr, size_t size) {
	//外层[0,n-1]区间的值需要作比较 有size个元素，则比较size - 1趟
	for (size_t i = 0; i < size - 1; i++)
	{
		//记录当前轮次最小值的索引
		size_t mini = i;
		//每一轮前面的元素都要和后面所有元素比较，比到最后一个
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				mini = j;
		}
		if (mini != i) 
			Swap(&arr[i], &arr[mini]);
	}
}
//选择排序
void SelectSort2(int* arr, size_t size) {
	size_t left = 0, right = size - 1;

	while (left < right) {
		//一轮下俩 最大值和最小值都能找到 分别放到最左边和最右边
		size_t mini = left, maxi = left;
		//假设第一个值是最大值最小值，只需要从第二个值开始遍历 找新的最大值最小值
		for (size_t i = left + 1; i <= right; i++)
		{
			//遇到更小的值/更大的值就更新索引
			if (arr[i] < arr[mini])	
				mini = i;
			if (arr[i] > arr[maxi]) 
				maxi = i;
		}
		//将最小的值放到左侧 最大的值放到右侧
		Swap(&arr[left], &arr[mini]);
		if (maxi == left) maxi = mini;
		Swap(&arr[right], &arr[maxi]);
		//开始新一轮查找
		left++;
		right--;
	}
}

//插入排序
void InsertSort(int* arr, size_t size) {

	for (size_t i = 0; i < size - 1; i++)
	{
		size_t end = i;
		int base = arr[end + 1];
		while (end >= 0) {
			if (arr[end] > base) {
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = base;
	}

}

//希尔排序
void ShellSort(int* arr, size_t size) {
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;
		for (size_t i = 0; i < size - gap; i++)
		{
			//这里的end必须是int类型 如果end - gap成为负数 用size_t类型会越界访问
			int end = i;
			int base = arr[end + gap];
			while (end >= 0) {
				if (arr[end] > base) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = base;
		}

	}
	
}