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
// 改一下名

Stu students[10];

void Pull (P array)
// 为结构体数组中的每一个元素（学生）填入信息
{
    for (int i=0; i<10; i++)
    {
        printf("请输入第%d个学生的信息：\n", i+1);
        printf("请输入学号：\n");
        scanf("%d", &students[i].id);
        getchar();
        printf("请输入姓名：\n");
        scanf("%s", students[i].name);
        getchar();
        printf("请输入性别(M:man, W:woman)：\n");
        scanf("%c", &students[i].sex);
        getchar();
        printf("请输入年龄：\n");
        scanf("%d", &students[i].age);
        getchar();
        printf("请输入住址：\n");
        scanf("%s", students[i].addr);
        getchar();
    }
}

void Print(P array)
// 打印每一个学生的信息
{
    for (int i=0; i<10; i++)
    {
        printf("%s的学号：%d\t 性别：%c\t 年龄：%d\t 住址：%s\n", students[i].name, students[i].id, 
        students[i].sex, students[i].age, students[i].addr);
    }
}

void PrintAddr(P array)
// 打印每一个结构体的地址
{
    for (int i=0; i<10; i++)
    {
        printf("%p\n", &students[i]);
    }
}

void PrintMember ()
// 打印出结构体的每个成员的大小和字母
{
    printf("成员 id 的地址：%p\t, 成员 id 的大小：%d\n", &students[0].id, sizeof(students[0].id));
    printf("成员 name 的地址：%p\t, 成员 name 的大小：%d\n", students[0].name, sizeof(students[0].name));
    printf("成员 sex 的地址：%p\t, 成员 sex 的大小：%d\n", &students[0].sex, sizeof(students[0].sex));
    printf("成员 age 的地址：%p\t, 成员 age 的大小：%d\n", &students[0].age, sizeof(students[0].age));
    printf("成员 addr 的地址：%p\t, 成员 addr 的大小：%d\n", students[0].addr, sizeof(students[0].addr));
    printf("结构体的大小：%d\n", sizeof(students[0]));
}

int main()
{
    // Pull(students);
    PrintMember();
    // Print(students);
    PrintAddr(students);
}