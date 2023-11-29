#include"SeqList.h"
#include"SList.h"
#include"List.h"
#include"Stack.h"

void SeqListTest() {
	SL sl;
	SeqListInit(&sl);

	SeqListInsert(&sl, 1, 1);
	SeqListInsert(&sl, 2, 2);
	SeqListInsert(&sl, 3, 3);
	SeqListInsert(&sl, 4, 4);

	SeqListPrint(&sl);

	SeqListInsert(&sl, 4, 3);
	SeqListInsert(&sl, 4, 2);
	SeqListInsert(&sl, 4, 1);

	SeqListPrint(&sl);
}
void SeqListTest02() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);

	SeqListPrint(&sl);
}
void SeqListTest03() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 6);
	SeqListErase(&sl, 1);


	SeqListPrint(&sl);

}
void SeqListTest04() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);

	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);
	//SeqListPopFront(&sl);


	SeqListPrint(&sl);
	printf("%d", SeqListFind(&sl, 4));

}

void SListTest01() {
	SLTNode* plist = NULL;

	SListPushFront(&plist, 6);

	SListPrint(plist);
	
	SListPopBack(&plist);
	SListPopBack(&plist);
	//SListPopFront(&plist);
	//SListPopFront(&plist);
	printf("\n");

	SListPrint(plist);

}
void SListTest02() {
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* ps = SListFind(plist, 4);

	printf("\n");
	//SListInsert(&plist, ps, 3);
	SListInsertAfter(&plist, ps, 9);

	
	SListPrint(plist);
}
void SListTest03() {
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);

	//SListErase(&plist, SListFind(plist, 0));
	SListEraseAfter(&plist, SListFind(plist, 3));

	SListPrint(plist);

}

void ListTest01() {
	LTNode* phead = NULL;
	phead = ListInit();

	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	//ListInsert(phead, ListFind(phead, 4), 2);
	//ListPopBack(phead);
	//ListPopBack(phead);
	//ListPopBack(phead);
	//ListPopBack(phead);

	//ListPopFront(phead);
	//ListPopFront(phead);
	//ListPopFront(phead);
	//ListPopFront(phead);

	ListErase(phead, ListFind(phead, 4));


	ListPrint(phead);
}

void StackTest01() {
	ST st;
	StackInit(&st);
	
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d\n", StackSize(&st));
	StackPrint(st);

	StackPop(&st);

	printf("%d\n", StackSize(&st));
	StackPrint(st);
}



int main() {
	//SeqListTest();
	//SeqListTest02();
	//SeqListTest03();
	//SeqListTest04();

	//SListTest01();
	//SListTest02();
	//SListTest03();

	//ListTest01();

	StackTest01();



	system("pause");
	return 0;
}