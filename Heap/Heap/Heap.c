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

void HeapCreate(hp* ph, HpDataType* arr, size_t size) {


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