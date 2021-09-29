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
    // �γ�����
    int num_Stu;
    // ѧ������
    int ** stu_score;
    // ��ά����
}ClassDate, *PtrClsDate ;

PtrClsDate InitClassDate (int num_Stu, int num_Class) {
    // ��ʼ��һ���µİ༶�γ̱�
    PtrClsDate class = (PtrClsDate)malloc(sizeof(ClassDate));
    class->num_Class = 0; class->num_Stu = 0;
    // Ŀǰ�Ŀγ̺�ѧ��������Ϊ0
    class->stu_score = (int**)malloc(num_Class*sizeof(int*));
    for (int i=0; i<num_Class; i++) class->stu_score[i] = (int*)malloc(num_Stu*sizeof(int));
    for (int i=0 ;i<num_Class; i++) {
        for (int j=0; j<num_Stu; j++) class->stu_score[i][j] = -1;
        // -1�������ڳɼ����߿γ�
    }
    return class;
}

status addCls (PtrClsDate class, int id_cls) {
    // ��ӿγ�
    // ����־��Ϊ1������˿γ̴�����
    class->stu_score[CLSID][0] = 1; return TRUE;
}

status addStuScore (PtrClsDate class, int id_cls, int id_stu, int score) {
    // ���ѧ���ɼ�
    CHECKCLS
    // ���γ��Ƿ���ڣ��������
    class->stu_score[CLSID][STUID] = score; return TRUE;
    // ���ó���
}

status delCls (PtrClsDate class, int id_cls) {
    // ɾ���γ�
    class->stu_score[CLSID][0] = -1; return TRUE;
    // �������Ϊ-1
}

status delStuScore (PtrClsDate class, int id_cls, int id_stu) {
    // ɾ��ĳ���γ̵�ĳ��ѧ���ĳɼ�
    CHECKCLS
    class->stu_score[CLSID][STUID] = -1; return TRUE;
    // �������Ϊ-1
}

status delStu (PtrClsDate class, int id_stu) {
    // ɾ������ѧ�����Կγ̵ĳɼ�
    for (int i=0; i<class->num_Class; i++) class->stu_score[i][STUID] = -1;
}

int getStuScore (PtrClsDate class, int id_cls, int id_stu) {
    // ���ĳ��ѧ����ĳ���γ̵ĳɼ�
    CHECKCLS
    CHECKSTU
    return class->stu_score[CLSID][STUID];
}


int Screen () {
    // ��������
    int num_Cls = 0; int num_Stu = 0;
    printf("������Ҫ��ʼ����ѧ�������Ϳγ������������� 60,30��\n");
    scanf("%d, %d", &num_Cls, &num_Stu); getchar();
    PtrClsDate class = InitClassDate(num_Cls, num_Stu);
    int id_cls = 0; int id_stu = 0; int score = 0;
    while (1)
    {
        printf("������Ҫ���еĲ�����0ֹͣ����\n");
        printf("101 ��ӿγ�\t102 ���ѧ���ɼ�\n");
        printf("201 ɾ���γ�\t202 ɾ��ѧ���ɼ�\t 203 ɾ��ѧ��ȫ���ɼ�\n");
        printf("301 ��ȡѧ���ɼ�\n");
        int num = 0; scanf("%d", &num); getchar();
        switch (num) {
        case 101: 
            printf("������Ҫ���ӵĿγ�id��\n");
            scanf("%d", &id_cls); getchar();
            if (addCls(class, id_cls)) printf("��ӳɹ���\n"); 
            break;
        case 102: 
            printf("������Ҫ���ӵ�ѧ���γ̺�ѧ��id��ѧ���ɼ���\n");
            scanf("%d, %d, %d", &id_cls, &id_stu, &score);
            if (addStuScore(class, id_cls, id_stu, score)) printf("��ӳɹ���\n");
            else printf("�޴˿γ̣�\n");
            break;
        case 201:
            printf("������Ҫɾ����ѧ���γ̣�\n");
            scanf("%d", &id_cls);getchar();
            delCls(class, id_cls);
            printf("ɾ���ɹ���\n");
            break;
        case 202:
            printf("������Ҫɾ����ѧ���γ̺�ѧ��id��\n");
            scanf("%d,%d", &id_cls, &id_stu);
            delStuScore(class, id_cls, id_stu);
            printf("ɾ���ɹ���\n");
            break;
        case 203:
            printf("������Ҫɾ����ѧ��id��\n");
            scanf("%d", &id_stu);
            delStu(class, id_stu);
            printf("ɾ���ɹ���\n");
            break;
        case 301:
            printf("������Ҫ��ѯ��ѧ���γ̺�ѧ��id��\n");
            scanf("%d, %d", &id_cls, &id_stu);
            printf("�ɼ���%d\n", getStuScore(class, id_cls, id_stu));
            break;
        default:
            return 0;
        }
    }
}

int main () {
    Screen();
}