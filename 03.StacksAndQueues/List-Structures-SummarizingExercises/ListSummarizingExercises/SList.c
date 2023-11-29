#include"SList.h"

void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d", cur->data);
		if (cur->next) {
			printf("->");
		}
		cur = cur->next;
	}
	printf("->NULL\n");
}

void SListPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newNode = BuySListNode(x);
	if (*pphead) {
		SLTNode* cur = *pphead;
		newNode->next = cur;
		*pphead = newNode;
	}
	else {
		newNode->next = NULL;
		*pphead = newNode;
	}
}
void SListPushBack(SLTNode** pphead, SLTDataType x) {
	SLTNode* newNode = BuySListNode(x);
	if (*pphead) {
		SLTNode* tail = *pphead;
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->next = NULL;
	}
	else {
		*pphead = newNode;
		newNode->next = NULL;
	}
}
void SListPopFront(SLTNode** pphead) {
	assert(*pphead);

	SLTNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}
void SListPopBack(SLTNode** pphead) {
	assert(*pphead);

	SLTNode* ptail = *pphead;
	SLTNode* tail = (*pphead)->next;
	while (tail && tail->next) {
		ptail = ptail->next;
		tail = tail->next; 
	}

	if ((*pphead)->next) {
		ptail->next = NULL;
	}
	else {
		*pphead = NULL;
	}

	free(tail);
	tail = NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(*pphead && pos);
	SLTNode* newNode = BuySListNode(x);
	SLTNode* prevPos = *pphead;
	if(prevPos->next && pos != *pphead){
		//找前一个节点,注意循环起始与终止条件
		while (prevPos->next && prevPos->next != pos) {
			prevPos = prevPos->next;
		}
		/*
			小心！是prevpos->next 进行判断，否则很容易写成死循环
		*/
		prevPos->next = newNode;
		newNode->next = pos;
	}
	else {
		*pphead = newNode;
		newNode->next = pos;
	}
}
void SListInsertAfter(SLTNode** phead, SLTNode* prevPos, SLTDataType x) {
	assert(prevPos);
	SLTNode* newNode = BuySListNode(x);
	SLTNode* next = prevPos->next;
	prevPos->next = newNode;
	newNode->next = next;

	//一不小心又写成环了

}
void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(*pphead && pos);
	SLTNode* prevPos = *pphead;
	if (prevPos->next && pos != *pphead) {
		//找前一个节点,注意循环起始与终止条件
		while (prevPos->next && prevPos->next != pos) {
			prevPos = prevPos->next;
		}

		SLTNode* nextPos = pos->next;
		prevPos->next = nextPos;
		free(pos);
		pos = NULL;
	}
	else {
		SLTNode* nextPos = pos->next;
		*pphead = nextPos;
		free(pos);
		pos = NULL;
	}

}
void SListEraseAfter(SLTNode** pphead, SLTNode* prevPos) {
	assert(prevPos->next);
	SLTNode* pos = prevPos->next;
	SLTNode* nextPos = pos->next;
	prevPos->next = nextPos;
	free(pos);
	pos = NULL;
}
/*
* 有点不太清楚地地方
*/
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	assert(phead);
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		else {
			cur = cur->next;
		}
	}

	return NULL;
}

SLTNode* BuySListNode(SLTDataType x) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	newNode->data = x;
	return newNode;
}