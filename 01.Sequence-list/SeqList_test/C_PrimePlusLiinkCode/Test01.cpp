#include"SeqList.h"

void TestFunction() {
	SL s1;
	SeqListInit(&s1);

	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPushBack(&s1, 6);

	SeqListPushFront(&s1, 666);

	SeqListPrint(&s1);
	SeqListDestroy(&s1);
}

int main() {
	TestFunction();

	system("pause");
	return 0;
}