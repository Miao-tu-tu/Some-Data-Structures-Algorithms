#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;
	int size;		//表示数组中存储了多少个数	据
	int capacity;	//数组实际能存数据的空间容量是多大
}SL;

void SeqListPrint(SL* ps);

//接口函数 --
void SeqListInit(SL* ps);			//初始化线性表
void SeqListDestroy(SL* ps);		//防止野指针出现，需要销毁
void SeqListCheckCapacity(SL* ps);	//检查增容
void SeqListPushBack(SL* ps, SLDataType x);//尾插功能
void SeqListPushFront(SL* ps, SLDataType x);//头插功能
void SeqListPopBack(SL* ps);		//尾删功能
void SeqListPopFront(SL* ps);		//头删功能
//...

int SeqListFind(SL* ps, SLDataType x);		//查找
void SeqListInsert(SL* ps, int pop, SLDataType x);//指定位置插入
void SeqListErase(SL* ps, int pos);			//指定位置删除