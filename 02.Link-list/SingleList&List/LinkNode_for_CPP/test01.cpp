#include"SeqLIst.h"
#include"List.h"

void TestFun01() {
	SLTNode* s1 = NULL;//ֱ��ʹ��ͷָ��ķ���
	//ֱ��ʹ��ͷָ�룬��Ҫ���ö���ָ��ķ���ȥ��ͷָ���ܹ��Ե�ַ���ݵķ�ʽ���뵽��������

	SListPushBack(&s1, 1);
	SListPushBack(&s1, 2);

	SListPopBack(&s1);


	SListPrint(s1);
}

void TestFun02() {
	SLTNode* s2 = NULL;

	SListPushBack(&s2, 1);
	SListPushBack(&s2, 2);
	SListPushBack(&s2, 3);

	SListPopFront(&s2);

	SListPrint(s2);
}

void TestFun03() {
	SLTNode* s3 = NULL;

	SListPushBack(&s3, 1);
	SListPushBack(&s3, 2);
	SListPushBack(&s3, 3);
	SListPushBack(&s3, 4);
	SListPushBack(&s3, 5);
	SListErase(&s3, 1);

	SListPrint(s3);
	
}

void TestFun04() {
	SLTNode* s4 = NULL;

	SListPushBack(&s4, 1);
	SListPushBack(&s4, 2);
	SListPushBack(&s4, 3);
	SListPushBack(&s4, 2);
	SListPushBack(&s4, 2);
	SListPushBack(&s4, 2);
	SListPushBack(&s4, 2);
	SListPushBack(&s4, 3);
	SListPushBack(&s4, 4);
	SListPrint(s4);
	SLTNode* pos = SListFind(s4, 2);
	int i = 1;
	while (pos) {
		cout << "��" << i << "��pos�ڵ㣺" << pos << "->" << pos->data << endl;
		pos = SListFind(pos->next, 2);//����ѭ��������ҳ��ظ���Ԫ��λ��
		i++;
	}

	pos = SListFind(s4, 3);
	if (pos) {
		pos->data = 30;
	}
	SListPrint(s4);
}

void TestFun05() {
	SLTNode* s5 = NULL;
	SListPushBack(&s5, 1); //����ͷָ����޸ģ���Ҫʹ�ö���ָ��
	SListPushBack(s5, 2);
	SListPushBack(s5, 3);
	SListPushBack(s5, 4);
	SListPushBack(s5, 5);
	SListPushBack(s5, 6);
	SListPushBack(s5, 7);
	SListPrint(s5);

	//SListInsert(&s5, 3, 30);
	//SListInsert(&s5, SListFind(s5, 3), 30);
	//SListInsertAfter(SListFind(s5, 3), 40);
	/*Ϊ���������õ�ֻ��һ��ָ�룿
		���ڲ����漰�Ե�һ��ͷָ����޸ģ���ʹ���ڵ�һ��Ԫ�غ���룬�޸ĵ�Ҳ
		ֻ�ǵ�һ���ڵ�����ݣ����޸Ľṹ������ݣ�����ʹ��һ��ָ�����
	*/
	//SListPrint(s5);
	
}

void TestFun06() {
	SLTNode* s6 = NULL;
	SListPushBack(&s6, 1); //����ͷָ����޸ģ���Ҫʹ�ö���ָ��
	SListPushBack(s6, 2);
	SListPushBack(s6, 3);
	SListPushBack(s6, 4);
	SListPushBack(s6, 5);
	SListPushBack(s6, 6);
	SListPushBack(s6, 7);
	SListPrint(s6);

	//SListErase(&s6, 3);
	//SListErase(&s6, SListFind(s6, 3));
	SListEraseAfter(SListFind(s6, 3));

	SListPrint(s6);
}

void TestFun07() {
	SLTNode* s7 = NULL;
	SListPushBack(&s7, 1); //����ͷָ����޸ģ���Ҫʹ�ö���ָ��
	SListPushBack(s7, 2);
	SListPushBack(s7, 3);
	SListPushBack(s7, 4);
	SListPushBack(s7, 5);
	SListPushBack(s7, 6);
	SListPushBack(s7, 7);
	SListPrint(s7);

	SListDestroy(&s7);

	SListPrint(s7);
}

void TestList() {
	LTNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	


	LTNode* temp = ListFind(phead, 3);
	ListInsert(temp, 2);
	ListErase(temp);
	ListPrint(phead);

	ListDestroy(phead);
	phead = NULL;

}

int main() {
	//TestFun01();
	//TestFun02();
	//TestFun03();
	//TestFun04();
	//TestFun05();
	//TestFun06();
	//TestFun07();

	TestList();



	system("pause");
	return 0;
}