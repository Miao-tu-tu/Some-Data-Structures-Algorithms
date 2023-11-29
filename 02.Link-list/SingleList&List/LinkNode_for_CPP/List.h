#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
/*
	带头双向循环链表

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
//pos位置之前插入
void ListInsert(LTNode* pos, LTDataType x);
//删除pos位置
void ListErase(LTNode* pos);
void ListDestroy(LTNode* phead);

