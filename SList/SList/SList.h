#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//����ͷ��ѭ����������
typedef int SLDataType;
typedef struct SListNdoe {
	SLDataType data;
	struct Listnode* next;
}SLTNode;

//���������
void SLTDestory(SLTNode** pplist);

//�������
void SLTPushHead(SLTNode** pplist, SLDataType input);
void SLTPushBack(SLTNode** pplist, SLDataType input);
//ָ��λ��֮ǰ����Ԫ��
void SLTPushPosFront(SLTNode** pplist, SLTNode* pos,SLDataType input);
//ָ��λ��֮�����Ԫ��
void SLTPushPosAfter(SLTNode* pos,SLDataType input);

//ɾ������
void SLTPopBack(SLTNode** pplist);
void SLTPoplist(SLTNode** pplist);
//ɾ��ָ��λ��֮���һ��Ԫ��
void SLTPopPosAfter(SLTNode* pos);
//ɾ��ָ��λ��Ԫ��
void SLTPopPos(SLTNode** pplist, SLTNode* pos);

//����Ԫ��
SLTNode* SLTFind(SLTNode* plist, SLDataType target);

//�����ӡ
void SLTPrint(SLTNode* plist);

//�����µĽڵ�
SLTNode* SLTBuyNode(SLDataType input);



