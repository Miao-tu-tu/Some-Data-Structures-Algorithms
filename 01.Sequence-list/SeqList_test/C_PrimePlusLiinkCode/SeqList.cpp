#include"SeqList.h"

void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SL* ps) {
	cout << "[";
	for (int i = 0; i < ps->size; i++) {
		cout << ps->a[i];
		if (i != ps->size) {
			cout << ",";
		}
	}
	cout << "]" << endl;
}

void SeqListDestroy(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		int newCapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDataType* temp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newCapacity);
		if (temp == NULL) {
			cout << "realloc error!" << endl;
			exit(-1);
		}

		ps->a = temp;
		ps->capacity = newCapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}

	ps->a[0] = x;
	ps->size++;
}