#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Student {
    int score;
    char name[10];
}Stu, *PtrStu;

typedef struct Students {
    PtrStu students;
    int length;
    int size;
}Stus, *PtrStus;

PtrStus InitStu () {
    // ��ʼ���ɼ���
    PtrStus students = (PtrStus)malloc(sizeof(Stus));
    students->length = 0; students->students = (PtrStu)malloc(60*sizeof(Stu));
    students->size = 60; return students;
}

int InsertStu (PtrStus students, char* name, int score) {
    // ����ѧ���ɼ�
    if (students->length >= students->size) {
        students->students = (PtrStu)realloc(students->students, (students->size+40)*sizeof(Stu));
        students->size += 40;
    }
    strcpy(students->students[students->length].name, name);
    students->students[students->length].score = score; students->length++;
    return TRUE;
}

int SortStu (PtrStus students) {
    // �Ӵ�С����
    for (int i=1; i<students->length; i++) {
        if (students->students[i].score < students->students[i-1].score) continue;
        for (int j=i; (students->students[j].score > students->students[j-1].score) && j>0; j--) {
            Stu temp = students->students[j];
            students->students[j] = students->students[j-1];
            students->students[j-1] = temp;
        }
    }
    return TRUE;
}

int PrintAll (PtrStus students) {
    // ��ӡȫ���ɼ���
    for (int i=0; i<students->length; i++) {
        printf("%s �ĳɼ���%d\n", students->students[i].name, students->students[i].score);
    }
    return TRUE;
}

int PrintByOrder (PtrStus students) {
    // ����������ӡ
    SortStu(students);
    int num = 1;
    for (int i=0; i<students->length; i++) {
        printf("�� %d ����%3s �ĳɼ���%d\n", num++, students->students[i].name, students->students[i].score);
        if (students->students[i].score == students->students[i+1].score) num--;
    }
    return TRUE;
}

int main () {
    PtrStus students = InitStu();
    InsertStu(students, "YJH", 99);
    InsertStu(students, "HHH", 88);
    InsertStu(students, "CYX", 90);
    InsertStu(students, "CY", 88);
    SortStu(students);
    PrintByOrder(students);
}