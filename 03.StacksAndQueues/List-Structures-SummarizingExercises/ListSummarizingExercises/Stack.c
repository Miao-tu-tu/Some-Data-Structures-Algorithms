#include"Stack.h"

void StackInit(ST* ps) {
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void StackDestroy(ST* ps) {
	assert(ps);

	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x) {
	StackCheakCapacity(ps);	//���ʱ����Ҫʹ�õ�ַ����
	//��Ϊ�����������st�Ѿ���һ��ָ�����͵ı�����
	
	if (ps->size == ps->capacity) {
		int newCapacity = (ps->capacity == 0) ? 4 : (ps->capacity) * 2;
		STDataType* newArr = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newCapacity);
		if (newArr) {
			ps->capacity = newCapacity;
			ps->arr = newArr;
		}
		else {
			printf("%, realloc fail");
			exit(-1);
		}
	}
	ps->arr[ps->size] = x;
	ps->size++;
}
void StackPop(ST* st) {
	assert(st);
	assert(st->size > 0);
	st->size--;
}
STDataType StackTop(ST* st) {
	assert(st);
	assert(!StackIsEmpty(st));
	return st->arr[st->size - 1];
}
bool StackIsEmpty(ST* st) {
	return st->size == 0;
}

int StackSize(ST* st) {
	return st->size;
}
void StackCheakCapacity(ST* ps) {
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : (ps->capacity) * 2;
		STDataType* newArr = (STDataType*)realloc(ps->arr, sizeof(STDataType) * newCapacity);
		if (newArr) {
			ps->capacity = newCapacity;
			ps->arr = newArr;
		}
		else {
			printf("%, realloc fail");
			exit(-1);
		}
	}
}

void StackPrint(ST st) {
	while (st.size) {
		printf("%d--", StackTop(&st));
		StackPop(&st);
	}
	printf(" \n");
}
