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
//����ȡ��
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
//Horae�汾����
void QuickSort1(int* arr, int left, int right) {

	if (left >= right)
		return;
	int begin = left, end = right;

	////Ϊ�˱���������߽ӽ��������������(O(N^2)),����һ����[left,right]�����ڵ��������Ϊbasei
	////[100, 200]
	//int randi = rand() % (right - left); //����100֮�ڣ�����������
	//randi += left; //��֤������[100, 200]��
	////����[100, 200]������һ������left�������Ͳ�����С���������basei��
	//Swap(&arr[randi], &arr[left]);

	int midi = MidSelect(arr, left, right);
	Swap(&arr[midi], &arr[left]);
	int basei = left;
	while (left < right) {
		//�ұ���С
		while (left < right && arr[basei] <= arr[right]) {
			right--;
		}
		//����Ҵ�
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
//˫ָ�뷨����
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

//�鲢����
void _MergeSort(int* arr, int* tmp, int begin, int end) {
	//��������С������
	if (begin == end) {
		return;
	}

	int mid = (begin + end) / 2;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	//�鲢
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