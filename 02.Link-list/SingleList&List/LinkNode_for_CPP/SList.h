#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

/*ͷָ���Ǳ���ģ������ڱ�λ��ͷ��㲢���Ǳ����*/
//����ͷ�ĵ���������

void SListPrint(SLTNode* phead);
void SListInit(SLTNode* phead);	//ֱ��ʹ��ͷָ��ķ������Բ��������ʼ��
void SListDestroy(SLTNode** phead);
//��
void SListPushFront(SLTNode** phead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode* phead, SLTDataType x);
void SListInsert(SLTNode** pphead, int index, SLTDataType x); 
void SListInsertAfter(SLTNode* pos, SLTDataType x);
//STL�в����±����λ�ã������ýڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//ɾ
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);
void SListErase(SLTNode** pphead, int index);	//�±귽����ǰɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);//�ڵ㷽����ǰָ��ɾ��
void SListEraseAfter(SLTNode* pos);				//�ڵ㷽�����ɾ��
//��
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��
//���˲��ҷ��ؽڵ�ָ��Ĺ��ܣ��Ϳ��Եó��޸ĵķ���
void SListModify(SLTNode* phead, int index, SLTDataType x);
