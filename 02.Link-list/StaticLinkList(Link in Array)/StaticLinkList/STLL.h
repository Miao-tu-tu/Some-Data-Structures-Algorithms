#pragma once
/*
* ��̬�����ʵ�ַ���
* �������������ʵ�ַ���
* 1.ʹ���α꣨����Ԫ���±���Ϣ������ָ�룬ʵ����ʽ�洢��Ч����
* 2.��ʼʱ�����С�̶�
* 3.�����л�δ��ʹ�õ�Ԫ��λ�ó�Ϊ��������
* 4.�����һ��Ԫ�ش洢���α���ϢΪ���������һ��Ԫ���±�
* 5.�������һ��Ԫ�ش洢���α���ϢΪ��һ�����������Ԫ�ص��±�
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

