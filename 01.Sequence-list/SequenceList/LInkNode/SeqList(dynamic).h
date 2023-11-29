#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;
	int size;		//��ʾ�����д洢�˶��ٸ���	��
	int capacity;	//����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;

void SeqListPrint(SL* ps);

//�ӿں��� --
void SeqListInit(SL* ps);			//��ʼ�����Ա�
void SeqListDestroy(SL* ps);		//��ֹҰָ����֣���Ҫ����
void SeqListCheckCapacity(SL* ps);	//�������
void SeqListPushBack(SL* ps, SLDataType x);//β�幦��
void SeqListPushFront(SL* ps, SLDataType x);//ͷ�幦��
void SeqListPopBack(SL* ps);		//βɾ����
void SeqListPopFront(SL* ps);		//ͷɾ����
//...

int SeqListFind(SL* ps, SLDataType x);		//����
void SeqListInsert(SL* ps, int pop, SLDataType x);//ָ��λ�ò���
void SeqListErase(SL* ps, int pos);			//ָ��λ��ɾ��