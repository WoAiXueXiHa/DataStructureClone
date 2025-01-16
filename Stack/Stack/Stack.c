#include "Stack.h"

//��ʼ��ջ
void STInit(ST* ps) {
	assert(ps);

	ps->arr = NULL;
	//ָ��ջ��Ԫ�ص���һ��
	ps->capacity = ps->size = 0;
}

//����ջ
void STDestory(ST* ps) {
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//ѹջ
void STPush(ST* ps, STDataType data) {
	assert(ps);

	//�ռ䲻�� ����
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newcapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc() err");
			return;
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	//�������ݣ���Ч���ݸ�����һ
	ps->arr[ps->size++] = data;
}

//��ջ
void STPop(ST* ps) {
	assert(ps);
	//ջ����Ϊ��
	assert(!STEmpty(ps));

	ps->size--;
}

//���ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps) {
	assert(ps);
	//ֱ���жϷ���ֵ
	return ps->size == 0;
}

//ջ�Ĵ�С����ȡջ����ЧԪ�ظ���
int STSize(ST* ps) {
	assert(ps);

	return ps->size;
}

//��ȡջ��Ԫ��
STDataType STTop(ST* ps) {
	assert(ps);
	//ջ����Ϊ��
	assert(!STEmpty(ps));

	if (ps->arr == NULL) {
		free(ps->arr);
		return;
	}
	//ָ��ջ��Ԫ��
	return ps->arr[ps->size - 1];
	
}