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
//三数取中
int ThreeNumMid(int* arr, int left, int right) {
	int mid = (left + right) / 2;

	if (arr[mid] < arr[right]) {
		if (arr[mid] > arr[left]) {
			return mid;
		}
		else if(arr[left] < arr[right]) {
			return left;
		}
		else {
			return right;
		}
	}
	else {// arr[mid] > arr[right]
		if (arr[mid] < arr[left]) {
			return mid;
		}
		else if (arr[right] < arr[left]) {
			return left;
		}
		else {
			return right;
		}
	}
}

//双指针法快排
void QuickSort1(int* arr, int left, int right) {
	if (left >= right)
		return;

	// 新增三数取中逻辑
	int mid = ThreeNumMid(arr, left, right);
	Swap(&arr[left], &arr[mid]);
	int keyi = left;

	int prev = left, cur = left + 1;
	while (cur <= right) {
		if (arr[cur] < arr[keyi] && prev++ != cur) {
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[prev], &arr[keyi]);
	keyi = prev;

	QuickSort1(arr, left, keyi - 1);
	QuickSort1(arr, keyi + 1, right);
}



//Hoare版本快排
void QuickSort2(int* arr, int left, int right) {
	if (left >= right)
		return;
	// 小区间选择走插入，可以减少90%左右的递归
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else {
		//创建变量保存区间边界
		int midi = ThreeNumMid(arr, left, right);
		Swap(&arr[left], &arr[midi]);
		int keyi = left;
		int begin = left, end = right;

		while (left < right) {
			//右边找小
			while (left < right && arr[keyi] <= arr[right]) {
				--right;
			}
			//左边找大
			while (left < right && arr[keyi] >= arr[left]) {
				++left;
			}
			Swap(&arr[left], &arr[right]);
		}

		Swap(&arr[keyi], &arr[left]);
		keyi = left;

		// [begin, keyi-1]keyi[keyi+1, end]
		QuickSort2(arr, begin, keyi - 1);
		QuickSort2(arr, keyi + 1, end);

	}
	
}

//归并排序
void _MergeSort(int* arr, int* tmp, int begin, int end) {
	//递归到最小子区间
	if (begin == end)
		return;

	int mid = (begin + end) / 2;
	//[begin,mid] [mid+1,end]
	_MergeSort(arr, tmp, begin, mid);
	_MergeSort(arr, tmp, mid+1, end);

	//归并排序 将大值尾插到tmp数组中
	//分出两个区间范围值
	int left1 = begin, right1 = mid;
	int left2 = mid + 1, right2 = end;
	int i = begin;
	//判断两个区间的值谁更小
	while (left1 <= right1 && left2 <= right2) {
		if (arr[left1] < arr[left2]) {
			tmp[i++] = arr[left1++];
		}
		else {
			tmp[i++] = arr[left2++];
		}
	}
	//任何一个区间结束，将剩余的直接尾插
	while (left1 <= right1) {
		tmp[i++] = arr[left1++];
	}
	while (left2 <= right2) {
		tmp[i++] = arr[left2++];
	}

	//将排序好的tmp拷贝到arr中
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));


}
void MergeSort(int* arr, size_t size) {
	int* tmp = (int*)malloc(sizeof(int) * size);
	if (tmp == NULL) {
		perror("malloc() err!");
		return;
	}
	_MergeSort(arr, tmp, 0, size - 1);
	free(tmp);
	tmp = NULL;
}

//计数排序
void CountSoort(int* arr, size_t size) {
	//找最大值和最小值
	int min = arr[0], max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	//创建临时数组用于统计次数
	int range = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * range);
	if (tmp == NULL) {
		perror("malloc() err!");
		return;
	}
	memset(tmp, 0, sizeof(int) * range);

	//统计次数
	for (size_t i = 0; i < size; i++)
	{
		tmp[arr[i] - min]++;
	}
	//排序
	int j = 0;
	for (size_t i = 0; i < range; i++)
	{
		while (tmp[i]--) {
			arr[j++] = i + min;
		}
	}

}