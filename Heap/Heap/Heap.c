#include "Heap.h"

void HeapInit(hp* ph) {
	assert(ph);

	ph->arr = NULL;
	ph->capacity = ph->size = 0;
}

void Swap(HpDataType* a, HpDataType* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustUp(HpDataType* arr, size_t child) {
	size_t parent = (child - 1) / 2;
	while (child > 0) {
		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}

}

void AdjustDown(HpDataType* arr,size_t size, size_t parent) {
	size_t child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && arr[child + 1] < arr[child]) {
			child++;
		}

		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = parent * 2 + 1;
		}
		else {
			break;
		}

	}

}
void HeapPush(hp* ph, HpDataType val) {
	assert(ph);

	//¿Õ¼ä²»¹»À©ÈÝ
	if (ph->size == ph->capacity) {
		size_t newCapacity = ph->capacity == 0 ? 4 : 2 * ph->capacity;
		hp* tmp = (hp*)realloc(ph->arr, sizeof(hp) * newCapacity);
		if (tmp == NULL) {
			perror("realloc error!");
			return;
		}
		ph->arr = tmp;
		ph->capacity = newCapacity;
	}
	ph->arr[ph->size++] = val;
	AdjustUp(ph->arr, ph->size - 1);

}
void HeapPop(hp* ph) {
	assert(ph);

	ph->arr[ph->size - 1] = ph->arr[0];
	ph->size--;

	AdjustDown(ph->arr, ph->size, 0);
}
HpDataType HeapTop(hp* ph) {
	assert(ph);

	return ph->arr[0];
}
void HeapDestory(hp* ph) {
	assert(ph);

	free(ph->arr);
	ph->arr = NULL;
	ph->size = ph->capacity = 0;
}
bool HeapEmpty(hp* ph) {
	assert(ph);

	return ph->size == 0;
}