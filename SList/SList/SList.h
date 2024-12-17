#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//不带头不循环单向链表
typedef int SLDataType;
typedef struct SListNdoe {
	SLDataType data;
	struct Listnode* next;
}SLTNode;

//链表的销毁
void SLTDestory(SLTNode** pplist);

//插入操作
void SLTPushHead(SLTNode** pplist, SLDataType input);
void SLTPushBack(SLTNode** pplist, SLDataType input);
//指定位置之前插入元素
void SLTPushPosFront(SLTNode** pplist, SLTNode* pos,SLDataType input);
//指定位置之后插入元素
void SLTPushPosAfter(SLTNode* pos,SLDataType input);

//删除操作
void SLTPopBack(SLTNode** pplist);
void SLTPoplist(SLTNode** pplist);
//删除指定位置之后的一个元素
void SLTPopPosAfter(SLTNode* pos);
//删除指定位置元素
void SLTPopPos(SLTNode** pplist, SLTNode* pos);

//查找元素
SLTNode* SLTFind(SLTNode* plist, SLDataType target);

//链表打印
void SLTPrint(SLTNode* plist);

//创建新的节点
SLTNode* SLTBuyNode(SLDataType input);



