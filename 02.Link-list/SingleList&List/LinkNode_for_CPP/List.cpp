#include"List.h"

LTNode* ListInit() {
	//不带数据的头结点，是首位指针指向自身的一个节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(LTNode* phead, LTDataType x) {
	//assert可以防止误用，即未经初始化直接传入。
	assert(phead);
	//确定尾节点与建立新的节点
	LTNode* tail = phead->prev;
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;

	//链接过程
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
	//自己指向自己就说明它已经到哨兵位节点了，此时链表已经为空
	assert(phead->next != phead);
	
	LTNode* pTail = phead->prev->prev;
	LTNode* tail = phead->prev;

	pTail->next = phead;
	phead->prev = pTail;

	//free一个节点，则会将节点里边的内容置为随机值
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
	//直接就可以使用ListErase
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
//可以作为头插、尾插的步骤单元
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

void ListDestroy(LTNode* phead) {	//保持代码一致性，不用传二级，
	//可在使用时进行置空(类似free）
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