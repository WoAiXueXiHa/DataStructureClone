#include "Stack.h"

//初始化栈
void StackInit(Stack* ps) {
	//检查指针有效性
	assert(ps);

	ps->arr = NULL;
	ps->capacity = ps->top = 0;//top指向栈顶的后一个元素
}

//数据入栈
void StackPush(Stack* ps, STDataType val) {
	//检查指针有效性
	assert(ps);

	//检查容量并扩容
	if (ps->top == ps->capacity) {
		//原始容量可能为0，需要利用三目操作符判断并扩容
		size_t newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//在堆上开辟新的数组
		STDataType* tmp = (STDataType*)malloc(newCapacity * sizeof(STDataType));
		//检查malloc是否成功
		if (tmp == NULL) {
			perror("malloc err!");
			return;
		}
		ps->capacity = newCapacity;
		ps->arr = tmp;
	}

	ps->arr[ps->top++] = val;

}

//数据出栈
void StackPop(Stack* ps) {
	//检查指针有效性
	assert(ps);
	
	if (!StackEmpty(ps)) {
		ps->top--;
	}
}

//查找栈顶元素
STDataType StackTopVal(Stack* ps) {
	//检查指针有效性
	assert(ps);

	if (!StackEmpty(ps)) {
		return ps->arr[ps->top - 1];
	}

}

//检查栈的有效数据个数
size_t StackSize(Stack* ps) {
	//检查指针有效性
	assert(ps);

	return ps->top;
}

//检查栈是否为空
bool StackEmpty(Stack* ps) {
	//检查指针有效性
	assert(ps);

	return ps->top == 0;
}

//销毁栈
void StackDestory(Stack* ps) {
	//检查指针有效性
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}