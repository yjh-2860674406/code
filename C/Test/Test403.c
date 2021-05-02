#include <stdio.h>

struct Information
{
    char name[10];
    char sex;
    unsigned int age;
    double height;
    double weight;
    double BMI;
};

int main()
{
    struct Information person;
    printf("请输入您的姓名:\n");
    gets(person.name);
    // scanf("%s", person.name);
    printf("请输入您的性别(男M女F):\n");
    person.sex = getchar();
    printf("请输入您的年龄:\n");
    scanf("%ud", &person.age);
    printf("请输入您的身高(m):\n");
    scanf("%lf", &person.height);
    printf("请输入您的体重(kg):\n");
    scanf("%lf", &person.weight);
    person.BMI = (person.weight)/(person.height*person.height);
    printf("%s的信息:\n", person.name);
    printf("性别:%c\n", person.sex);
    printf("年龄:%6d岁\n", person.age);
    printf("身高:%17.3f(m)\n", person.height);
    printf("体重:%10.2f(kg)\n", person.weight);
    printf("BMI:%f\n", person.BMI);
    return 0;
}