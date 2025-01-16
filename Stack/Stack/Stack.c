#include "Stack.h"

//初始化栈
void STInit(ST* ps) {
	assert(ps);

	ps->arr = NULL;
	//指向栈顶元素的下一个
	ps->capacity = ps->size = 0;
}

//销毁栈
void STDestory(ST* ps) {
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//压栈
void STPush(ST* ps, STDataType data) {
	assert(ps);

	//空间不够 扩容
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newcapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc() err");
			return;
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//插入数据，有效数据个数加一
	ps->arr[ps->size++] = data;
}

//出栈
void STPop(ST* ps) {
	assert(ps);
	//栈不能为空
	assert(!STEmpty(ps));

	ps->size--;
}

//检查栈是否为空
bool STEmpty(ST* ps) {
	assert(ps);
	//直接判断返回值
	return ps->size == 0;
}

//栈的大小，获取栈中有效元素个数
int STSize(ST* ps) {
	assert(ps);

	return ps->size;
}

//获取栈顶元素
STDataType STTop(ST* ps) {
	assert(ps);
	//栈不能为空
	assert(!STEmpty(ps));

	if (ps->arr == NULL) {
		free(ps->arr);
		return;
	}
	//指向栈顶元素
	return ps->arr[ps->size - 1];
	
}