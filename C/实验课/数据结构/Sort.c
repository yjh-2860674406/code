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
        Stu temp = students->students[i]; int j = i;
        for ( ; (temp.score > students->students[j-1].score && j>0); j--) {
            // printf("%d,%d\n", students->students[j].score, students->students[j-1].score);
            students->students[j] = students->students[j-1];
        } students->students[j] = temp;
    }
    return TRUE;
}

int ShellSort (PtrStus students) {
    // ϣ������
    int array[3] = {1,3,5};
    for (int k=2; k>0; k--) {
        int d = array[k];
        for (int i=0; i<students->length; i+=d) {
            if (students->students[i].score < students->students[i-d].score) continue;
            Stu temp = students->students[i]; int j = i;
            for (; temp.score > students->students[j-1].score; j-=d) {
                students->students[j] = students->students[j-d];
            } students->students[j] = temp;
        }
    }
}

int SortByBit (PtrStu students) {
    // �۰��������
    
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
    InsertStu(students, "A", 99);
    InsertStu(students, "B", 88);
    InsertStu(students, "C", 90);
    InsertStu(students, "D", 88);
    InsertStu(students, "E", 78);
    InsertStu(students, "F", 100);
    InsertStu(students, "G", 79);
    InsertStu(students, "H", 68);
    InsertStu(students, "I", 100);
    InsertStu(students, "J", 59);
    ShellSort(students);
    PrintByOrder(students);
}