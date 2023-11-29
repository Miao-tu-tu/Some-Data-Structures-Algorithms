#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

/*头指针是必须的，但是哨兵位的头结点并不是必需的*/
//不带头的单链表类型

void SListPrint(SLTNode* phead);
void SListInit(SLTNode* phead);	//直接使用头指针的方法可以不用这个初始化
void SListDestroy(SLTNode** phead);
//增
void SListPushFront(SLTNode** phead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode* phead, SLTDataType x);
void SListInsert(SLTNode** pphead, int index, SLTDataType x); 
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//STL中不用下标查找位置，而是用节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);
void SListErase(SLTNode** pphead, int index);	//下标方法当前删除
void SListErase(SLTNode** pphead, SLTNode* pos);//节点方法找前指针删除
void SListEraseAfter(SLTNode* pos);				//节点方法向后删除
//查
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//改
//有了查找返回节点指针的功能，就可以得出修改的方法
void SListModify(SLTNode* phead, int index, SLTDataType x);
