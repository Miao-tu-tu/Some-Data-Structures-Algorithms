#include"String.h"

void TestString01() {
	St str1, str2;
	StringInit(&str1);
	StringInit(&str2);

	StringAssign(&str1, "123489");
	StringAssign(&str2, "567");

	StringInsert(&str1, 4, &str2);

	cout << Index(&str1, &str2, 5) << endl;
	cout << IndexByBF(&str1, &str2, 5) << endl;
	cout << IndexByKMP(&str1, &str2, 5) << endl;



	//StringPrint(&str2);

}

void TestString02()
{
	St str;
	int next[10];
	StringInit(&str);
	StringAssign(&str, "ababaaaba");

	getNext(&str, next);

}



int main() {

	TestString01();
	//TestString02();

	system("pause");
	return 0;
}