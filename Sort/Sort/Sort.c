#include "Sort.h"

//��������
void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//��ӡ����
void PrintArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ð������
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

//��ѡ������
void SelectSort1(int* arr, size_t size) {
	//���ѭ����[0,size-1]
	for (size_t i = 0; i < size - 1; i++)
	{
		//��¼��Сֵ������
		size_t mini = i;
		//�ڲ�ѭ�����ҵ�δ��������[1,size-1]����Сֵ
		//��Ҫ��size-1����
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
		//�����һ��������ֵ�������ֵҲ����Сֵ
		size_t mini = left, maxi = left;
		//ֻ��Ҫ�ӵڶ���ֵ��ʼ���� ���µ����ֵ��Сֵ
		for (size_t i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[maxi]) 
				maxi = i;
			if (arr[i] < arr[mini]) 
				mini = i;
		}
		//����ֵ
		Swap(&arr[left], &arr[mini]);
		//������Ҫ����ж� ���maxi == left �������������൱��û�н���
		if (maxi == left) maxi = mini;
		Swap(&arr[right], &arr[maxi]);

		left++;
		right--;
	}
}

//��������
void InsertSort(int* arr, int size) {
	//end�ߵ������ڶ�����ͣ�£����������Ƚ�
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


//ϣ������
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


//������
//���µ����㷨������������ ����Ԫ�ظ��� ��ʼ���µ����ĸ��ڵ�����
void AdjustDown(HpDataType* arr, size_t size, size_t parent) {
	//�ҽϴ���ӽڵ㣬�������ӽڵ�ϴ�
	size_t child = 2 * parent + 1;
	//child�����������󣬵����ᳬ������Ԫ�ظ���
	while (child < size) {
		//����������ӽڵ���󣬸�������
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child++;
		}
		//������ڵ�С�ڵ����ӽڵ㣬�������ڵ��ֵ
		if (arr[parent] <= arr[child]) {
			Swap(&arr[parent], &arr[child]);
			//���¸��ڵ�����������ڱ�ɶ�����
			parent = child;
			//�����Ҷ��ӱȽ�
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(HpDataType* arr, int size) {
	// ���� ���򽨴���� ����С����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(arr, size, i);
	}

	// ����
	int end = size - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
//˫ָ�뷨����
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