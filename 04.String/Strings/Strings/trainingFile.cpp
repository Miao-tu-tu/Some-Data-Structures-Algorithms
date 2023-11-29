#include"trainingFile.h"

void getNext(St* str, int* next) {
	assert(str);
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < str->length) {
		if (j == 0 || str->ch[i] == str->ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

void getNextVal(St* str, int* nextVal) {
	assert(str);
	int i = 1;
	int i = 1;
	int j = 0;
	nextVal[1] = 0;
	while (i < str->length) {
		if (j == 0 || str->ch[i] == str->ch[j]) {
			i++;
			j++;
			if (str->ch[i] != str->ch[j]) {
				nextVal[i] = j;
			}
			else {
				nextVal[i] = nextVal[j];
			}
		}
		else {
			j = nextVal[j] ;
		}
	}
}

void StringInit(St* str) {
	str->length = 0;
}
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


int index(St* str1, int pos, St* str2) {
	assert(str1);
	assert(str2);
	assert(pos > 0 && pos < str1->length - str2->length);
	int len1 = str1->length;
	int len2 = str2->length;
	int tmp = pos;
	St sub;
	while (tmp < len1-len2) {
		sub = SubString(str1, tmp, len2);
		if (StringCompare(&sub, str2)) {
			tmp++;
		}
		else {
			return tmp - pos;
		}
	}
	return -1;
}

int indexBF(St* str1, int pos, St* str2) {
	assert(str1);
	assert(str2);
	int len1 = str1->length;
	int len2 = str2->length;
	assert(pos > 0 && pos < len1 - len2);
	//int i = 0, 错误啦，这里是有pos参照位置的
	int i = pos - 1;
	int j = 0;
	while (i < len1 && j < len2) {
		if (str1->ch[i] == str2->ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == len2) {
		/*return pos - i - 1;*/
		return i - pos - j + 1;
		//这里是需要找到和子串头相同的位置
	}
	else {
		return -1;
	}
}

int indexKMP(St* str1, int pos, St* str2) {
	assert(str1);
	assert(str2);
	int len1 = str1->length;
	int len2 = str2->length;
	assert(pos > 0 && pos < len1 - len2);
	/*int i = 0;*/
	int i = pos - 1;
	int j = 0;
	int next[MAX_SIZE];
	getNext(str2, next);
	while (i < len1 && j < len2) {
		if (j == 0 || str1->ch[i] == str2->ch[j]) {
			/*看来还是需要理解的，初始时，j == 0，是不能走下面的
			*判断的否则就乱码了*/
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}

	if (j == str2->length) {
		return i - pos - j + 1;
	}
	else {
		return -1;
	}
}

St SubString(St* str, int pos, int len) {
	assert(str);
	//这里的起始位置pos的取值范围也为主串长度length
	assert(pos >= 1 && pos < str->length);
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
