#include "Heap.h"

void HeapInit(hp* ph) {
	assert(ph);

	ph->arr = NULL;
	ph->size = ph->capacity = 0;
}

void HeapCreate(hp* ph, HpDataType* arr, size_t size) {
	assert(ph);
	//�����鿪�ٿռ�
	ph->arr = (HpDataType*)malloc(sizeof(HpDataType) * size);
	if (ph->arr == NULL) {
		perror("malloc err!");
		return;
	}
	//����������������
	memcpy(ph->arr, arr, sizeof(HpDataType) * size);
	ph->size = ph->capacity = size;

	//�����ѵĹ��̣������һ����Ҷ�ӽڵ㿪ʼ
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(ph->arr, size, i);
	}

}

void HeapDestory(hp* ph) {
	assert(ph);

	free(ph->arr);
	ph->arr;
	ph->capacity = ph->size;
}
//����������ֵ
Swap(HpDataType* pa, HpDataType* pb) {
	HpDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//���ϵ����㷨���������飬������ʼ����Ҷ�ڵ������
AdjustUp(HpDataType* arr, size_t child) {
	//�Ҹ��ڵ�����
	size_t parent = (child - 1) / 2;
	//��������Ҷ�ڵ����Ϊ���ڵ�
	while (child > 0) {
		//���ڵ�С�ڵ����ӽڵ㣬�������ڵ��ֵ
		if (arr[parent] <= arr[child]) {
			Swap(&arr[parent], &arr[child]);
			//�����ӽڵ�������������ӽڵ��Ϊ�µ�
			child = parent;
			//�����ҵ����Ƚ�
			child = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(hp* ph, HpDataType val) {
	assert(ph);
	//�ռ䲻����Ҫ����
	if (ph->size == ph->capacity) {
		//ԭ����Ϊ�㣬�ȸ�һ��HpDataType�Ĵ�С������Ϊ�㣬�����������ݱ���
		HpDataType newCapacity = ph->capacity == 0 ? sizeof(HpDataType) : ph->capacity * 2;
		//��������µĿռ�
		HpDataType* tmp = (HpDataType*)realloc(ph->arr, sizeof(HpDataType) * newCapacity);
		if (tmp == NULL) {
			perror("realloc err!");
			return;
		}
		//���������Ϳռ�
		ph->capacity = newCapacity;
		ph->arr = tmp;
	}
	//��ѵײ���Ԫ�أ��ѵ�Ԫ��������һ
	ph->arr[ph->size++] = val;
	//��ʱ�ѵĽṹ���ܱ��ƻ������ϵ����㷨�޸��ѵĽṹ
	AdjustUp(ph->arr, ph->size - 1);
}

//���µ����㷨������������ ����Ԫ�ظ��� ��ʼ���µ����ĸ��ڵ�����
AdjustDown(HpDataType* arr, size_t size, size_t parent) {
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

void HeapPop(hp* ph) {
	assert(ph);
	
	//���ѵ�Ԫ���Ƶ��Ѷ����Ѷ�Ԫ��ֵ������
	ph->arr[0] = ph->arr[ph->size - 1];
	//ɾ���ѵ�Ԫ��
	ph->size--;
	//�ѵĽṹ���ƻ������µ����㷨�޸��ѵĽṹ
	AdjustDown(ph->arr, ph->size, 0);
}

HpDataType HeapTop(hp* ph) {
	assert(ph);

	return ph->arr[0];
}


bool HeapEmpty(hp* ph) {
	assert(ph);

	return ph->size == 0;
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

void DataCreate()
{
	// ������
	int n = 99;
	srand(time(0));
	FILE* fp = fopen("D:\CODE\DataStructure\DataStructureClone\Heap\data.x", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 99;
		fprintf(fp, "%d\n", x);
	}

	fclose(fp);
}

void HeapTopK() {
	//����ָ��
	printf("������k:");
	int k = 0;
	scanf_s("%d", &k);

	//�����������
	DataCreate();

	//��ȡ�ļ���k������
	FILE* fout = fopen("D:\CODE\DataStructure\DataStructureClone\Heap\data.x", "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	int val = 0;
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc error");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf_s(fout, "%d", &minheap[i]);
	}
	//����С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}

	int x = 0;
	while (fscanf_s(fout, "%d", &x) != EOF)
	{
		// ��ȡʣ�����ݣ��ȶѶ���ֵ�󣬾��滻������
		if (x > minheap[0])
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}

	fclose(fout);
}
