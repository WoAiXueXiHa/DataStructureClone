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
//����ȡ��
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

//˫ָ�뷨����
void QuickSort1(int* arr, int left, int right) {
	if (left >= right)
		return;

	// ��������ȡ���߼�
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



//Hoare�汾����
void QuickSort2(int* arr, int left, int right) {
	if (left >= right)
		return;
	// С����ѡ���߲��룬���Լ���90%���ҵĵݹ�
	if (right - left + 1 < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else {
		//����������������߽�
		int midi = ThreeNumMid(arr, left, right);
		Swap(&arr[left], &arr[midi]);
		int keyi = left;
		int begin = left, end = right;

		while (left < right) {
			//�ұ���С
			while (left < right && arr[keyi] <= arr[right]) {
				--right;
			}
			//����Ҵ�
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

//�鲢����
void _MergeSort(int* arr, int* tmp, int begin, int end) {
	//�ݹ鵽��С������
	if (begin == end)
		return;

	int mid = (begin + end) / 2;
	//[begin,mid] [mid+1,end]
	_MergeSort(arr, tmp, begin, mid);
	_MergeSort(arr, tmp, mid+1, end);

	//�鲢���� ����ֵβ�嵽tmp������
	//�ֳ��������䷶Χֵ
	int left1 = begin, right1 = mid;
	int left2 = mid + 1, right2 = end;
	int i = begin;
	//�ж����������ֵ˭��С
	while (left1 <= right1 && left2 <= right2) {
		if (arr[left1] < arr[left2]) {
			tmp[i++] = arr[left1++];
		}
		else {
			tmp[i++] = arr[left2++];
		}
	}
	//�κ�һ�������������ʣ���ֱ��β��
	while (left1 <= right1) {
		tmp[i++] = arr[left1++];
	}
	while (left2 <= right2) {
		tmp[i++] = arr[left2++];
	}

	//������õ�tmp������arr��
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

//��������
void CountSoort(int* arr, size_t size) {
	//�����ֵ����Сֵ
	int min = arr[0], max = arr[0];
	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	//������ʱ��������ͳ�ƴ���
	int range = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * range);
	if (tmp == NULL) {
		perror("malloc() err!");
		return;
	}
	memset(tmp, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (size_t i = 0; i < size; i++)
	{
		tmp[arr[i] - min]++;
	}
	//����
	int j = 0;
	for (size_t i = 0; i < range; i++)
	{
		while (tmp[i]--) {
			arr[j++] = i + min;
		}
	}

}