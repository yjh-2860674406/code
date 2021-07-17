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
// 创建头节点
{
    P head = (P)malloc(sizeof(Stu));
    head->next = NULL;
    return head;
}

void Pull (int i, P student)
// 记录第i个学生信息
{
    printf("请输入第%d个学生的信息：\n", i);
    printf("请输入学号：\n");
    scanf("%d", &student->id);
    getchar();
    printf("请输入姓名：\n");
    scanf("%s", student->name);
    getchar();
    printf("请输入性别(M:man, W:woman)：\n");
    scanf("%c", &student->sex);
    getchar();
    printf("请输入年龄：\n");
    scanf("%d", &student->age);
    getchar();
    printf("请输入住址：\n");
    scanf("%s", student->addr);
    getchar();
}

void Insert (P head)
// 尾插法插入链表
{
    int i=0;
    while (i++, head->next != NULL) head = head->next;
    head->next = (P)malloc(sizeof(Stu));
    Pull(i, head->next);
    head->next->next = NULL;
}

void PrintAddr (P head)
// 打印每个结构体的地址
{
    for (int i=0; i<11; i++) printf("%p\n", head++);
}

int main()
{
    P head = Make();
    for (int i=0; i<10; i++) Insert(head);
    PrintAddr (head);
}