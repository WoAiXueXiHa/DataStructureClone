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
//三数取中
int MidSelect(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	if (arr[mid] > arr[left]) {
		if (arr[mid] < arr[right]) {
			return mid;
		}
		else if(arr[left] > arr[right]) { 
			return left;
		}
		else {
			return right;
		}
	}
	else {// arr[mid] < arr[left]
		if (arr[mid] > arr[right]) {
			return mid;
		}
		else if(arr[left] < arr[right]) {
			return left;
		}
		else {
			return right;
		}
	}
}
//Horae版本快排
void QuickSort1(int* arr, int left, int right) {

	if (left >= right)
		return;
	int begin = left, end = right;

	////为了避免有序或者接近有序的最坏情况发生(O(N^2)),生成一个在[left,right]区间内的随机数作为basei
	////[100, 200]
	//int randi = rand() % (right - left); //数在100之内，不在区间里
	//randi += left; //保证在区间[100, 200]里
	////这样[100, 200]里任意一个数和left交换，就不是最小或者最大做basei了
	//Swap(&arr[randi], &arr[left]);

	int midi = MidSelect(arr, left, right);
	Swap(&arr[midi], &arr[left]);
	int basei = left;
	while (left < right) {
		//右边找小
		while (left < right && arr[basei] <= arr[right]) {
			right--;
		}
		//左边找大
		while (left < right && arr[basei] >= arr[left]) {
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[basei], &arr[left]);

	basei = left;

	//[begin, basei - 1] basei [basei + 1, end]
	QuickSort1(arr, begin, basei - 1);
	QuickSort1(arr, basei + 1, end);
}
//双指针法快排
void QuickSort2(int* arr, int left, int right) {

	if (left >= right)
		return;

	int prev = left;
	int basei = left;
	int cur = left + 1;

	while (cur <= right) {
		if (arr[cur] < arr[basei] && ++prev != cur) {
			Swap(&arr[prev], &arr[cur]);
		}
		++cur;
	}
	Swap(&arr[basei], &arr[prev]);
	basei = prev;

	//[left, basei - 1] basei [basei + 1 , right]
	QuickSort2(arr, left, basei - 1);
	QuickSort2(arr, basei + 1, right);
}

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

//归并排序
void _MergeSort(int* arr, int* tmp, int begin, int end) {
	//分治找最小子区间
	if (begin == end) {
		return;
	}

	int mid = (begin + end) / 2;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	//归并
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] < arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}

	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = arr[begin2++];
	}

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