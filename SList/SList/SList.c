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

/****************************************�������********************************************/
//ͷ��
void SLTPushHead(SLTNode** pplist, SLDataType input) {
	//������ָ���Ƿ���Ч
	assert(pplist);

	SLTNode* newNode = SLTBuyNode(input);

	newNode->next = *pplist;
	*pplist = newNode;			
}
//β��
void SLTPushBack(SLTNode** pplist, SLDataType input) {
	//������ָ���Ƿ���Ч
	assert(pplist);

	SLTNode* newNode = SLTBuyNode(input);
	SLTNode* ptail = *pplist;
	//����Ϊ�� �½ڵ����β�ڵ�
	if (*pplist == NULL) {
		ptail = newNode;
		return;
	}
	//����Ϊ�� ��β�ڵ�
	while (ptail->next) {
		ptail = ptail->next;
	}
	ptail->next = newNode;
}

//ָ��λ��֮ǰ����Ԫ��
void SLTPushPosFront(SLTNode** pplist, SLTNode* pos, SLDataType input) {
	assert(pplist);
	assert(pos);
	assert(*pplist);

	//pos�պ��ǵ�һ���ڵ� ͷ��
	if (pos == *pplist) {
		SLTPushHead(pplist, input);
		return;
	}

	//pos���ǵ�һ���ڵ� ��pos��ǰ���ڵ�
	SLTNode* newNode = SLTBuyNode(input);
	SLTNode* prev = *pplist;
	while (prev != NULL && prev->next != pos) {
		prev = prev->next;
	}
	// ����жϣ����Ƿ��ҵ���pos��ǰ���ڵ�
	if (prev == NULL) {
		// ˵��û�ҵ�pos������pos�����ڸ��������Ը��ݾ���������д�����������ͷŸ�����Ľڵ㲢����
		free(newNode);
		return;
	}
	newNode->next = pos;
	prev->next = newNode;
}
//ָ��λ��֮�����Ԫ��
void SLTPushPosAfter(SLTNode* pos, SLDataType input) {
	//ֻ��Ҫ�ҵ�pos��λ�ü��� pos֮ǰ�Ľڵ����迼��
	assert(pos);
	SLTNode* newNode = SLTBuyNode(input);

	newNode->next = pos->next;
	pos->next = newNode;
}



/****************************************�������********************************************/


/****************************************ɾ������********************************************/

//βɾ
void SLTPopBack(SLTNode** pplist) {
	//������ָ���Ƿ���Ч
	assert(pplist);
	//������Ϊ�� ��������ִ��ɾ������
	assert(*pplist);

	//����Ϊ��
	// ֻ��һ���ڵ�
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//�ж���ڵ�
	//��β ����ǰ���ڵ�
	SLTNode* ptail = *pplist;
	SLTNode* prev = NULL;
	while (ptail->next) {
		prev = ptail;
		ptail = ptail->next;
	}
	//����β�ڵ�
	prev->next = NULL;
	free(ptail);
	ptail = NULL;
}

//ͷɾ
void SLTPoplist(SLTNode** pplist) {
	//������ָ���Ƿ���Ч
	assert(pplist);
	//������Ϊ�� ��������ִ��ɾ������
	assert(*pplist);
	//�ѵڶ����ڵ㵱����һ���ڵ� �ͷŵ�һ���ڵ�
	SLTNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}

//ɾ��ָ��λ��֮���һ��Ԫ��
void SLTPopPosAfter(SLTNode* pos) {
	assert(pos);
	assert(pos->next);

	SLTNode* del = pos->next;
	pos->next =del->next;
	free(del);
	del = NULL;
}

//ɾ��ָ��λ��Ԫ��
void SLTPopPos(SLTNode** pplist, SLTNode* pos) {
	assert(pplist);
	assert(pos);
	assert(*pplist);

	//pos�պ��ڵ�һ���ڵ�λ��
	if (pos == *pplist) {
		//ͷɾ
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

/****************************************ɾ������********************************************/


//�����ӡ
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


//���������
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


