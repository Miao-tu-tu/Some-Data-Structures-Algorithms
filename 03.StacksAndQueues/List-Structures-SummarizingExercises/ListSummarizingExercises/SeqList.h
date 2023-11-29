#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SeqLDataType;
typedef struct SeqList {
	SeqLDataType* arr;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPushFront(SL* ps, SeqLDataType x);
void SeqListPushBack(SL* ps, SeqLDataType x);
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);
int SeqListFind(SL* ps, SeqLDataType x);
void SeqListInsert(SL* ps, int pos, SeqLDataType x);
void SeqListErase(SL* ps, int pos);

void SeqListCheakCapacity(SL* ps);
void SeqListPrint(SL* ps);
