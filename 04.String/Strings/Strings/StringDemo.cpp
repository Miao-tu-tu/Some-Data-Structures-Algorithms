#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX_SIZE 100
//
//typedef struct {
//    char str[MAX_SIZE];
//    int length;
//} String;
//
//// ��ʼ����
//void initString(String* s, const char* initial) {
//    if (initial) {
//        strncpy(s->str, initial, MAX_SIZE - 1);
//        s->length = strlen(s->str);
//    }
//    else {
//        s->str[0] = '\0';
//        s->length = 0;
//    }
//}
//
//// �����
//void printString(const String* s) {
//    printf("%s\n", s->str);
//}
//
//// ׷���ַ�����
//void appendString(String* s, char c) {
//    if (s->length < MAX_SIZE - 1) {
//        s->str[s->length] = c;
//        s->length++;
//        s->str[s->length] = '\0';  // ȷ���ַ����� null ��β
//    }
//    else {
//        printf("Error: String length exceeds maximum size.\n");
//    }
//}
//
//// ƴ��������
//void concatenateString(const String* s1, const String* s2, String* result) {
//    if (s1->length + s2->length < MAX_SIZE - 1) {
//        strcpy(result->str, s1->str);
//        strcat(result->str, s2->str);
//        result->length = strlen(result->str);
//    }
//    else {
//        printf("Error: Resulting string length exceeds maximum size.\n");
//    }
//}

//int main01() {
//    String str1, str2, result;
//
//    // ��ʼ����
//    initString(&str1, "Hello");
//    initString(&str2, " World");
//
//    // �����
//    printf("String 1: ");
//    printString(&str1);
//
//    printf("String 2: ");
//    printString(&str2);
//
//    // ƴ�Ӵ�
//    concatenateString(&str1, &str2, &result);
//
//    // ������
//    printf("Concatenated String: ");
//    printString(&result);
//
//    // ׷���ַ�
//    appendString(&result, '!');
//    printf("Appended String: ");
//    printString(&result);
//
//    return 0;
//}
