#include"SList.h"

SLTNode* BuyListNode(SLTDataType x) {	//Ƶ��ʹ�ô����¿ռ䣬���Կ��Խ��䵥����Ϊһ������
	//SLTNode* newNode = new SLTNode;	//����һ��new��malloc������
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	//�ƺ���û��ʲô����

	if (newNode == NULL) {//��Ҫ�Ͻ�����������ʧ�ܵı���
		cout << "malloc fail" << endl;
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;

	//������ĺ���������������ֻ�ܳ���һ�Σ����ܽ��䷵��ֵ��Ϊ����ʹ��
}

void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		cout <<'[' << cur->data << ']';
		cur = cur->next;
		if (cur != NULL) {
			cout << "->";
		}
		else {
			cout << "->NULL";
		}
	}
	cout << endl;
}

void SListInit(SLTNode* phead) {
	phead = new SListNode;	//�����µĽڵ���Ϊͷ���
	phead->next = NULL;		//ͷ����ָ����Ϊ��
}

void SListDestroy(SLTNode** pphead) {//�����ܷ�ʵ��δ֪���ڲ������ݷ�����ܻ�������
	assert(*pphead);
	while (*pphead)
	{	
		SListPopFront(pphead);
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x) {
	SLTNode* newNode = BuyListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

void SListPushBack(SLTNode** pphead, SLTDataType x) {

	SLTNode* newNode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else {
		//�ҵ�β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			//��Ҫ��ֹ��whileѭ���ж�tailΪ��ʱ�����ã�������ͷ���Ϊ��ʱ��������β�ڵ�Ĳ��衣
			// ��->����һ�������õ���Ϊ��������tail->next����Ϊ�գ�ֻ�漰�жϣ�����tailָ���ǲ���Ϊ�յġ�    
			tail = tail->next;
		}                
		tail->next = newNode;
	}
}

//�Զ���ָ�빦�ܵĲ���
void SListPushBack(SLTNode* phead, SLTDataType x) {
	SLTNode* newNode = BuyListNode(x);
	if (phead == NULL)
	{
		phead = newNode;
	}
	else {
		//�ҵ�β���
		SLTNode* tail = phead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//�±���Ҳ���
void SListInsert(SLTNode** pphead, int index, SLTDataType x) {
	assert(index > 0);
	SLTNode* newNode = BuyListNode(x);
	if (index == 1 || *pphead == NULL) {
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else {
		SListNode* ptr = *pphead;
		int count = 0;
		while (count != index - 1 && ptr->next != NULL) {
			ptr = ptr->next;
			count++;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}
//�ڵ���Ҳ���(ǰ�߲��룩
//������̫�ʺ�ǰ�߲��룬���ʺϺ�߲���
//�����ǰ������Ҫ��Ϊͷ���β�������жϡ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(*pphead && pos);
	SLTNode* newNode = BuyListNode(x);
	if (*pphead == pos) {	//ͷ������
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else {					//��ͷ������
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos) {
			posPrev = posPrev->next;
		}
		posPrev->next = newNode;
		newNode->next = pos;
	}
}

//����壬����Ч��
void SListInsertAfter(SLTNode* pos, SLTDataType x) {	//����ʹ�õĲ�����ֻ�нڵ�ָ��
	assert(pos);
	SLTNode* newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;

}
/*������Ҳ�����Լ���ȱ�ݵ�*/

//void SListPopFront(SLTNode** pphead) {
//	assert(*pphead != NULL);
//	SLTNode* front = *pphead;
//	SLTNode* back = NULL;
//	if (front->next == NULL) {	//������жϵ�������֧������ʵ��û�������
//		*pphead = NULL;
//		free(front);
//		front = NULL;
//	}
//	else {
//		back = front->next;
//		*pphead = back;
//		free(front);
//		front = NULL;
//	}
//}
void SListPopFront(SLTNode** pphead) {
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

void SListPopBack(SLTNode** pphead) {
	assert(*pphead);	//��Ҫ��֤��������Ϊ0
	SLTNode* prev = NULL;		//��������ָ���Է������Ӧ��ַ���в���
	SLTNode* tail = *pphead;
	while (tail->next) {	//0Ϊ�٣���0Ϊ�棬����NULL������ʽת����0
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	if (prev == NULL) {	//��ֹֻ��һ���ڵ�ʱ��prevʼ��ΪNULLδ�����ı�������ֽ��н����õĲ���
		*pphead = NULL;
	}
	else {
		prev->next = NULL;
	}


}

void SListErase(SLTNode** pphead, int index) {//����λ��ɾ�����±귽��
	assert(*pphead && index > 0);
	SLTNode* prev = NULL;
	SLTNode* back = *pphead;
	int count = 0;
	if (back->next == NULL) {	//ͷɾ���⴦��
		*pphead = NULL;
		free(back);
		back = NULL;
	}
	else {
		while (count != index - 1 && back->next != NULL) {	//ע�⣬����Ӧʹ���ҽ����жϣ�
			//�������ֳ�������ѭ����ֱ�����ȫΪNULL�����
			prev = back;
			back = back->next;
			count++;
		}
		if (prev == NULL) {
			*pphead = back->next;
		}
		else {
			prev->next = back->next;
		}
		
		free(back);
		back = NULL;
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(*pphead);
	if (*pphead == pos) {
		SListPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
		//�����벢û��ʵ���ϵ����壬��Ϊpos�����ֻ��һ���βζ��ѣ�
		//�ں����������ڽ���֮����Լ������յġ�
	}
}

void SListEraseAfter(SLTNode* pos) {
	assert(pos->next);

	SLTNode* prev = pos;
	pos = pos->next;
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	assert(phead);	//��֤���������������һ�������Ͻڵ���ڵ�
	SLTNode* ptr = phead;
	while (ptr) {
		if (ptr->data == x) {
			return ptr;
		}
		else {
			ptr = ptr->next;
		}
	}

	return NULL;
}

void SListModify(SLTNode* phead, int index, SLTDataType x) {
	assert(index > 0 && phead != NULL);
	SLTNode* ptr = phead;
	int count = 1;		//��ʼʱptrָ�����ʵ���ǵ�һ���ڵ㣬��������1��ʼ�ġ�
	while (count != index) {
		if (ptr->next == NULL) {
			break;
		}else {
			ptr = ptr->next;
		}
		count++;	//ע�⣬������++������������ʹ��count����ֵ���ڶ�ptrλ���жϵ�ǰ�档
	}
	if (ptr->next == NULL && count != index) {
		cout << "δ�ҵ���Ӧλ��" << endl;
		exit(-1);
	}
	else {
		ptr->data = x;
	}
	
}