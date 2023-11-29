#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack {
	STDataType* arr;
	int capacity;
	int size;
}ST;

void StackInit(ST* ps);

void StackDestroy(ST* ps);//不能忘记的一个地方

void StackPush(ST* st, STDataType x);
void StackPop(ST* st);
STDataType StackTop(ST* st);
int StackSize(ST* st);
void StackCheakCapacity(ST* st);

bool StackIsEmpty(ST* st);

void StackPrint(ST st);
