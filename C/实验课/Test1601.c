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

// ����Ϊ ѧ����Ϣ �Ĳ���

void InsertStu ()
// ¼��ѧ��
{
    int id;
    printf("��������������ѧ�ţ��������Ա����䣬Ժϵ:\n");
    getid;getchar();
    gets(STU.name);
    scanf("%c", &STU.sex);getchar();
    scanf("%d", &STU.age);getchar();
    gets(STU.faculty);
    students[ID(id)].right = 'y';
    printf("¼�����\n");
    clock_t finish = clock();
}

void FindStuById ()
// ͨ��ѧ�Ų�ѯѧ����Ϣ
{
    int id;
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
    getid;
    if (STU.right == 'y')
    {
        printf("������ѧ������Ϣ��\n");
        printf("������%s\n", STU.name);
        printf("�Ա�%c\n", STU.sex);
        printf("���䣺%d\n", STU.age);
        printf("Ժϵ��%s\n", STU.faculty);
        printf("��ѯ���\n");
    }
    else printf("���޴���\n");
}

void FindStuByName ()
// ͨ��������ѯѧ����Ϣ
{
    char names[10];
    int id;
    int num = 0;
    printf("������Ҫ��ѯ��ѧ��������\n");
    puts(names);
    for (int i=0; i<1000; i++)
    {
        if (strcmp(students[i].name, names)) 
        {
            id = i+2020101000;
            printf("������ѧ������Ϣ��\n");
            printf("������%s\n", STU.name);
            printf("ѧ�ţ�%d\n", id);
            printf("�Ա�%c\n", STU.sex);
            printf("���䣺%d\n", STU.age);
            printf("Ժϵ��%s\n", STU.faculty);
            printf("��ѯ���\n");
            num ++;
        }
    }
    if (num == 0) printf("���޴���\n");
}

void ChangStuId ()
// �ı�ѧ����id
{
    char names[10];
    int id;
    int num = 0;
    printf("������Ҫ�޸ĵ�ѧ��������\n");
    puts(names);
    for (int i=0; i<1000; i++)
    {
        if (strcmp(students[i].name, names)) 
        {
            printf("�������޸ĺ��ѧ��ѧ�ţ�\n");
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
            printf("�޸ĳɹ�\n");
        }
    }
    if (num == 0) printf("���޴���\n");
}

void ChangStuName ()
// �޸�����
{
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    getid;getchar();
    Idtrue
    {
        printf("������Ҫ�޸ĵ�������\n");
        gets(STU.name);
        printf("�޸����\n");
    }
    else printf("���޴���\n");
}

void ChangStuAge ()
// �޸�����
{
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        printf("������Ҫ�޸ĵ����䣺\n");
        scanf("%d", &STU.age);getchar();
        printf("�޸����\n");
    }
    else printf("���޴���\n");
}

void ChangStuSex ()
// �޸��Ա�
{
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        if (STU.sex == 'm') STU.sex = 'f';
        else STU.sex = 'm';
        printf("�޸����\n");
    }
    else printf("���޴���\n");
}

void ChangStuF ()
// �޸�Ժϵ
{
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        printf("������Ҫ�޸ĵ�Ժϵ��\n");
        gets(STU.faculty);
        printf("�޸����\n");
    }
    else printf("���޴���\n");
}

void DeleteId ()
// ɾ��ѧ��
{
    int id;
    printf("������Ҫɾ����ѧ��ѧ�ţ�\n");
    getid;getchar();
    printf("��ȷ��Ҫ���д˲�����(yΪȷ�ϣ�nΪȡ��)\n");
    char selete;
    scanf("%c", &selete);
    if (selete == 'y')
    {
        STU.right = 'n';
        printf("��ɾ��");
    }
    else printf("��ȡ��");
}

void InsertStuClass ()
// ��ѧ��¼��γ̺ͳɼ�
{
    int id;
    printf("������Ҫ¼��γ̵�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        int class_id;
        printf("������Ҫ¼��Ŀγ�id��\n");
        getclass_id;
        Class_idtrue
        {
            printf("������%s��%s�ĳɼ���\n", STU.name, CLA.class_name);
            int score;
            scanf("%d", &score);
            STU.score[C_ID(class_id)].score = score;
            STU.score[C_ID(class_id)].right = 'y';
            printf("¼�����\n");
        }
        else printf("û�д˿γ̣�");
    }
    else printf("û�и���");
}

void FindStuAllClass ()
// ��ѯһ��ѧ����ȫ���γ̺ͳɼ�
{
    int id;
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        for (int i=0; i<50; i++) 
        {
            if (STU.score[i].right == 'y') 
            printf("�γ̣�%s\t������%d\n", classes[i].class_name, STU.score[i].score);
        }
        printf("��ѯ���\n");
    }
    else printf("û�и���\n");
}

void DeleteStuClass ()
// ɾ��ѧ����ĳ���γ�
{
    int id;
    printf("������Ҫɾ���γ̵�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        printf("��ȷ���Ƿ�Ҫ����ɾ������(yΪȷ��\\nΪȡ��)��\n");
        char selete;
        scanf("%c", &selete);
        if (selete == 'y')
        {
            int class_id;
            getclass_id;
            STU.score[C_ID(class_id)].right = 'n';
            printf("��ɾ��\n");
        }
        else printf("��ȡ��\n");
    }
    else printf("û�и���\n");
}

void DeleteStuAllClass ()
// ɾ��һ��ѧ����ȫ���γ�
{
    int id;
    printf("������Ҫɾ���γ̵�ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        printf("��ȷ���Ƿ�Ҫ����ɾ������(yΪȷ��\\nΪȡ��)��\n");
        char selete;
        scanf("%c", &selete);
        if (selete == 'y')
        {
            int class_id;
            getclass_id;
            for (int i=0; i<50; i++)
            STU.score[i].right = 'n';
            printf("��ɾ��\n");
        }
        else printf("��ȡ��\n");
    }
    else printf("û�и���\n");
}

void Sum_GPA ()
// ����
{
    int gpa = 0;
    int id;
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
    getid;
    Idtrue
    {
        for (int i=0; i<50; i++)
        {
            if (STU.score[i].right == 'y') gpa += STU.score[i].score * classes[i].credit;
        }
        printf("%s���ܼ��㣺%d\n", STU.name, (gpa-50)/10);
        printf("��ѯ���\n");
    }
    else printf("û�и���\n");
}

void GPA ()
// ƽ������
{
    int gpa = 0;
    int id;
    printf("������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
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
        printf("%s��ƽ�����㣺%d\n", STU.name, ((gpa-50)/10));
        printf("��ѯ���\n");
    }
    else printf("û�и���\n");
}

void Fail ()
// �ҿƵĿγ̼��ɼ�
{
    int id;
    getid;
    Idtrue
    {
        printf("%s�ҿƵĿγ̼��ɼ���\n", STU.name);
        for (int i=0; i<50; i++)
        {
            if (STU.score[i].right == 'y' && STU.score[i].score<60) printf("%s\t������%d\n", classes[i].class_name, STU.score[i].score);
        }
        printf("��ѯ���\n");
    }
    else printf("û�и���\n");
}







// ����Ϊ �γ����� ����

void InsertClass ()
// ��ӿγ�
{
    int class_id;
    printf("������������Ҫ��ӵĿγ�id���γ��������п�id��ѧ�֣�\n");
    getclass_id;getchar();
    gets(CLA.class_name);
    scanf("%d", &CLA.pre);getchar();
    scanf("%d", &CLA.credit);getchar();
    CLA.right = 'y';
    printf("¼�����\n");
}

void FindClass ()
// ��ѯ�γ���Ϣ
{
    int class_id;
    printf("������Ҫ��ѯ�Ŀγ�id��\n");
    getclass_id;
    Class_idtrue
    {
        printf("�����ǿγ̵���Ϣ��\n");
        printf("�γ�����%s\n", CLA.class_name);
        printf("���п�id��%d\n", CLA.pre);
        printf("ѧ�֣�%d\n", CLA.credit);
        printf("��ѯ���\n");
    }
    else printf("û�д˿γ�\n");
}

void FindClassAllStu ()
// ��ѯ�γ�����ѧ�����ɼ�
{
    int class_id;
    printf("������Ҫ��ѯ�Ŀγ�id��\n");
    getclass_id;
    Class_idtrue
    {
        printf("ѡ��%s��ѧ�����ɼ���\n", CLA.class_name);
        for (int i=0; i<1000; i++)
        {
            if (students[i].right == 'y' && students[i].score[C_ID(i)].right == 'y')
            {
                printf("%s\t������%d\n", students[i].name, students[i].score[C_ID(i)].score);
            }
        }
        printf("��ѯ���\n");
    }
    else printf("û�д˿γ̣�\n");
}

void DeleteClass ()
// ɾ���γ�
{
    int class_id;
    printf("������Ҫɾ���Ŀγ�id��\n");
    getclass_id;getchar();
    Class_idtrue
    {
        char selete;
        printf("��ȷ���Ƿ�Ҫ���д˲�����(yΪ�ǣ�nΪ��)\n");
        scanf("%c", &selete);
        if (selete == 'y')
        {
            classes[C_ID(class_id)].right = 'n';
            for (int i=0; i<1000; i++) students[i].score[C_ID(class_id)].right = 'n';
            printf("��ɾ��\n");
        }
        else printf("��ȡ��\n");
    }
    else printf("û�д˿γ�\n");
}








// ������ ���� ����

void Screen ()
{
    int num;
    printf("ѧ���γ̹���ϵͳ\n");
    printf("q��Q�ر�ϵͳ��\n");
    printf(star"\n");
    printf("101.���ѧ����Ϣ\t102.ɾ��ѧ����Ϣ\t103.�޸�ѧ����Ϣ\t104.��ѯѧ����Ϣ\n");
    printf("201.��ӿγ���Ϣ\t202.ɾ���γ���Ϣ\t203.�޸Ŀγ���Ϣ\n");
    printf("301.¼��ѧ���γ�\n");
    printf("401.��ѯѧ�����пγ̼��ɼ�\t402.��ѯ�γ�������ѧ�����ɼ�\n");
    printf("403.��ѯѧ������\t404��ѯѧ��ƽ������\n");
    printf("405.��ѯѧ��ƽ����������\t406.��ѯѧ���γ�����\t407.��ѯ�γ�ѧ������\n");
    printf("408.��ѯѧ���ҿƿ�Ŀ\n");
    printf("501.�������\n");
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
            printf("������Ҫ�޸ĵ�����(1.ѧ��,2.����,3.����,4.�Ա�,5.Ժϵ,6.)��\n");
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
            printf("ѡ�����ѧ�Ż���������ѯ(iΪѧ��,nΪ����)��\n");
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