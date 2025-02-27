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
void SelectSort1(int* arr, size_t size) {
	//���[0,n-1]�����ֵ��Ҫ���Ƚ� ��size��Ԫ�أ���Ƚ�size - 1��
	for (size_t i = 0; i < size - 1; i++)
	{
		//��¼��ǰ�ִ���Сֵ������
		size_t mini = i;
		//ÿһ��ǰ���Ԫ�ض�Ҫ�ͺ�������Ԫ�رȽϣ��ȵ����һ��
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				mini = j;
		}
		if (mini != i) 
			Swap(&arr[i], &arr[mini]);
	}
}
//ѡ������
void SelectSort2(int* arr, size_t size) {
	size_t left = 0, right = size - 1;

	while (left < right) {
		//һ������ ���ֵ����Сֵ�����ҵ� �ֱ�ŵ�����ߺ����ұ�
		size_t mini = left, maxi = left;
		//�����һ��ֵ�����ֵ��Сֵ��ֻ��Ҫ�ӵڶ���ֵ��ʼ���� ���µ����ֵ��Сֵ
		for (size_t i = left + 1; i <= right; i++)
		{
			//������С��ֵ/�����ֵ�͸�������
			if (arr[i] < arr[mini])	
				mini = i;
			if (arr[i] > arr[maxi]) 
				maxi = i;
		}
		//����С��ֵ�ŵ���� ����ֵ�ŵ��Ҳ�
		Swap(&arr[left], &arr[mini]);
		if (maxi == left) maxi = mini;
		Swap(&arr[right], &arr[maxi]);
		//��ʼ��һ�ֲ���
		left++;
		right--;
	}
}

//��������
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

//ϣ������
void ShellSort(int* arr, size_t size) {
	int gap = size;
	while (gap > 1){
		gap = gap / 3 + 1;
		for (size_t i = 0; i < size - gap; i++)
		{
			//�����end������int���� ���end - gap��Ϊ���� ��size_t���ͻ�Խ�����
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