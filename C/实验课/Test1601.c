#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ID(x) (x-2020101000)
#define STU students[ID(id)]
#define C_ID(x) (x-1000)
#define CLA classes[C_ID(class_id)]
#define getid scanf("%d", &id)
#define getclass_id scanf("%d", &class_id)
#define Idtrue if (STU.right == 'y') 
#define Class_idtrue if (CLA.right == 'y') 
#define star "************"

struct Stu_Class
{
    int score;
    char right;
};

struct Student 
{
    char name[10];
    char sex;
    int age;
    char faculty[10];
    struct Stu_Class score[50];
    char right;
};

struct Class
{
    int credit;
    char class_name[10];
    struct Class* pre;
    char right;
};

struct Student students[1000];
struct Class classes[50];



void WriteStu ()
{
    FILE* f = fopen("Store.txt","w+");
    fwrite(students,sizeof(struct Student),1000,f);
    fclose(f);
}

void WriteClass ()
{
    FILE* f = fopen("Store.txt","w+");
    fwrite(classes,sizeof(struct Class),50,f);
    fclose(f);
}

void ReadStu ()
{
    FILE* f = fopen("Store.txt", "w+");
    fread(students,sizeof(struct Student), 1000, f);
    fclose(f);
}

void ReadClass ()
{
    FILE* f = fopen("Store.txt", "w+");
    fread(classes,sizeof(struct Class), 50, f);
    fclose(f);
}

// 以下为 学生信息 的操作

void InsertStu ()
// 录入学生
{
    int id;
    printf("请输入依次输入学号，姓名，性别，年龄，院系:\n");
    getid;getchar();
    gets(STU.name);
    scanf("%c", &STU.sex);getchar();
    scanf("%d", &STU.age);getchar();
    gets(STU.faculty);
    students[ID(id)].right = 'y';
    printf("录入完毕\n");
    clock_t finish = clock();
}

void FindStuById ()
// 通过学号查询学生信息
{
    int id;
    printf("请输入要查询的学生学号：\n");
    getid;
    if (STU.right == 'y')
    {
        printf("以下是学生的信息：\n");
        printf("姓名：%s\n", STU.name);
        printf("性别：%c\n", STU.sex);
        printf("年龄：%d\n", STU.age);
        printf("院系：%s\n", STU.faculty);
        printf("查询完毕\n");
    }
    else printf("查无此人\n");
}

void FindStuByName ()
// 通过姓名查询学生信息
{
    char names[10];
    int id;
    int num = 0;
    printf("请输入要查询的学生姓名：\n");
    puts(names);
    for (int i=0; i<1000; i++)
    {
        if (strcmp(students[i].name, names)) 
        {
            id = i+2020101000;
            printf("以下是学生的信息：\n");
            printf("姓名：%s\n", STU.name);
            printf("学号：%d\n", id);
            printf("性别：%c\n", STU.sex);
            printf("年龄：%d\n", STU.age);
            printf("院系：%s\n", STU.faculty);
            printf("查询完毕\n");
            num ++;
        }
    }
    if (num == 0) printf("查无此人\n");
}

void ChangStuId ()
// 改变学生的id
{
    char names[10];
    int id;
    int num = 0;
    printf("请输入要修改的学生姓名：\n");
    puts(names);
    for (int i=0; i<1000; i++)
    {
        if (strcmp(students[i].name, names)) 
        {
            printf("请输入修改后的学生学号：\n");
            getid;
            strcpy(STU.name, students[i].name);
            STU.age = students[i].age;
            STU.right = 'y';students[i].right = 'n';
            strcpy(STU.faculty, students[i].faculty);
            STU.sex = students[i].sex;
            for (int j=0; j<50; i++)
            {
                STU.score[j].right = students[i].score[j].right;
                STU.score[j].score = students[i].score[j].score;
            }
            printf("修改成功\n");
        }
    }
    if (num == 0) printf("查无此人\n");
}

void ChangStuName ()
// 修改姓名
{
    int id;
    printf("请输入要修改的学生学号：\n");
    getid;getchar();
    Idtrue
    {
        printf("请输入要修改的姓名：\n");
        gets(STU.name);
        printf("修改完成\n");
    }
    else printf("查无此人\n");
}

void ChangStuAge ()
// 修改年龄
{
    int id;
    printf("请输入要修改的学生学号：\n");
    getid;
    Idtrue
    {
        printf("请输入要修改的年龄：\n");
        scanf("%d", &STU.age);getchar();
        printf("修改完成\n");
    }
    else printf("查无此人\n");
}

void ChangStuSex ()
// 修改性别
{
    int id;
    printf("请输入要修改的学生学号：\n");
    getid;
    Idtrue
    {
        if (STU.sex == 'm') STU.sex = 'f';
        else STU.sex = 'm';
        printf("修改完成\n");
    }
    else printf("查无此人\n");
}

void ChangStuF ()
// 修改院系
{
    int id;
    printf("请输入要修改的学生学号：\n");
    getid;
    Idtrue
    {
        printf("请输入要修改的院系：\n");
        gets(STU.faculty);
        printf("修改完毕\n");
    }
    else printf("查无此人\n");
}

void DeleteId ()
// 删除学生
{
    int id;
    printf("请输入要删除的学生学号：\n");
    getid;getchar();
    printf("请确认要进行此操作！(y为确认，n为取消)\n");
    char selete;
    scanf("%c", &selete);
    if (selete == 'y')
    {
        STU.right = 'n';
        printf("已删除");
    }
    else printf("已取消");
}

void InsertStuClass ()
// 给学生录入课程和成绩
{
    int id;
    printf("请输入要录入课程的学生学号：\n");
    getid;
    Idtrue
    {
        int class_id;
        printf("请输入要录入的课程id：\n");
        getclass_id;
        Class_idtrue
        {
            printf("请输入%s在%s的成绩：\n", STU.name, CLA.class_name);
            int score;
            scanf("%d", &score);
            STU.score[C_ID(class_id)].score = score;
            STU.score[C_ID(class_id)].right = 'y';
            printf("录入完毕\n");
        }
        else printf("没有此课程！");
    }
    else printf("没有该生");
}

void FindStuAllClass ()
// 查询一个学生的全部课程和成绩
{
    int id;
    printf("请输入要查询的学生学号：\n");
    getid;
    Idtrue
    {
        for (int i=0; i<50; i++) 
        {
            if (STU.score[i].right == 'y') 
            printf("课程：%s\t分数：%d\n", classes[i].class_name, STU.score[i].score);
        }
        printf("查询完毕\n");
    }
    else printf("没有该生\n");
}

void DeleteStuClass ()
// 删除学生的某个课程
{
    int id;
    printf("请输入要删除课程的学生学号：\n");
    getid;
    Idtrue
    {
        printf("请确认是否要进行删除操作(y为确认\\n为取消)：\n");
        char selete;
        scanf("%c", &selete);
        if (selete == 'y')
        {
            int class_id;
            getclass_id;
            STU.score[C_ID(class_id)].right = 'n';
            printf("已删除\n");
        }
        else printf("已取消\n");
    }
    else printf("没有该生\n");
}

void DeleteStuAllClass ()
// 删除一个学生的全部课程
{
    int id;
    printf("请输入要删除课程的学生学号：\n");
    getid;
    Idtrue
    {
        printf("请确认是否要进行删除操作(y为确认\\n为取消)：\n");
        char selete;
        scanf("%c", &selete);
        if (selete == 'y')
        {
            int class_id;
            getclass_id;
            for (int i=0; i<50; i++)
            STU.score[i].right = 'n';
            printf("已删除\n");
        }
        else printf("已取消\n");
    }
    else printf("没有该生\n");
}

void Sum_GPA ()
// 绩点
{
    int gpa = 0;
    int id;
    printf("请输入要查询的学生学号：\n");
    getid;
    Idtrue
    {
        for (int i=0; i<50; i++)
        {
            if (STU.score[i].right == 'y') gpa += STU.score[i].score * classes[i].credit;
        }
        printf("%s的总绩点：%d\n", STU.name, (gpa-50)/10);
        printf("查询完毕\n");
    }
    else printf("没有该生\n");
}

void GPA ()
// 平均绩点
{
    int gpa = 0;
    int id;
    printf("请输入要查询的学生学号：\n");
    getid;
    Idtrue
    {
        int n=0;
        for (int i=0; i<50; i++)
        {
            if (STU.score[i].right == 'y') 
            {
                gpa += STU.score[i].score * classes[i].credit;
                n += classes[i].credit;
            }
        }
        printf("%s的平均绩点：%d\n", STU.name, ((gpa-50)/10));
        printf("查询完毕\n");
    }
    else printf("没有该生\n");
}

void Fail ()
// 挂科的课程及成绩
{
    int id;
    getid;
    Idtrue
    {
        printf("%s挂科的课程及成绩：\n", STU.name);
        for (int i=0; i<50; i++)
        {
            if (STU.score[i].right == 'y' && STU.score[i].score<60) printf("%s\t分数：%d\n", classes[i].class_name, STU.score[i].score);
        }
        printf("查询完毕\n");
    }
    else printf("没有该生\n");
}







// 以下为 课程数组 操作

void InsertClass ()
// 添加课程
{
    int class_id;
    printf("请依次输入你要添加的课程id，课程名，先行课id，学分：\n");
    getclass_id;getchar();
    gets(CLA.class_name);
    scanf("%d", &CLA.pre);getchar();
    scanf("%d", &CLA.credit);getchar();
    CLA.right = 'y';
    printf("录入完毕\n");
}

void FindClass ()
// 查询课程信息
{
    int class_id;
    printf("请输入要查询的课程id：\n");
    getclass_id;
    Class_idtrue
    {
        printf("以下是课程的信息：\n");
        printf("课程名：%s\n", CLA.class_name);
        printf("先行课id：%d\n", CLA.pre);
        printf("学分：%d\n", CLA.credit);
        printf("查询完毕\n");
    }
    else printf("没有此课程\n");
}

void FindClassAllStu ()
// 查询课程所有学生及成绩
{
    int class_id;
    printf("请输入要查询的课程id：\n");
    getclass_id;
    Class_idtrue
    {
        printf("选了%s的学生及成绩：\n", CLA.class_name);
        for (int i=0; i<1000; i++)
        {
            if (students[i].right == 'y' && students[i].score[C_ID(i)].right == 'y')
            {
                printf("%s\t分数：%d\n", students[i].name, students[i].score[C_ID(i)].score);
            }
        }
        printf("查询完毕\n");
    }
    else printf("没有此课程！\n");
}

void DeleteClass ()
// 删除课程
{
    int class_id;
    printf("请输入要删除的课程id：\n");
    getclass_id;getchar();
    Class_idtrue
    {
        char selete;
        printf("请确认是否要进行此操作！(y为是，n为否)\n");
        scanf("%c", &selete);
        if (selete == 'y')
        {
            classes[C_ID(class_id)].right = 'n';
            for (int i=0; i<1000; i++) students[i].score[C_ID(class_id)].right = 'n';
            printf("已删除\n");
        }
        else printf("已取消\n");
    }
    else printf("没有此课程\n");
}








// 以下是 交互 操作

void Screen ()
{
    int num;
    printf("学生课程管理系统\n");
    printf("q或Q关闭系统：\n");
    printf(star"\n");
    printf("101.添加学生信息\t102.删除学生信息\t103.修改学生信息\t104.查询学生信息\n");
    printf("201.添加课程信息\t202.删除课程信息\t203.修改课程信息\n");
    printf("301.录入学生课程\n");
    printf("401.查询学生所有课程及成绩\t402.查询课程中所有学生及成绩\n");
    printf("403.查询学生绩点\t404查询学生平均绩点\n");
    printf("405.查询学生平均绩点排名\t406.查询学生课程排名\t407.查询课程学生排名\n");
    printf("408.查询学生挂科科目\n");
    printf("501.保存更改\n");
    printf(star"\n");
    
    scanf("%d", &num);getchar();
    switch (num)
    {
        case 101:
        {
            InsertStu();break;
        }
        case 103:
        {
            int i;
            printf("请输入要修改的内容(1.学号,2.姓名,3.年龄,4.性别,5.院系,6.)：\n");
            scanf("%d",&i);getchar();
            switch(i)
            {
                case 1: 
                {
                    ChangStuId();break;
                }
                case 2:
                {
                    ChangStuName();break;
                }
                case 3:
                {
                    ChangStuAge();break;
                }
                case 4:
                {
                    ChangStuSex();break;
                }
                case 5:
                {
                    ChangStuF();break;
                }
            }
            break;
        }
        case 102:
        {
            DeleteId();break;
        }
        case 104:
        {
            printf("选择根据学号还是姓名查询(i为学号,n为姓名)：\n");
            char select;
            select = getchar();getchar();
            if (select == 'i') FindStuById();
            else FindStuByName();
            break;
        }
        case 201:
        case 203:
        {
            InsertClass();break;
        }
        case 202:
        {
            DeleteClass();break;
        }
        case 301:
        {
            InsertStuClass();break;
        }
        case 401:
        {
            FindStuAllClass();break;
        }
        case 402:
        {
            FindClassAllStu();break;
        }
        case 403:
        {
            Sum_GPA();break;
        }
        case 404:
        {
            GPA();break;
        }
        case 408:
        {
            Fail();break;
        }
        case 501:
        {
            WriteStu();
            WriteClass();
            break;
        }
    }
    printf("%d\n",num);
    while ((char)num != 'q' && (char)num != 'Q') Screen();
    return;
}

int main()
{
    ReadStu();
    ReadClass();
    Screen();
}