#include"String.h"

void StringInit(St* str) {
	assert(str);
	str->length = 0;
}

void StringDestroy(St* str) {
	assert(str);
	//����ʹ�õ��Ǿ�̬�ַ�������ķ�ʽ�洢�����ͣ����Բ���ȥ���ٿռ�
}

void StringAssign(St* str, const char* st) //
{
	assert(str->length == 0);
	int len = (int)strlen(st);
	assert(str);
	assert(len);
	for (int i = 0; i <= len; i++) {
		str->ch[i] = st[i];
	}
	str->length = len;
}

void StringClear(St* str) {
	assert(str);
	str->length = 0;
}

void StringReplace(St* str1, St* str2) {

}
void StringInsert(St* str1, int pos, St* str2) {
	assert(str1);
	assert(str2);
	assert(pos > 0 && pos <= StringLength(str1));
	int len1 = StringLength(str1);
	int len2 = StringLength(str2);
	for (int i = len1; i >= pos; i--) {
		str1->ch[i + len2] = str1->ch[i];
	}
	for (int j = 0; j < len2; j++) {
		str1->ch[pos + j] = str2->ch[j];
	}
	str1->length += len2;
}

void StringPrint(St* str1)
{
	int len = StringLength(str1);
	for(int i = 0; i < len; i++)
	{
		cout << str1->ch[i] << " ";
	}
}

int StringLength(St* str) {
	assert(str);
	return str->length;
}

/// <summary>
///	�����ַ����ıȽϣ���ȫȡ������ĳλ���ϵ��ַ��Ĵ�С���
/// ��ʱ���кܳ����ַ��������ʼ�Ǹ�λ�õ��ַ�����һ���ַ�С����Ҳ����С����һ���ַ���
/// ֻ����ÿһλ�ϵ��ַ�ȫ����ͬ������������ȵ��ַ���
/// ���ֵ�Ĳ����ַ��Ų���ʽ����
/// </summary>
int StringCompare(St* str1, St* str2) {
	int count = 0;
	while (str1->ch[count] != '\0' && str2->ch[count] != '\0') //"->"���������ȼ��Ǵ���"*"��
	{
		if (str1->ch[count] > str2->ch[count]) {
			return 1;
		}
		else if (str1->ch[count] < str2->ch[count]) {
			return -1;
		}
		else {
			count++;
		}
	}

	if (str1->ch[count] == '\0' && str2->ch[count] != '\0') {
		return -1;
	}
	else if (str2->ch[count] == '\0' && str1->ch[count] != '\0') {
		return 1;
	}
	else {
		return 0;
	}
}

/// <summary>
/// ����1�д��ںʹ�2ֵ��ȵ��Ӵ����򷵻����ڴ�1�е�pos���ַ�֮��
/// ��һ�γ��ֵ�λ�ã����򷵻�0��
/// </summary>
/// <param name="str1">��1</param>
/// <param name="str2">��2</param>
/// <param name="pos">����λ��</param>
/// <returns></returns>
int Index(St* str1, St* str2, int pos) {
	assert(str1);
	assert(str2);
	assert(pos > 0 && pos <= StringLength(str1) - StringLength(str2));
	int len1, len2, tmp;
	St sub;
	len1 = StringLength(str1);
	len2 = StringLength(str2);
	tmp = pos;
	//����λ�õķ�Χ����0����str2��Ϊ��βʱ��λ��
	while (tmp <= len1 - len2 + 1) {
		//subÿ�ν���һ�η��س���Ϊlen2���Ӵ�
		sub = SubString(str1, tmp, len2);
		//boolֵ��0Ϊ�٣���0Ϊ��

		if (StringCompare(&sub, str2)) {
			//�����Ӵ���λ�������������
			++tmp;
		}
		else {
			return tmp - pos;
		}
	}	
	return -1;
}
/// <summary>
/// <para>brute force,�����ƽⷽʽ
/// <para>ͨ��Ѱ����ģʽ�����ַ���ȵ�λ�������г�ʼ�Ƚ�
/// <para>�ҵ����ַ���ͬ��λ��ʱ����ʼ�����Ƚ��ڲ��ַ�
/// <para>�������ַ���ƥ�䣬���˳��Ƚϣ�ģʽ�������λ�������Ƚ����ַ�
/// <para>ʱ�临�Ӷ�ΪO(M*N)
/// </summary>

int IndexByBF(St* str1, St* str2, int pos) {
	assert(str1);
	assert(str2);
	assert(pos >= 0 && pos <= StringLength(str1) - StringLength(str2));
	int i = pos - 1;
	int j = 0;
	//��֤ѭ�������������Ŀ�괮û�н���
	while (i < StringLength(str1) && j < StringLength(str2)) {
		if (str1->ch[i] == str2->ch[j]) {
			//���ƥ�䣬�������������±���ƥ�䡣
			i++;
			j++;
		}
		else {
			//�����ƥ�䣬i �ص���ʼƥ�����һλ��j �ص��Ӵ��Ŀ�ʼλ�ã������ټ�������ƥ��
			//��ʹ��˫ѭ����ģʽ���Լ��ٺܶ಻��Ҫ����ʱ�������ṹҲ�ܸ��Ӽ�
			//���ｫ�±�ֵ���ݵķ�ʽ�������ģʽ������ѭ��
			i = i - j + 1;
			j = 0;
		}
	}

	//��������ҵ�Ŀ���Ӵ������ҵ��Ӵ��϶����Ѿ��������˵�
	if (j == StringLength(str2)) {
		return i - pos - j + 1;
	}
	else {
		return -1;
	}
}

void getNext(St* str, int* next) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < str->length)	//�˴���ʾ��ѭ��������next[1]���Ѿ�ȷ���ģ�����ֻ��Ҫѭ��len - 1�μ���
	{
		//���ڳ�ʼλ�û�ǰλ������һλ�õķ�����ͬ��i��j�������ƶ�һλ������j��λֵ����ֵ����һλ
		if (j == 0 || str->ch[i] == str->ch[j]) 
		{
			++i;
			++j;
			next[i] = j;
		}
		//������ͬ��
		else {
			j = next[j];
		}
	}
}


/// <summary>
/// �Ľ����next������ֵ����
/// ���ڲ���ϸ��֤��δ���������Կ�������ʱ���þ��а�
/// �������ı仯���Ƕ�next[i]��ȡֵ�������еĸĽ�
/// </summary>
/// <param name="str"></param>
/// <param name="nextVal"></param>
void getNextVal(St* str, int* nextVal) {
	int i, j;
	i = 1;
	j = 0;
	nextVal[1] = 0;
	while (i < str->length)	
	{
		if (j == 0 || str->ch[i] == str->ch[j])
		{
			++i;
			++j;
			if (str->ch[i] != str->ch[j])	//������ƶ�һλ֮������ǰ�ַ���ǰ׺�ַ���ͬ
			{
				nextVal[i] = j;				//ʹ��ԭ������ֵnext
			}
			else {
				nextVal[i] = nextVal[j];	//�����ǰ׺�ַ���ͬ����ǰ׺�ַ���
											//nextvalֵ����nextval��iλ�õ�ֵ��
											// ������j�ڴ����ظ��Ƚ���ֵͬ�����
			}
		}
		else {
			j = nextVal[j];

		}
	}

}

/// <summary>
/// KMPģʽƥ���㷨�����п�����next�����н��в��ָĽ�
/// </summary>
/// <param name="str1"></param>
/// <param name="str2"></param>
/// <param name="pos"></param>
/// <returns></returns>
int IndexByKMP(St* str1, St* str2, int pos) {
	assert(str1);
	assert(str2);
	assert(pos >= 0 && pos <= StringLength(str1) - StringLength(str2));
	int i = pos - 1;
	int j = 0;
	int next[255];
	getNextVal(str2, next);
	while (i < StringLength(str1) && j < StringLength(str2)) {
		if (j == 0 || str1->ch[i] == str2->ch[j]) {
			//��Ҫ������next�����еġ�0��ֵ��δ���������������Ҫ����ȡֵ��Ҫ��j==0�����ж�
			i++;
			j++;
		}
		else {
			//�������KMP�㷨���������ڣ�ֻ��j��next�����е�ָʾ���л���
			//i = i - j + 1;
			//j = 0;
			j = next[j];	//���˵����ʵ�λ�ã�iֵ����
		}
	}

	if (j == StringLength(str2)) {
		return i - pos - j + 1;
	}
	else {
		return -1;
	}

}

St* StringCopy(St* dest, St* src) {
	St* originalDest = dest;
	int count = 0;
	while (dest->ch[count] != '\0') {
		dest->ch[count] = src->ch[count];
		count++;
	}

	return originalDest;
}

/// <summary>
/// ��������str�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ���
/// **��һЩ�޷���������⣬�ֲ�����sub�޷����ʡ�
/// **�������ʱ������������ֵ���ݳ�ȥ��
/// </summary>
/// <param name="str">����</param>
/// <param name="pos">��ʼλ��</param>
/// <param name="len">��Ҫ���ص��Ӵ�����</param>
/// <returns></returns>
St SubString(St* str, int pos, int len) {
	assert(str);
	//�������ʼλ��pos��ȡֵ��ΧҲΪ��������length
	assert(pos >= 1 && pos < StringLength(str));
	//��Ҫ���г�ʼ�������߻��������Ԥ�ϵĽ��
	St sub;
	StringInit(&sub);
	int count = 0;
	for (int i = pos - 1; i < pos + len - 1; i++) {
		sub.ch[count] = str->ch[i];
		count++;
	}
	sub.ch[count] = '\0';
	sub.length = len;
	return sub;

}

bool StringEmpty(St* str) {
	assert(str);
	return str->length == 0;
}
