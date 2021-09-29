#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define STUID id_stu-2020101300
#define CLSID id_cls+0
#define CHECKCLS if (class->stu_score[CLSID][0] == -1) return FALSE;
#define CHECKSTU if (class->stu_score[CLSID][STUID] == -1) return FALSE;

typedef int status;

typedef struct ClassDate {
    int num_Class;
    // 课程总数
    int num_Stu;
    // 学生总数
    int ** stu_score;
    // 二维数组
}ClassDate, *PtrClsDate ;

PtrClsDate InitClassDate (int num_Stu, int num_Class) {
    // 初始化一个新的班级课程表
    PtrClsDate class = (PtrClsDate)malloc(sizeof(ClassDate));
    class->num_Class = 0; class->num_Stu = 0;
    // 目前的课程和学生人数均为0
    class->stu_score = (int**)malloc(num_Class*sizeof(int*));
    for (int i=0; i<num_Class; i++) class->stu_score[i] = (int*)malloc(num_Stu*sizeof(int));
    for (int i=0 ;i<num_Class; i++) {
        for (int j=0; j<num_Stu; j++) class->stu_score[i][j] = -1;
        // -1代表不存在成绩或者课程
    }
    return class;
}

status addCls (PtrClsDate class, int id_cls) {
    // 添加课程
    // 将标志设为1，代表此课程存在了
    class->stu_score[CLSID][0] = 1; return TRUE;
}

status addStuScore (PtrClsDate class, int id_cls, int id_stu, int score) {
    // 添加学生成绩
    CHECKCLS
    // 检查课程是否存在，下面均是
    class->stu_score[CLSID][STUID] = score; return TRUE;
    // 设置程序
}

status delCls (PtrClsDate class, int id_cls) {
    // 删除课程
    class->stu_score[CLSID][0] = -1; return TRUE;
    // 将标记设为-1
}

status delStuScore (PtrClsDate class, int id_cls, int id_stu) {
    // 删除某个课程的某个学生的成绩
    CHECKCLS
    class->stu_score[CLSID][STUID] = -1; return TRUE;
    // 将标记设为-1
}

status delStu (PtrClsDate class, int id_stu) {
    // 删除整个学生所以课程的成绩
    for (int i=0; i<class->num_Class; i++) class->stu_score[i][STUID] = -1;
}

int getStuScore (PtrClsDate class, int id_cls, int id_stu) {
    // 获得某个学生的某个课程的成绩
    CHECKCLS
    CHECKSTU
    return class->stu_score[CLSID][STUID];
}


int Screen () {
    // 交互界面
    int num_Cls = 0; int num_Stu = 0;
    printf("请输入要初始化的学生总数和课程总数：（例如 60,30）\n");
    scanf("%d, %d", &num_Cls, &num_Stu); getchar();
    PtrClsDate class = InitClassDate(num_Cls, num_Stu);
    int id_cls = 0; int id_stu = 0; int score = 0;
    while (1)
    {
        printf("请输入要进行的操作（0停止）：\n");
        printf("101 添加课程\t102 添加学生成绩\n");
        printf("201 删除课程\t202 删除学生成绩\t 203 删除学生全部成绩\n");
        printf("301 获取学生成绩\n");
        int num = 0; scanf("%d", &num); getchar();
        switch (num) {
        case 101: 
            printf("请输入要增加的课程id：\n");
            scanf("%d", &id_cls); getchar();
            if (addCls(class, id_cls)) printf("添加成功！\n"); 
            break;
        case 102: 
            printf("请输入要增加的学生课程和学生id和学生成绩：\n");
            scanf("%d, %d, %d", &id_cls, &id_stu, &score);
            if (addStuScore(class, id_cls, id_stu, score)) printf("添加成功！\n");
            else printf("无此课程！\n");
            break;
        case 201:
            printf("请输入要删除的学生课程：\n");
            scanf("%d", &id_cls);getchar();
            delCls(class, id_cls);
            printf("删除成功！\n");
            break;
        case 202:
            printf("请输入要删除的学生课程和学生id：\n");
            scanf("%d,%d", &id_cls, &id_stu);
            delStuScore(class, id_cls, id_stu);
            printf("删除成功！\n");
            break;
        case 203:
            printf("请输入要删除的学生id：\n");
            scanf("%d", &id_stu);
            delStu(class, id_stu);
            printf("删除成功！\n");
            break;
        case 301:
            printf("请输入要查询的学生课程和学生id：\n");
            scanf("%d, %d", &id_cls, &id_stu);
            printf("成绩：%d\n", getStuScore(class, id_cls, id_stu));
            break;
        default:
            return 0;
        }
    }
}

int main () {
    Screen();
}