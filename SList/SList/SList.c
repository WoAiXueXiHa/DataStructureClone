#include "SList.h"

SLTNode* SLTBuyNode(SLDataType input) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {
		perror("malloc() err!");
		return;
	}
	newNode->data = input;
	newNode->next = NULL;

	return newNode;
}

/****************************************插入操作********************************************/
//头插
void SLTPushHead(SLTNode** pplist, SLDataType input) {
	//检查二级指针是否有效
	assert(pplist);

	SLTNode* newNode = SLTBuyNode(input);

	newNode->next = *pplist;
	*pplist = newNode;			
}
//尾插
void SLTPushBack(SLTNode** pplist, SLDataType input) {
	//检查二级指针是否有效
	assert(pplist);

	SLTNode* newNode = SLTBuyNode(input);
	SLTNode* ptail = *pplist;
	//链表为空 新节点就是尾节点
	if (*pplist == NULL) {
		ptail = newNode;
		return;
	}
	//链表不为空 找尾节点
	while (ptail->next) {
		ptail = ptail->next;
	}
	ptail->next = newNode;
}

//指定位置之前插入元素
void SLTPushPosFront(SLTNode** pplist, SLTNode* pos, SLDataType input) {
	assert(pplist);
	assert(pos);
	assert(*pplist);

	//pos刚好是第一个节点 头插
	if (pos == *pplist) {
		SLTPushHead(pplist, input);
		return;
	}

	//pos不是第一个节点 找pos的前驱节点
	SLTNode* newNode = SLTBuyNode(input);
	SLTNode* prev = *pplist;
	while (prev != NULL && prev->next != pos) {
		prev = prev->next;
	}
	// 添加判断，看是否找到了pos的前驱节点
	if (prev == NULL) {
		// 说明没找到pos，可能pos不属于该链表，可以根据具体需求进行错误处理，这里简单释放刚申请的节点并返回
		free(newNode);
		return;
	}
	newNode->next = pos;
	prev->next = newNode;
}
//指定位置之后插入元素
void SLTPushPosAfter(SLTNode* pos, SLDataType input) {
	//只需要找到pos的位置即可 pos之前的节点无需考虑
	assert(pos);
	SLTNode* newNode = SLTBuyNode(input);

	newNode->next = pos->next;
	pos->next = newNode;
}



/****************************************插入操作********************************************/


/****************************************删除操作********************************************/

//尾删
void SLTPopBack(SLTNode** pplist) {
	//检查二级指针是否有效
	assert(pplist);
	//链表不能为空 空链表不能执行删除操作
	assert(*pplist);

	//链表不为空
	// 只有一个节点
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//有多个节点
	//找尾 保存前驱节点
	SLTNode* ptail = *pplist;
	SLTNode* prev = NULL;
	while (ptail->next) {
		prev = ptail;
		ptail = ptail->next;
	}
	//销毁尾节点
	prev->next = NULL;
	free(ptail);
	ptail = NULL;
}

//头删
void SLTPoplist(SLTNode** pplist) {
	//检查二级指针是否有效
	assert(pplist);
	//链表不能为空 空链表不能执行删除操作
	assert(*pplist);
	//把第二个节点当作第一个节点 释放第一个节点
	SLTNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}

//删除指定位置之后的一个元素
void SLTPopPosAfter(SLTNode* pos) {
	assert(pos);
	assert(pos->next);

	SLTNode* del = pos->next;
	pos->next =del->next;
	free(del);
	del = NULL;
}

//删除指定位置元素
void SLTPopPos(SLTNode** pplist, SLTNode* pos) {
	assert(pplist);
	assert(pos);
	assert(*pplist);

	//pos刚好在第一个节点位置
	if (pos == *pplist) {
		//头删
		SLTPoplist(pplist);
		return;
	}
	SLTNode* prev = *pplist;
	while (prev != NULL && prev->next != pos) {
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;

}

/****************************************删除操作********************************************/


//链表打印
void SLTPrint(SLTNode* plist) {
	SLTNode* pcur = plist;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTFind(SLTNode* plist, SLDataType target) {
	assert(plist);
	SLTNode* pcur = plist;
	while (pcur) {
		if (pcur->data == target) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}


//链表的销毁
void SLTDestory(SLTNode** pplist) {
	assert(pplist);
	assert(*pplist);

	SLTNode* del = *pplist;
	while (del) {
		SLTNode* pcur = del;
		free(pcur);
		del = del->next;
	}
	*pplist = NULL;
}


