#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;
//���嶯̬˳���
typedef struct SeqList {
	SLDataType* arr;
	size_t size;//˳�����Ч���ݸ���
	size_t capacity;//˳�������
}SeqList;

//��ʼ��������
void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

//�������
void SeqListPushHead(SeqList* ps, SLDataType input);
void SeqListPushBack(SeqList* ps, SLDataType input);
void SeqListPushPos(SeqList* ps, SLDataType input, size_t pos);

//ɾ������
void SeqListPopHead(SeqList* ps);
void SeqListPopBack(SeqList* ps);
void SeqListPopPos(SeqList* ps, size_t pos);

//����
int SeqListFind(SeqList* ps, SLDataType target);

//��ӡ
void SeqListPrint(SeqList* ps);

//����������Ҫ����
void CapacityCheck(SeqList* ps);




