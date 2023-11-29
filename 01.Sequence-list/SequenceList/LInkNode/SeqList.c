#include"SeqList(dynamic).h"

//��ʼ�����Ա�
void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//�������Ա�
//ʹ��destroy�����ڳ�������ʱ����Խ���飬������Խ�����ʱ�ᵯ��������Ϣ
void SeqListDestroy(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//��ӡ���Ա��ڵ�����
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
	//���������1.û�пռ䣻2.�ռ����
	if (ps->size == ps->capacity)
	{
		//û�пռ䣬��������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL)
		{
			//������������ռ�ʧ��
			printf("realloc fail\n");//�޷����У��˳�
			exit(-1);//�쳣�˳�
			//������return����Ϊֻ���˳�һ�㣬�������������û�з���ֵ
		}

		//���ݳɹ�����
		ps->a = temp;
		ps->capacity = newcapacity;
	}
}

//�ӿں��� --
void SeqListPushBack(SL* ps, SLDataType x){//β�幦��
	//û�пռ䣬��������
	SeqListCheckCapacity(ps);
	//�ռ���㣬���ɣ�
	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPopBack(SL* ps) {//βɾ����
	assert(ps->size > 0);
	ps->size--;
}
void SeqListPushFront(SL* ps, SLDataType x){//ͷ�幦��
	//����
	SeqListCheckCapacity(ps); 
	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	
	//��������
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps) {		//ͷɾ����
	assert(ps->size > 0);

	//Ų������
	int begin = 1;
	while (begin < ps->size)//��Ҫ�һ��Ĵ���Ϊsize-1
	{
		ps->a[begin -1] = ps->a[begin];
		begin++;
	}
	
	ps->size--;
}
//... 

int SeqListFind(SL* ps, SLDataType x) {	//λ�÷��ص�ֻ���±�int����
	int sum = 0;
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i + 1;
		}
		sum++;
	}
	if (sum == ps->size) {
		return -1;//���δ�ҵ�������-1��
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
