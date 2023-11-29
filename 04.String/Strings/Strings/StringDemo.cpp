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
//// 初始化串
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
//// 输出串
//void printString(const String* s) {
//    printf("%s\n", s->str);
//}
//
//// 追加字符到串
//void appendString(String* s, char c) {
//    if (s->length < MAX_SIZE - 1) {
//        s->str[s->length] = c;
//        s->length++;
//        s->str[s->length] = '\0';  // 确保字符串以 null 结尾
//    }
//    else {
//        printf("Error: String length exceeds maximum size.\n");
//    }
//}
//
//// 拼接两个串
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
//    // 初始化串
//    initString(&str1, "Hello");
//    initString(&str2, " World");
//
//    // 输出串
//    printf("String 1: ");
//    printString(&str1);
//
//    printf("String 2: ");
//    printString(&str2);
//
//    // 拼接串
//    concatenateString(&str1, &str2, &result);
//
//    // 输出结果
//    printf("Concatenated String: ");
//    printString(&result);
//
//    // 追加字符
//    appendString(&result, '!');
//    printf("Appended String: ");
//    printString(&result);
//
//    return 0;
//}
