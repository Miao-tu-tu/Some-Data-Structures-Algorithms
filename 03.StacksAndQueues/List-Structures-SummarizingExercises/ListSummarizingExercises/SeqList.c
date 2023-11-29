#include"SeqList.h"

void SeqListInit(SL* ps) {
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestroy(SL* ps) {
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPushFront(SL* ps, SeqLDataType x) {
	SeqListCheakCapacity(ps);

	int end = ps->size;
	while (end > 0) {
		ps->arr[end] = ps->arr[end - 1];
		end--;
	}

	ps->arr[0] = x;
	ps->size++;

}

void SeqListPushBack(SL* ps, SeqLDataType x) {
	SeqListCheakCapacity(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps) {
	assert(ps);
	int begin = 1;
	while (begin < ps->size) {
		ps->arr[begin - 1] = ps->arr[begin];
		begin++;
	}

	ps->size--;
}

void SeqListPopBack(SL* ps) {
	assert(ps);

	ps->size--;
}

int SeqListFind(SL* ps, SeqLDataType x) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (ps->arr[i] == x) {
			return i + 1;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SeqLDataType x) {
	assert(pos > 0);


	SeqListCheakCapacity(ps);
	int end = ps->size;
	while (end >= pos) {
		ps->arr[end] = ps->arr[end - 1];
		end--;
	}

	ps->arr[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos) {
	assert(ps && pos > 0);

	int begin = pos;
	while (begin < ps->size) {
		ps->arr[begin - 1] = ps->arr[begin];
		begin++;
	}

	ps->size--;
}

void SeqListCheakCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqLDataType* newArr = (SeqLDataType*)realloc(ps->arr, sizeof(SeqLDataType) * newCapacity);
		ps->capacity = newCapacity;
		ps->arr = newArr;
	}
}

void SeqListPrint(SL* ps) {
	int end = ps->size;
	printf("[");

	for (int i = 0; i < end; i++) {
		printf("%d", ps->arr[i]);
		if (i != end - 1)
		{
			printf(", ");
		}
	}
	printf("]\n");

}

