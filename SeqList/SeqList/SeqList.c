#include "SeqList.h"

//初始化和销毁
void SeqListInit(SeqList* ps) {
	assert(ps);

	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//容量不够需要扩容
void CapacityCheck(SeqList* ps) {
	assert(ps);

	if (ps->capacity == ps->size) {
		size_t newCapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc() err!\n");
			free(tmp);
			return 1;
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

void SeqListDestory(SeqList* ps) {
	assert(ps);

	//置为空之前，先考虑数组是否为空
	if (ps->arr) {
		free(ps->arr);
		ps->arr;
	}
	ps->capacity = ps->size = 0;
}

//插入操作
void SeqListPushHead(SeqList* ps, SLDataType input) {
	assert(ps);

	//检查容量是否充足
	CapacityCheck(ps);

	//到这里 ps->arr一定有空间 即使ps->arr中没有元素 那么size == 0 我们就不进入循环 直接插入即可
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//ps->arr[1] = ps->arr[0]
	}
	ps->arr[0] = input;
	ps->size++;
}

void SeqListPushBack(SeqList* ps, SLDataType input) {
	assert(ps);

	//检查容量是否充足
	CapacityCheck(ps);
	ps->arr[ps->size++] = input;
}

//指定位置之前插入元素
//将pos及以后的元素往后挪动，此时就相当于pos对应的元素跑到后面一位了，就是往pos之前插入一个元素
//如果在指定pos位置插入元素则不会挪动，直接覆盖pos未知的元素
void SeqListPushPos(SeqList* ps, SLDataType input, size_t pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//检查容量是否充足
	CapacityCheck(ps);

	for (size_t i = ps->size - 1; i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];//ps->arr[pos + 1] = ps->[pos]
	}
	ps->arr[pos] = input;
	ps->size++;
}

//删除操作
void SeqListPopHead(SeqList* ps) {
	assert(ps);
	//顺序表为空不能执行删除操作
	assert(ps->size);

	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[size - 2] = ps->arr[size - 1] 索引倒数第二个等于最后一个
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps) {
	assert(ps);
	//顺序表为空不能执行删除操作
	assert(ps->size);

	ps->size--;
}
//删除指定位置的数据
void SeqListPopPos(SeqList* ps, size_t pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//pos是索引 size是个数
	//只需要将pos后的数据往前挪动
	for (size_t i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[size - 2] = ps->arr[szie - 1];
	}
	ps->size--;
}

//查找
int SeqListFind(SeqList* ps, SLDataType target) {
	assert(ps);

	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == target) {
			return target;
			break;
		}
		else {
			printf("未找到！\n");
			return -1;
		}
	}
}

//打印
void SeqListPrint(SeqList* ps) {

	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


