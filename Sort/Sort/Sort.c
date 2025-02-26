#include "Sort.h"

//��ӡ����
void PrintArray(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������
void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//ð������
void BubbleSort(int* arr, size_t size) {
	// ���ѭ�� �ܹ�size������ ��Ҫðsize-1��
	for (size_t i = 0; i < size - 1; i++)
	{
		bool exchange = 0;
		//�ڲ�ѭ�� ����0��1���ȿ�ʼ�Ƚ� �Ƚϴ����ɵȲ����еݼ�
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


//ѡ������
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