#include "Stack.h"

//��ʼ��ջ
void StackInit(Stack* ps) {
	//���ָ����Ч��
	assert(ps);

	ps->arr = NULL;
	ps->capacity = ps->top = 0;//topָ��ջ���ĺ�һ��Ԫ��
}

//������ջ
void StackPush(Stack* ps, STDataType val) {
	//���ָ����Ч��
	assert(ps);

	//�������������
	if (ps->top == ps->capacity) {
		//ԭʼ��������Ϊ0����Ҫ������Ŀ�������жϲ�����
		size_t newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//�ڶ��Ͽ����µ�����
		STDataType* tmp = (STDataType*)malloc(newCapacity * sizeof(STDataType));
		//���malloc�Ƿ�ɹ�
		if (tmp == NULL) {
			perror("malloc err!");
			return;
		}
		ps->capacity = newCapacity;
		ps->arr = tmp;
	}

	ps->arr[ps->top++] = val;

}

//���ݳ�ջ
void StackPop(Stack* ps) {
	//���ָ����Ч��
	assert(ps);
	
	if (!StackEmpty(ps)) {
		ps->top--;
	}
}

//����ջ��Ԫ��
STDataType StackTopVal(Stack* ps) {
	//���ָ����Ч��
	assert(ps);

	if (!StackEmpty(ps)) {
		return ps->arr[ps->top - 1];
	}

}

//���ջ����Ч���ݸ���
size_t StackSize(Stack* ps) {
	//���ָ����Ч��
	assert(ps);

	return ps->top;
}

//���ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps) {
	//���ָ����Ч��
	assert(ps);

	return ps->top == 0;
}

//����ջ
void StackDestory(Stack* ps) {
	//���ָ����Ч��
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}