#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode {
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;
}LTNode;

LTNode* ListInit();
void ListDestroy(LTNode* phead);

void ListPushFront(LTNode* phead, LTDataType x);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);
void ListPopBack(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDataType x);
void ListInsert(LTNode* phead, LTNode* pos, LTDataType x);
void ListErase(LTNode* phead, LTNode* pos);

LTNode* BuyListNode(LTDataType x);
void ListPrint(LTNode* phead);