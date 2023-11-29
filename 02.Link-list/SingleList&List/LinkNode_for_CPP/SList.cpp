#include"SList.h"

SLTNode* BuyListNode(SLTDataType x) {	//频繁使用创建新空间，所以可以将其单独做为一个函数
	//SLTNode* newNode = new SLTNode;	//测试一下new和malloc的区别
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	//似乎并没有什么区别

	if (newNode == NULL) {//需要严谨，进行扩容失败的报错
		cout << "malloc fail" << endl;
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;

	//创建类的函数在其他函数中只能出现一次，不能将其返回值作为参数使用
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
	phead = new SListNode;	//生成新的节点作为头结点
	phead->next = NULL;		//头结点的指针置为空
}

void SListDestroy(SLTNode** pphead) {//具体能否实现未知，在参数传递方面可能会有问题
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
		//找到尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			//需要防止在while循环中对tail为空时解引用，所以在头结点为空时，跳过找尾节点的步骤。
			// “->”是一个解引用的行为，在这里tail->next可以为空（只涉及判断），而tail指针是不能为空的。    
			tail = tail->next;
		}                
		tail->next = newNode;
	}
}

//对二级指针功能的测验
void SListPushBack(SLTNode* phead, SLTDataType x) {
	SLTNode* newNode = BuyListNode(x);
	if (phead == NULL)
	{
		phead = newNode;
	}
	else {
		//找到尾结点
		SLTNode* tail = phead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//下标查找插入
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
//节点查找插入(前边插入）
//单链表不太适合前边插入，更适合后边插入
//如果是前插则需要分为头插和尾插两种判断。
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(*pphead && pos);
	SLTNode* newNode = BuyListNode(x);
	if (*pphead == pos) {	//头插类型
		newNode->next = *pphead;
		*pphead = newNode;
	}
	else {					//非头插类型
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos) {
			posPrev = posPrev->next;
		}
		posPrev->next = newNode;
		newNode->next = pos;
	}
}

//往后插，更有效率
void SListInsertAfter(SLTNode* pos, SLTDataType x) {	//这里使用的参数是只有节点指针
	assert(pos);
	SLTNode* newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;

}
/*单链表也是有自己的缺陷的*/

//void SListPopFront(SLTNode** pphead) {
//	assert(*pphead != NULL);
//	SLTNode* front = *pphead;
//	SLTNode* back = NULL;
//	if (front->next == NULL) {	//这里的判断的两个分支操作其实是没有区别的
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
	assert(*pphead);	//需要保证其借点数不为0
	SLTNode* prev = NULL;		//设置两个指针以方便对相应地址进行操作
	SLTNode* tail = *pphead;
	while (tail->next) {	//0为假，非0为真，但是NULL可以隐式转换成0
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail = NULL;
	if (prev == NULL) {	//防止只有一个节点时，prev始终为NULL未发生改变而后续又进行解引用的操作
		*pphead = NULL;
	}
	else {
		prev->next = NULL;
	}


}

void SListErase(SLTNode** pphead, int index) {//任意位置删除，下标方法
	assert(*pphead && index > 0);
	SLTNode* prev = NULL;
	SLTNode* back = *pphead;
	int count = 0;
	if (back->next == NULL) {	//头删特殊处理
		*pphead = NULL;
		free(back);
		back = NULL;
	}
	else {
		while (count != index - 1 && back->next != NULL) {	//注意，这里应使用且进行判断，
			//否则会出现持续放行循环，直至最后全为NULL的情况
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
		//这句代码并没有实际上的意义，因为pos传入的只是一个形参而已，
		//在函数生命周期结束之后会自己被回收的。
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
	assert(phead);	//保证这个链表至少是有一个及以上节点存在的
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
	int count = 1;		//初始时ptr指向的其实就是第一个节点，所以是以1开始的。
	while (count != index) {
		if (ptr->next == NULL) {
			break;
		}else {
			ptr = ptr->next;
		}
		count++;	//注意，不能先++操作，这样会使得count的数值跑在对ptr位置判断的前面。
	}
	if (ptr->next == NULL && count != index) {
		cout << "未找到相应位置" << endl;
		exit(-1);
	}
	else {
		ptr->data = x;
	}
	
}