#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//定义一个栈
typedef int STDataType;
typedef struct Stack {
	size_t top;//栈顶
	size_t capacity;//容量
	STDataType* arr;//大小可变的数组
}Stack;

//初始化栈
void StackInit(Stack* ps);

//数据入栈
void StackPush(Stack* ps, STDataType val);

//数据出栈
void StackPop(Stack* ps);

//查找栈顶元素
STDataType StackTopVal(Stack* ps);

//检查栈的有效数据个数
size_t StackSize(Stack* ps);

//检查栈是否为空
bool StackEmpty(Stack* ps);

//销毁栈
void StackDestory(Stack* ps);