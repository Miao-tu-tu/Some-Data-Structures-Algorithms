#include"SeqList(dynamic).h"

void TestSeqList1() {
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);

	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

void TestSeqList2() {
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);
	SeqListPushBack(&s1, 7);
	SeqListPushBack(&s1, 8);
	SeqListPushBack(&s1, 9);

	SeqListPrint(&s1);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 11);
	SeqListPushFront(&s1, 12);

	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);

	SeqListPrint(&s1);

	printf("%d\n", SeqListFind(&s1, 100));

	SeqListInsert(&s1, 3, 100);
	SeqListPrint(&s1);
	SeqListErase(&s1, 3);
	SeqListPrint(&s1);

	SeqListDestroy(&s1);
}

int main()
{
	//TestSeqList1();
	TestSeqList2();

	return 0;
}