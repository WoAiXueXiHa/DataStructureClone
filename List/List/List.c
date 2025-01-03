#include "List.h"

//创建新的节点
ListNode* ListNewNode(LTDataType input) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		perror("malloc() err!");
		return 1;
	}
	newNode->data = input;
	newNode->next = newNode->prev = newNode;
}

// 初始化链表
ListNode* ListInit() {
	ListNode* phead = ListNewNode(-1);
	return phead;
}

// 双向链表销毁
void ListDestory(ListNode* plist) {
	assert(plist);

	ListNode* pcur = plist->next;
	while (pcur != plist) {
		ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//只剩下哨兵位了
	free(plist);
	plist = NULL;
}

// 双向链表打印
void ListPrint(ListNode* plist) {
	assert(plist);

	ListNode* pcur = plist->next;
	while (pcur != plist) {
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType input) {
	assert(plist);
	ListNode* newNode = ListNewNode(input);
	ListNode* pcur = plist->next;

	newNode->next = plist;
	newNode->prev = plist->prev;

	plist->prev->next = newNode;
	plist->prev = newNode;
}

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType input) {
	assert(plist);

	ListNode* newNode = ListNewNode(input);

	newNode->next = plist->next;
	newNode->prev = plist;

	plist->next->prev = newNode;
	plist->next = newNode;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType input) {
	assert(pos);

	ListNode* newNode = ListNewNode(input);

	newNode->next = pos;
	newNode->prev = pos->prev;

	pos->prev->next = newNode;//这两个顺序不能错
	pos->prev = newNode;
}

// 双向链表头删
void ListPopFront(ListNode* plist) {
	assert(plist->next != plist);//链表不能为空

	ListNode* del = plist->next;
	ListNode* next = del->next;

	next->prev = plist;
	plist->next = next;//顺序不能错

	free(del);
	del = NULL;
}

// 双向链表尾删
void ListPopBack(ListNode* plist) {
	assert(plist->prev != plist);

	ListNode* del = plist->prev;
	ListNode* prev = del->prev;

	prev->next = plist;
	plist->prev = prev;
	
	free(del);
	del = NULL;
}

// 双向链表删除pos位置的结点
void ListErase(ListNode* pos) {
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
	pos = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType target) {
	assert(plist);

	ListNode* pcur = plist->next;

	while (pcur != plist) {
		if (pcur->data == target) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}