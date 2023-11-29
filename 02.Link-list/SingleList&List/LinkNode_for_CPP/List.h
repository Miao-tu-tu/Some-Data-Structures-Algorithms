#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
/*
	��ͷ˫��ѭ������

*/

typedef int LTDataType;

typedef struct ListNode {
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* ListInit();
void ListPushBack(LTNode* phead, LTDataType x);
void ListPrint(LTNode* phead);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopFront(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDataType x);
//posλ��֮ǰ����
void ListInsert(LTNode* pos, LTDataType x);
//ɾ��posλ��
void ListErase(LTNode* pos);
void ListDestroy(LTNode* phead);

