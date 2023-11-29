#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pop, SLDataType x);
void SeqListErase(SL* ps, int pos);

