#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;//ָ���̽ڵ�
	struct ListNode* prev;//ָ��ǰ���ڵ�
}ListNode;

//�����µĽڵ�
ListNode* ListNewNode(LTDataType input);
// ��ʼ������
ListNode* ListInit();
// ˫����������
void ListDestory(ListNode* plist);
// ˫�������ӡ
void ListPrint(ListNode* plist);
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType input);
// ˫������βɾ
void ListPopBack(ListNode* plist);
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType input);
// ˫������ͷɾ
void ListPopFront(ListNode* plist);
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType target);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType input);
// ˫������ɾ��posλ�õĽ��
void ListErase(ListNode* pos);
