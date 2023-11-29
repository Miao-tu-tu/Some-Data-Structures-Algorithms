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
void StringAssign(St* str, const char* st);
void StringDestroy(St* str);
void StringClear(St* str);
void StringReplace(St* str1, St* str2);
void StringInsert(St* str1, int pos, St* str2);
void StringPrint(St* str1);
void getNext(St* str, int* next);
void getNextVal(St* str, int* next);

int StringLength(St* str);
int StringCompare(St* str1, St* str2);
int Index(St* str1, St* str2, int pos);
int IndexByBF(St* str1, St* str2, int pos);
int IndexByKMP(St* str1, St* str2, int pos);

St SubString(St* str, int pos, int len);
St* StringCopy(St* dest, St* src);

bool StringEmpty(St* str);

