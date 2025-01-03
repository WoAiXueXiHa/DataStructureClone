#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;//指向后继节点
	struct ListNode* prev;//指向前驱节点
}ListNode;

//创建新的节点
ListNode* ListNewNode(LTDataType input);
// 初始化链表
ListNode* ListInit();
// 双向链表销毁
void ListDestory(ListNode* plist);
// 双向链表打印
void ListPrint(ListNode* plist);
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType input);
// 双向链表尾删
void ListPopBack(ListNode* plist);
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType input);
// 双向链表头删
void ListPopFront(ListNode* plist);
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType target);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType input);
// 双向链表删除pos位置的结点
void ListErase(ListNode* pos);
