#pragma once

#define N 100
typedef int SLDataType;
//ʹ��typedef�����������͵�������
//��̬˳���
//��̬�ص㣺������˾Ͳ��ò���  ȱ������ٲ���ȷ��
typedef struct SeqList//ʹ��typedef���нṹ���������
{
	SLDataType a[N];
	int size;	//��ʾ�����д洢�˶��ٸ�����
}SL;

//���Ա��ʼ��
void SeqListInit(SL* ps, SLDataType x);
//β��
void SeqListPushBack(SL* ps, SLDataType x);
//βɾ
void SeqListPopBack(SL* ps);
//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//ͷɾ
void SeqListPopFront(SL* ps);