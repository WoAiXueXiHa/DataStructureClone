#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack{
	STDataType* arr;
	int size;
	int capacity;
}ST;

//初始化栈
void STInit(ST* ps);
//销毁栈
void STDestory(ST* ps);
//压栈
void STPush(ST* ps, STDataType data);
//出栈
void STPop(ST* ps);
//检查栈是否为空
bool STEmpty(ST* ps);
//栈的大小，获取栈中有效元素个数
int STSize(ST* ps);
//获取栈顶元素
STDataType STTop(ST* ps);

