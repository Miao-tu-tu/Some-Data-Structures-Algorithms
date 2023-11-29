#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);

void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListInsertAfter(SLTNode** phead, SLTNode* prevPos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode** pphead, SLTNode* prevPos);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);

SLTNode* BuySListNode(SLTDataType x);