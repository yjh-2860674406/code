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
    printf("��������������:\n");
    gets(person.name);
    // scanf("%s", person.name);
    printf("�����������Ա�(��MŮF):\n");
    person.sex = getchar();
    printf("��������������:\n");
    scanf("%ud", &person.age);
    printf("�������������(m):\n");
    scanf("%lf", &person.height);
    printf("��������������(kg):\n");
    scanf("%lf", &person.weight);
    person.BMI = (person.weight)/(person.height*person.height);
    printf("%s����Ϣ:\n", person.name);
    printf("�Ա�:%c\n", person.sex);
    printf("����:%6d��\n", person.age);
    printf("���:%17.3f(m)\n", person.height);
    printf("����:%10.2f(kg)\n", person.weight);
    printf("BMI:%f\n", person.BMI);
    return 0;
}