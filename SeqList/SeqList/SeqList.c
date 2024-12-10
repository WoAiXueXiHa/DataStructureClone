#include "SeqList.h"

//��ʼ��������
void SeqListInit(SeqList* ps) {
	assert(ps);

	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//����������Ҫ����
void CapacityCheck(SeqList* ps) {
	assert(ps);

	if (ps->capacity == ps->size) {
		size_t newCapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc() err!\n");
			free(tmp);
			return 1;
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

void SeqListDestory(SeqList* ps) {
	assert(ps);

	//��Ϊ��֮ǰ���ȿ��������Ƿ�Ϊ��
	if (ps->arr) {
		free(ps->arr);
		ps->arr;
	}
	ps->capacity = ps->size = 0;
}

//�������
void SeqListPushHead(SeqList* ps, SLDataType input) {
	assert(ps);

	//��������Ƿ����
	CapacityCheck(ps);

	//������ ps->arrһ���пռ� ��ʹps->arr��û��Ԫ�� ��ôsize == 0 ���ǾͲ�����ѭ�� ֱ�Ӳ��뼴��
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];//ps->arr[1] = ps->arr[0]
	}
	ps->arr[0] = input;
	ps->size++;
}

void SeqListPushBack(SeqList* ps, SLDataType input) {
	assert(ps);

	//��������Ƿ����
	CapacityCheck(ps);
	ps->arr[ps->size++] = input;
}

//ָ��λ��֮ǰ����Ԫ��
//��pos���Ժ��Ԫ������Ų������ʱ���൱��pos��Ӧ��Ԫ���ܵ�����һλ�ˣ�������pos֮ǰ����һ��Ԫ��
//�����ָ��posλ�ò���Ԫ���򲻻�Ų����ֱ�Ӹ���posδ֪��Ԫ��
void SeqListPushPos(SeqList* ps, SLDataType input, size_t pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//��������Ƿ����
	CapacityCheck(ps);

	for (size_t i = ps->size - 1; i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];//ps->arr[pos + 1] = ps->[pos]
	}
	ps->arr[pos] = input;
	ps->size++;
}

//ɾ������
void SeqListPopHead(SeqList* ps) {
	assert(ps);
	//˳���Ϊ�ղ���ִ��ɾ������
	assert(ps->size);

	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[size - 2] = ps->arr[size - 1] ���������ڶ����������һ��
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps) {
	assert(ps);
	//˳���Ϊ�ղ���ִ��ɾ������
	assert(ps->size);

	ps->size--;
}
//ɾ��ָ��λ�õ�����
void SeqListPopPos(SeqList* ps, size_t pos) {
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//pos������ size�Ǹ���
	//ֻ��Ҫ��pos���������ǰŲ��
	for (size_t i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//ps->arr[size - 2] = ps->arr[szie - 1];
	}
	ps->size--;
}

//����
int SeqListFind(SeqList* ps, SLDataType target) {
	assert(ps);

	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == target) {
			return target;
			break;
		}
		else {
			printf("δ�ҵ���\n");
			return -1;
		}
	}
}

//��ӡ
void SeqListPrint(SeqList* ps) {

	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


