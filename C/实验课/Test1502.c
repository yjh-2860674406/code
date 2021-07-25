#include <stdio.h>
#include <stdlib.h>

struct Student 
{
    long id;
    char name[10];
    char sex;
    int age;
    char addr[10];
    struct Student* next;
};

typedef struct Student Stu;
typedef Stu* P;

P Make()
// ����ͷ�ڵ�
{
    P head = (P)malloc(sizeof(Stu));
    head->next = NULL;
    return head;
}

void Pull (int i, P student)
// ��¼��i��ѧ����Ϣ
{
    printf("�������%d��ѧ������Ϣ��\n", i);
    printf("������ѧ�ţ�\n");
    scanf("%d", &student->id);
    getchar();
    printf("������������\n");
    scanf("%s", student->name);
    getchar();
    printf("�������Ա�(M:man, W:woman)��\n");
    scanf("%c", &student->sex);
    getchar();
    printf("���������䣺\n");
    scanf("%d", &student->age);
    getchar();
    printf("������סַ��\n");
    scanf("%s", student->addr);
    getchar();
}

void Insert (P head)
// β�巨��������
{
    int i=0;
    while (i++, head->next != NULL) head = head->next;
    head->next = (P)malloc(sizeof(Stu));
    Pull(i, head->next);
    head->next->next = NULL;
}

void PrintAddr (P head)
// ��ӡÿ���ṹ��ĵ�ַ
{
    for (int i=0; i<11; i++) printf("%p\n", head++);
}

int main()
{
    P head = Make();
    for (int i=0; i<10; i++) Insert(head);
    PrintAddr (head);
}