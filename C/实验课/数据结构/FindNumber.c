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
        printf("****************�绰�������ϵͳ*****************\n");
        printf("****������Ҫִ�еĲ�����101��ӣ�102���ң���****\n");
        printf("*************************************************\n");
        char name[15]; char number[15];
        int num = 0; scanf("%d", &num); getchar();
        switch (num) {
            case 101 :
            printf("������Ҫ��ӵ������͵绰����\n");
            gets(name); gets(number);
            InsertNum(name, number, numbers);
            printf("��ӳɹ���\n"); break;
            case 102 :
            printf("������Ҫ��ѯ��������\n");
            gets(name);
            printf("%s �ĵ绰�����ǣ�%s\n", name, FindNumber(name, numbers));
            break;
            default :
            printf("����������������룡\n");continue;
        }
    }
}

int main () {
    Screen();
}