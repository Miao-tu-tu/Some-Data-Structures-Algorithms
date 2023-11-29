#pragma once
/*
* 静态链表的实现方法
* 基于数组的链表实现方法
* 1.使用游标（数组元素下标信息）代替指针，实现链式存储的效果。
* 2.初始时数组大小固定
* 3.数组中还未被使用的元素位置称为备用链表
* 4.数组第一个元素存储的游标信息为备用链表的一个元素下标
* 5.数组最后一个元素存储的游标信息为第一个插入数组的元素的下标
*/
#include<iostream>
#include<assert.h>
using namespace std;
#define MAXSIZE 1000

typedef int STLLDataType;

typedef struct LinkNode {
	STLLDataType data;
	int index;
}Node;

typedef struct StaticLinkList {
	Node* arr;
}STLL;

void STLListInit(STLL* ps);
void STLListDestroy(STLL* ps);

void STLListPushFront(STLL* ps, STLLDataType x);
void STLListPushBack(STLL* ps, STLLDataType x);
void STLListInsert(STLL* ps, int pos, STLLDataType x);

void STLListPopFront(STLL* ps);
void STLListPopBack(STLL* ps);
void STLListErase(STLL* ps, int pos);

int STLListFind(STLL* ps);

int STLListMalloc(STLL* ps);

