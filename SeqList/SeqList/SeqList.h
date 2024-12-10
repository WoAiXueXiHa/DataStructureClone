#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;
//定义动态顺序表
typedef struct SeqList {
	SLDataType* arr;
	size_t size;//顺序表有效数据个数
	size_t capacity;//顺序表容量
}SeqList;

//初始化和销毁
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

//插入操作
void SeqListPushHead(SeqList* ps, SLDataType input);
void SeqListPushBack(SeqList* ps, SLDataType input);
void SeqListPushPos(SeqList* ps, SLDataType input, size_t pos);

//删除操作
void SeqListPopHead(SeqList* ps);
void SeqListPopBack(SeqList* ps);
void SeqListPopPos(SeqList* ps, size_t pos);

//查找
int SeqListFind(SeqList* ps, SLDataType target);

//打印
void SeqListPrint(SeqList* ps);

//容量不够需要扩容
void CapacityCheck(SeqList* ps);




