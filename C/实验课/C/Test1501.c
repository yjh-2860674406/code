#include <stdio.h>
#include <stdlib.h>

struct Student 
{
    long id;
    char name[10];
    char sex;
    int age;
    char addr[10];
};

typedef struct Student Stu;
typedef Stu* P;
// ��һ����

Stu students[10];

void Pull (P array)
// Ϊ�ṹ�������е�ÿһ��Ԫ�أ�ѧ����������Ϣ
{
    for (int i=0; i<10; i++)
    {
        printf("�������%d��ѧ������Ϣ��\n", i+1);
        printf("������ѧ�ţ�\n");
        scanf("%d", &students[i].id);
        getchar();
        printf("������������\n");
        scanf("%s", students[i].name);
        getchar();
        printf("�������Ա�(M:man, W:woman)��\n");
        scanf("%c", &students[i].sex);
        getchar();
        printf("���������䣺\n");
        scanf("%d", &students[i].age);
        getchar();
        printf("������סַ��\n");
        scanf("%s", students[i].addr);
        getchar();
    }
}

void Print(P array)
// ��ӡÿһ��ѧ������Ϣ
{
    for (int i=0; i<10; i++)
    {
        printf("%s��ѧ�ţ�%d\t �Ա�%c\t ���䣺%d\t סַ��%s\n", students[i].name, students[i].id, 
        students[i].sex, students[i].age, students[i].addr);
    }
}

void PrintAddr(P array)
// ��ӡÿһ���ṹ��ĵ�ַ
{
    for (int i=0; i<10; i++)
    {
        printf("%p\n", &students[i]);
    }
}

void PrintMember ()
// ��ӡ���ṹ���ÿ����Ա�Ĵ�С����ĸ
{
    printf("��Ա id �ĵ�ַ��%p\t, ��Ա id �Ĵ�С��%d\n", &students[0].id, sizeof(students[0].id));
    printf("��Ա name �ĵ�ַ��%p\t, ��Ա name �Ĵ�С��%d\n", students[0].name, sizeof(students[0].name));
    printf("��Ա sex �ĵ�ַ��%p\t, ��Ա sex �Ĵ�С��%d\n", &students[0].sex, sizeof(students[0].sex));
    printf("��Ա age �ĵ�ַ��%p\t, ��Ա age �Ĵ�С��%d\n", &students[0].age, sizeof(students[0].age));
    printf("��Ա addr �ĵ�ַ��%p\t, ��Ա addr �Ĵ�С��%d\n", students[0].addr, sizeof(students[0].addr));
    printf("�ṹ��Ĵ�С��%d\n", sizeof(students[0]));
}

int main()
{
    // Pull(students);
    PrintMember();
    // Print(students);
    PrintAddr(students);
}