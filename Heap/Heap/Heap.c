#include "Heap.h"

void HeapInit(hp* ph) {
	assert(ph);

	ph->arr = NULL;
	ph->size = ph->capacity = 0;
}

void HeapCreate(hp* ph, HpDataType* arr, size_t size) {
	assert(ph);
	//给数组开辟空间
	ph->arr = (HpDataType*)malloc(sizeof(HpDataType) * size);
	if (ph->arr == NULL) {
		perror("malloc err!");
		return;
	}
	//拷贝传过来的数组
	memcpy(ph->arr, arr, sizeof(HpDataType) * size);
	ph->size = ph->capacity = size;

	//调整堆的过程，从最后一个非叶子节点开始
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
//交换两数的值
Swap(HpDataType* pa, HpDataType* pb) {
	HpDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//向上调整算法，参数数组，参数开始调整叶节点的索引
AdjustUp(HpDataType* arr, size_t child) {
	//找父节点索引
	size_t parent = (child - 1) / 2;
	//最坏的情况，叶节点调整为根节点
	while (child > 0) {
		//父节点小于等于子节点，交换两节点的值
		if (arr[parent] <= arr[child]) {
			Swap(&arr[parent], &arr[child]);
			//跟新子节点的索引，现在子节点变为新爹
			child = parent;
			//继续找爹作比较
			child = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void HeapPush(hp* ph, HpDataType val) {
	assert(ph);
	//空间不够需要扩容
	if (ph->size == ph->capacity) {
		//原容量为零，先给一个HpDataType的大小，若不为零，采用两倍扩容比例
		HpDataType newCapacity = ph->capacity == 0 ? sizeof(HpDataType) : ph->capacity * 2;
		//向堆申请新的空间
		HpDataType* tmp = (HpDataType*)realloc(ph->arr, sizeof(HpDataType) * newCapacity);
		if (tmp == NULL) {
			perror("realloc err!");
			return;
		}
		//更新容量和空间
		ph->capacity = newCapacity;
		ph->arr = tmp;
	}
	//向堆底插入元素，堆的元素数量加一
	ph->arr[ph->size++] = val;
	//此时堆的结构可能被破坏，向上调整算法修复堆的结构
	AdjustUp(ph->arr, ph->size - 1);
}

//向下调整算法，参数：数组 数组元素个数 开始向下调整的父节点索引
AdjustDown(HpDataType* arr, size_t size, size_t parent) {
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

void HeapPop(hp* ph) {
	assert(ph);
	
	//将堆底元素移到堆顶，堆顶元素值被覆盖
	ph->arr[0] = ph->arr[ph->size - 1];
	//删除堆底元素
	ph->size--;
	//堆的结构被破坏，向下调整算法修复堆的结构
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

void DataCreate()
{
	// 造数据
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
	//输入指令
	printf("请输入k:");
	int k = 0;
	scanf_s("%d", &k);

	//创建随机数据
	DataCreate();

	//读取文件中k个数据
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
	//创建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}

	int x = 0;
	while (fscanf_s(fout, "%d", &x) != EOF)
	{
		// 读取剩余数据，比堆顶的值大，就替换他进堆
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
