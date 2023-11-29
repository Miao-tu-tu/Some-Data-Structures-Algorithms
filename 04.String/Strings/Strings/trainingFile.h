#pragma once

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

#define MAX_SIZE 225

typedef int SDataType;
typedef struct String {
	char ch[MAX_SIZE];
	int length;
}St;

void StringInit(St* str);
void getNext(St* str, int* next);
void getNextVal(St* str, int* nextVal);

int StringCompare(St* str1, St* str2);
int index(St* str1, int pos, St* str2);
int indexBF(St* str1, int pos, St* str2);
int indexKMP(St* str1, int pos, St* str2);

St SubString(St* str, int pos, int len);
