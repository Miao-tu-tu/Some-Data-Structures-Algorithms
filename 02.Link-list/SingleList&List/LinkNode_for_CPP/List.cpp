#include"List.h"

LTNode* ListInit() {
	//�������ݵ�ͷ��㣬����λָ��ָ�������һ���ڵ�
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(LTNode* phead, LTDataType x) {
	//assert���Է�ֹ���ã���δ����ʼ��ֱ�Ӵ��롣
	assert(phead);
	//ȷ��β�ڵ��뽨���µĽڵ�
	LTNode* tail = phead->prev;
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;

	//���ӹ���
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;

}

void ListPrint(LTNode* phead) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		cout << cur->data;
		cur = cur->next;
	}
	cout << endl;
}

void ListPopBack(LTNode* phead) {
	assert(phead);
	//�Լ�ָ���Լ���˵�����Ѿ����ڱ�λ�ڵ��ˣ���ʱ�����Ѿ�Ϊ��
	assert(phead->next != phead);
	
	LTNode* pTail = phead->prev->prev;
	LTNode* tail = phead->prev;

	pTail->next = phead;
	phead->prev = pTail;

	//freeһ���ڵ㣬��Ὣ�ڵ���ߵ�������Ϊ���ֵ
	free(tail);

}

void ListPushFront(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* cur = phead->next;
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;

	phead->next = newNode;
	newNode->next = cur;

	newNode->prev = phead;
	cur->prev = newNode;

	//ListInsert(phead, x);
}

void ListPopFront(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	LTNode* cur = phead->next;
	LTNode* bCur = phead->next->next;

	phead->next = bCur;
	bCur->prev = phead;
	//ֱ�ӾͿ���ʹ��ListErase
	//ListErase(phead, x);

	free(cur);

}

LTNode* ListFind(LTNode* phead, LTDataType x) {
	assert(phead);
	assert(phead->next);
	ListNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		else {
			cur = cur->next;
		}
		
	}

	return NULL;

}
//������Ϊͷ�塢β��Ĳ��赥Ԫ
void ListInsert(LTNode* pos, LTDataType x) {
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;

	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListErase(LTNode* pos) {
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}

void ListDestroy(LTNode* phead) {	//���ִ���һ���ԣ����ô�������
	//����ʹ��ʱ�����ÿ�(����free��
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}