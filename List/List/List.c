#include "List.h"

//�����µĽڵ�
ListNode* ListNewNode(LTDataType input) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		perror("malloc() err!");
		return 1;
	}
	newNode->data = input;
	newNode->next = newNode->prev = newNode;
}

// ��ʼ������
ListNode* ListInit() {
	ListNode* phead = ListNewNode(-1);
	return phead;
}

// ˫����������
void ListDestory(ListNode* plist) {
	assert(plist);

	ListNode* pcur = plist->next;
	while (pcur != plist) {
		ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//ֻʣ���ڱ�λ��
	free(plist);
	plist = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* plist) {
	assert(plist);

	ListNode* pcur = plist->next;
	while (pcur != plist) {
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType input) {
	assert(plist);
	ListNode* newNode = ListNewNode(input);
	ListNode* pcur = plist->next;

	newNode->next = plist;
	newNode->prev = plist->prev;

	plist->prev->next = newNode;
	plist->prev = newNode;
}

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType input) {
	assert(plist);

	ListNode* newNode = ListNewNode(input);

	newNode->next = plist->next;
	newNode->prev = plist;

	plist->next->prev = newNode;
	plist->next = newNode;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType input) {
	assert(pos);

	ListNode* newNode = ListNewNode(input);

	newNode->next = pos;
	newNode->prev = pos->prev;

	pos->prev->next = newNode;//������˳���ܴ�
	pos->prev = newNode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* plist) {
	assert(plist->next != plist);//������Ϊ��

	ListNode* del = plist->next;
	ListNode* next = del->next;

	next->prev = plist;
	plist->next = next;//˳���ܴ�

	free(del);
	del = NULL;
}

// ˫������βɾ
void ListPopBack(ListNode* plist) {
	assert(plist->prev != plist);

	ListNode* del = plist->prev;
	ListNode* prev = del->prev;

	prev->next = plist;
	plist->prev = prev;
	
	free(del);
	del = NULL;
}

// ˫������ɾ��posλ�õĽ��
void ListErase(ListNode* pos) {
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
	pos = NULL;
}

// ˫���������
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