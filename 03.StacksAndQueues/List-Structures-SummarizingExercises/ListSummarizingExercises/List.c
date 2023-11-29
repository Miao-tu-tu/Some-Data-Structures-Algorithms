#include"List.h"

LTNode* ListInit() {
	LTNode* header = (LTNode*)malloc(sizeof(LTNode));
	header->prev = header;
	header->next = header;
	return header;
}

void ListDestroy(LTNode* phead) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		LTNode* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	free(phead);
	phead = NULL;
}

void ListPushFront(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* newNode = BuyListNode(x);
	LTNode* cur = phead->next;
	phead->next = newNode;
	newNode->prev = phead;
	newNode->next = cur;
	cur->prev = newNode;
}

void ListPushBack(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* newNode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}

void ListPopFront(LTNode* phead) {
	assert(phead->next != phead);
	LTNode* cur = phead->next;
	LTNode* prevCur = cur->prev;
	LTNode* nextCur = cur->next;
	prevCur->next = nextCur;
	nextCur->prev = prevCur;
	free(cur);
	cur = NULL;
}

void ListPopBack(LTNode* phead) {
	assert(phead->next != phead);
	LTNode* cur = phead->prev;
	LTNode* prevCur = cur->prev;
	LTNode* nextCur = cur->next;
	prevCur->next = nextCur;
	nextCur->prev = prevCur;
	free(cur);
	cur = NULL;
}

LTNode* ListFind(LTNode* phead, LTDataType x) {
	LTNode* cur = phead->next;
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

void ListInsert(LTNode* phead, LTNode* pos, LTDataType x) {
	assert(phead && pos);
	LTNode* prevPos = pos->prev;
	LTNode* newNode = BuyListNode(x);
	prevPos->next = newNode;
	newNode->prev = prevPos;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListErase(LTNode* phead, LTNode* pos) {
	assert(phead && pos);
	LTNode* prevPos = pos->prev;
	LTNode* nextPos = pos->next;
	prevPos->next = nextPos;
	nextPos->prev = prevPos;
	free(pos);
	pos = NULL;
}

LTNode* BuyListNode(LTDataType x) {
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

void ListPrint(LTNode* phead) {
	LTNode* cur = phead->next;
	while (cur != phead) {
		printf("%d", cur->data);
		printf("->");
		cur = cur->next;
	}
	printf("O\n");
}