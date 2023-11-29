#include"String.h"

void StringInit(St* str) {
	assert(str);
	str->length = 0;
}

void StringDestroy(St* str) {
	assert(str);
	//由于使用的是静态字符串数组的方式存储串类型，所以不必去销毁空间
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
///	关于字符串的比较，完全取决于在某位置上的字符的大小情况
/// 即时是有很长的字符串，在最开始那个位置的字符比另一个字符小，那也算是小于另一个字符串
/// 只有在每一位上的字符全部相同才能算作是相等的字符串
/// 和字典的查找字符排布方式相似
/// </summary>
int StringCompare(St* str1, St* str2) {
	int count = 0;
	while (str1->ch[count] != '\0' && str2->ch[count] != '\0') //"->"的运算优先级是大于"*"的
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
/// 若串1中存在和串2值相等的子串，则返回它在串1中第pos个字符之后
/// 第一次出现的位置，否则返回0。
/// </summary>
/// <param name="str1">串1</param>
/// <param name="str2">串2</param>
/// <param name="pos">参照位置</param>
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
	//参照位置的范围是在0到以str2作为结尾时的位置
	while (tmp <= len1 - len2 + 1) {
		//sub每次接收一次返回长度为len2的子串
		sub = SubString(str1, tmp, len2);
		//bool值以0为假，非0为真

		if (StringCompare(&sub, str2)) {
			//搜索子串的位置依次往后遍历
			++tmp;
		}
		else {
			return tmp - pos;
		}
	}	
	return -1;
}
/// <summary>
/// <para>brute force,暴力破解方式
/// <para>通过寻找与模式串首字符相等的位置来进行初始比较
/// <para>找到首字符相同的位置时，开始遍历比较内部字符
/// <para>若出现字符不匹配，则退出比较，模式串向后移位，继续比较首字符
/// <para>时间复杂度为O(M*N)
/// </summary>

int IndexByBF(St* str1, St* str2, int pos) {
	assert(str1);
	assert(str2);
	assert(pos >= 0 && pos <= StringLength(str1) - StringLength(str2));
	int i = pos - 1;
	int j = 0;
	//保证循环还在主串里，且目标串没有结束
	while (i < StringLength(str1) && j < StringLength(str2)) {
		if (str1->ch[i] == str2->ch[j]) {
			//如果匹配，着两串继续向下遍历匹配。
			i++;
			j++;
		}
		else {
			//如果不匹配，i 回到开始匹配的下一位，j 回到子串的开始位置，两串再继续向下匹配
			//不使用双循环的模式可以减少很多不必要的临时参数，结构也能更加简单
			//这里将下标值回溯的方式来代替对模式串的内循环
			i = i - j + 1;
			j = 0;
		}
	}

	//如果我能找到目标子串，那我的子串肯定是已经遍历完了的
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
	while (i < str->length)	//此处表示大循环，由于next[1]是已经确定的，所以只需要循环len - 1次即可
	{
		//如在初始位置或当前位置与下一位置的符号相同则i，j都往后移动一位，并将j的位值付赋值给下一位
		if (j == 0 || str->ch[i] == str->ch[j]) 
		{
			++i;
			++j;
			next[i] = j;
		}
		//若不相同则
		else {
			j = next[j];
		}
	}
}


/// <summary>
/// 改进后的next数组求值方法
/// 由于部分细节证明未给出，所以可以先暂时会用就行吧
/// 其中最大的变化就是对next[i]的取值方法进行的改进
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
			if (str->ch[i] != str->ch[j])	//各向后移动一位之后，若当前字符与前缀字符不同
			{
				nextVal[i] = j;				//使用原方法赋值next
			}
			else {
				nextVal[i] = nextVal[j];	//如果与前缀字符相同，则将前缀字符的
											//nextval值赋给nextval在i位置的值，
											// 减少了j在串里重复比较相同值的情况
			}
		}
		else {
			j = nextVal[j];

		}
	}

}

/// <summary>
/// KMP模式匹配算法，其中可以在next数组中进行部分改进
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
			//不要忘记了next数组中的【0】值是未定义的数，所以需要避免取值，要将j==0进行判断
			i++;
			j++;
		}
		else {
			//这里就是KMP算法的优势所在，只对j以next数组中的指示进行回溯
			//i = i - j + 1;
			//j = 0;
			j = next[j];	//回退到合适的位置，i值不变
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
/// 返回主串str的第pos个字符起长度为len的子串。
/// **有一些无法解决的问题，局部变量sub无法访问。
/// **但是输出时可以正常将数值传递出去。
/// </summary>
/// <param name="str">主串</param>
/// <param name="pos">起始位置</param>
/// <param name="len">需要返回的子串长度</param>
/// <returns></returns>
St SubString(St* str, int pos, int len) {
	assert(str);
	//这里的起始位置pos的取值范围也为主串长度length
	assert(pos >= 1 && pos < StringLength(str));
	//需要进行初始化，否者会产生不可预料的结果
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
