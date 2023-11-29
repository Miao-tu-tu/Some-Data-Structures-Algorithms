#pragma once

#define N 100
typedef int SLDataType;
//使用typedef进行数据类型的重命名
//静态顺序表
//静态特点：如果满了就不让插入  缺点给多少不好确定
typedef struct SeqList//使用typedef进行结构体的重命名
{
	SLDataType a[N];
	int size;	//表示数组中存储了多少个数据
}SL;

//线性表初始化
void SeqListInit(SL* ps, SLDataType x);
//尾插
void SeqListPushBack(SL* ps, SLDataType x);
//尾删
void SeqListPopBack(SL* ps);
//头插
void SeqListPushFront(SL* ps, SLDataType x);
//头删
void SeqListPopFront(SL* ps);