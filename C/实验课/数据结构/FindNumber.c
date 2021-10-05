#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct PhoneNumber {
    char name[15];
    char number[11];
}Number, *PtrNumber;

PtrNumber InitNumber () {
    PtrNumber numbers = (PtrNumber)malloc(800*sizeof(Number));
    return numbers;
}

void Low (char* string) {
    while (*string != '\0') {
        *string++ |= 32;
    }
}

int Hash (char* name) {
    Low(name); int num = 0; int operate = 7; int x = 0;
    for (; *name != '\0'; name++) {
        x = (int)*name - 97;
        num += x*operate; operate--;
    }
    return num;
}

int InsertNum (char* name, char* number, PtrNumber numbers) {
    int num = Hash(name);
    strcpy(numbers[num].name, name);
    strcpy(numbers[num].number, number);
    return TRUE;
}

char* FindNumber (char* name, PtrNumber numbers) {
    int num = Hash(name);
    return numbers[num].number;
}

int Screen () {
    PtrNumber numbers = InitNumber();
    while (1) {
        printf("*************************************************\n");
        printf("****************电话号码管理系统*****************\n");
        printf("****请输入要执行的操作（101添加，102查找）：****\n");
        printf("*************************************************\n");
        char name[15]; char number[15];
        int num = 0; scanf("%d", &num); getchar();
        switch (num) {
            case 101 :
            printf("请输入要添加的姓名和电话号码\n");
            gets(name); gets(number);
            InsertNum(name, number, numbers);
            printf("添加成功！\n"); break;
            case 102 :
            printf("请输入要查询的姓名：\n");
            gets(name);
            printf("%s 的电话号码是：%s\n", name, FindNumber(name, numbers));
            break;
            default :
            printf("输入错误！请重新输入！\n");continue;
        }
    }
}

int main () {
    Screen();
}