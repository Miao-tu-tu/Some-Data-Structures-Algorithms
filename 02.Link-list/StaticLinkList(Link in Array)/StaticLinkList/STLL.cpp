#include"STLL.h"

void STLListInit(STLL* ps) {
	int i;
	//初始时将所有的元素存储的游标置为下一位的下标
	for (i = 0; i < MAXSIZE - 1; i++) {
		ps->arr[i].data = i + 1;
	}
	//初始情况最后一个数组保存的第一个位置应是0
	ps->arr[MAXSIZE - 1].data = 0;
}

void STTListDestroy(STLL* ps) {
	free(ps);
	ps = NULL;
}

void STLListPushFront(STLL* ps, STLLDataType x) {

}

int STLListFind(STLL* ps) {
}

int STLListMalloc(STLL* ps) {
	int i = ps->arr[0].index;	//当前数组保存的第一个元素的index存储的值
								//就是返回第一个备用空闲的下标
	if (ps->arr[0].index) {
		//如果首地址存储的游标信息不为0，则将首地址游标替换成第一个备用空闲空间的下标
		ps->arr[0].index = ps->arr[i].index;

	}
	return i;

}