#include"SeqList(dynamic).h"

//初始化线性表
void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//销毁线性表
//使用destroy可以在程序运行时进行越界检查，当发生越界访问时会弹出错误信息
void SeqListDestroy(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//打印线性表内的数据
void SeqListPrint(SL* ps) {

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d", ps->a[i]);
		if (i < ps->size - 1)
		{
			printf(",");
		}
	}

	printf("\n");
}

void SeqListCheckCapacity(SL* ps) {
	//两种情况，1.没有空间；2.空间充足
	if (ps->size == ps->capacity)
	{
		//没有空间，进行扩容
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			//这样表明扩充空间失败
			printf("realloc fail\n");//无法进行，退出
			exit(-1);//异常退出
			//不能用return，因为只会退出一点，而且这个函数并没有返回值
		}

		//扩容成功，齐活！
		ps->a = temp;
		ps->capacity = newcapacity;
	}
}

//接口函数 --
void SeqListPushBack(SL* ps, SLDataType x){//尾插功能
	//没有空间，进行扩容
	SeqListCheckCapacity(ps);
	//空间充足，开干！
	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPopBack(SL* ps) {//尾删功能
	assert(ps->size > 0);
	ps->size--;
}
void SeqListPushFront(SL* ps, SLDataType x){//头插功能
	//扩容
	SeqListCheckCapacity(ps); 
	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	
	//放入数据
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps) {		//头删功能
	assert(ps->size > 0);

	//挪动数据
	int begin = 1;
	while (begin < ps->size)//需要兑换的次数为size-1
	{
		ps->a[begin -1] = ps->a[begin];
		begin++;
	}
	
	ps->size--;
}
//... 

int SeqListFind(SL* ps, SLDataType x) {	//位置返回的只是下标int而已
	int sum = 0;
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i + 1;
		}
		sum++;
	}
	if (sum == ps->size) {
		return -1;//如果未找到，返回-1。
	}
}

void SeqListInsert(SL* ps, int pop, SLDataType x) {
	assert(pop > 0 && pop <= ps->size);
	SeqListCheckCapacity(ps);

	int end = ps->size;
	while (end >= pop) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}

	ps->a[end] = x;
	ps->size += 1;
}

void SeqListErase(SL* ps, int pos) {
	assert(pos > 0 && pos <= ps->size);

	int pop = pos;
	while (pop < ps->size) {
		ps->a[pop - 1] = ps->a[pop];
		++pop;
	}
	ps->size--;

}
