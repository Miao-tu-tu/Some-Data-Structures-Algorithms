#include"STLL.h"

void STLListInit(STLL* ps) {
	int i;
	//��ʼʱ�����е�Ԫ�ش洢���α���Ϊ��һλ���±�
	for (i = 0; i < MAXSIZE - 1; i++) {
		ps->arr[i].data = i + 1;
	}
	//��ʼ������һ�����鱣��ĵ�һ��λ��Ӧ��0
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
	int i = ps->arr[0].index;	//��ǰ���鱣��ĵ�һ��Ԫ�ص�index�洢��ֵ
								//���Ƿ��ص�һ�����ÿ��е��±�
	if (ps->arr[0].index) {
		//����׵�ַ�洢���α���Ϣ��Ϊ0�����׵�ַ�α��滻�ɵ�һ�����ÿ��пռ���±�
		ps->arr[0].index = ps->arr[i].index;

	}
	return i;

}