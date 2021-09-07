#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 //������100��elemtype//
#define SIZE_ADD 10        //�࿪10��elemtype//

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int elemtype;
typedef int status;
typedef struct sqlist
{
    elemtype *pt; /*pt��˳����ַ  length�ǵ�ǰ˳���ĳ���  list_size�ǵ�ǰ˳��������*/
    elemtype length;
    elemtype list_size;
} sqlist;
typedef struct sqlist *sqlistptr;

status InitList(sqlistptr ptrlist1)
{ //��ʼ��˳�����//
    ptrlist1->pt = (elemtype *)malloc(LIST_INIT_SIZE * sizeof(elemtype));
    if (!ptrlist1->pt)
    {
        exit(OVERFLOW); //ȷ�Ͽռ�ɹ�����//
    }
    else
    {
        ptrlist1->length = 0; //���ƽṹ����Ϣ//
        ptrlist1->list_size = LIST_INIT_SIZE;
    }
    return OK;
}

status ListInsert(sqlistptr ptrlist1, elemtype i, elemtype e)
{ //Ԫ�ز��뺯��//

    elemtype *q1, *q2;
    if (i < 1 || i > ptrlist1->length + 1)
    {
        printf("i���Ϸ���\n"); //i���Ϸ������//
        return ERROR;
    }
    else if (ptrlist1->length >= ptrlist1->list_size)
    {
        elemtype *newbase;
        newbase = (elemtype *)realloc(ptrlist1->pt, (SIZE_ADD + LIST_INIT_SIZE) * sizeof(elemtype));
        //�����ٵĿռ䲻����������ĳ���ʱ//
        if (!newbase)
        {
            exit(OVERFLOW);
        }
        ptrlist1->pt = newbase;
        ptrlist1->list_size += SIZE_ADD;
    }

    q1 = &ptrlist1->pt[i - 1]; //��ȡ�����е�i��Ԫ�صĵ�ַ��//
    if (ptrlist1->length)
    {
        q2 = &ptrlist1->pt[ptrlist1->length - 1]; //��ȡ�����б�βԪ�صĵ�ַ//
        for (; q1 <= q2; q2--)
        {
            *(q2 + 1) = *(q2); //������ǿձ���ֱ�Ӳ������//
        }
    }
    *(q1) = e;
    ptrlist1->length++;
    return OK;
}

status ListDelete(sqlistptr ptrlist1, elemtype i, elemtype *e_ptr)
{
    if (i < 1 || i > ptrlist1->length)
    {
        printf("����i���Ϸ���\n");
        return ERROR;
    }
    else
    {
        *(e_ptr) = ptrlist1->pt[i - 1];
        for (; i < ptrlist1->length; i++)
        {
            ptrlist1->pt[i - 1] = ptrlist1->pt[i];
        }
        ptrlist1->length--;
    }
    return OK;
}

status ListEmpty(sqlist list1)
{ //�жϱ�պ�����//
    if (list1.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

status ListLength(sqlist list1)
{ //�������//
    if (list1.length == 0)
    {
        return ERROR;
    }
    else
    {
        return list1.length;
    }
}

status GetElem(sqlist list1, elemtype i, elemtype *e_ptr)
{
    if (i < 1 || i > list1.length)
    {
        return ERROR;
    }
    else
    {
        *(e_ptr) = list1.pt[i - 1];
        return *(e_ptr);
    }
}

status PriorElem(sqlist list1, elemtype cur_e, elemtype *pre_e_ptr)
{
    elemtype i;
    for (i = 1; i <= list1.length; i++)
    {
        if (cur_e == list1.pt[i - 1])
        {
            if (i == 1)
            {
                return ERROR;
            }
            else
            {
                *(pre_e_ptr) = list1.pt[i - 2];
                return OK;
            }
        }
    }
    if (i > list1.length)
    {
        printf("�����޴�Ԫ�أ�\n");
        return ERROR;
    }
}

status NextElem(sqlist list1, elemtype cur_e, elemtype *next_e_ptr)
{
    elemtype i;
    for (i = 1; i <= list1.length; i++)
    {
        if (cur_e == list1.pt[i - 1])
        {
            if (i == list1.length)
            {
                return ERROR;
            }
            else
            {
                *(next_e_ptr) = list1.pt[i];
                return OK;
            }
        }
    }
    if (i > list1.length)
    {
        printf("�����޴�Ԫ�أ�\n");
        return ERROR;
    }
}

elemtype LocateElem(sqlist list1, elemtype e, elemtype (*p)())
{
    elemtype i;
    for (i = 1; i <= list1.length; i++)
    {
        if ((*p)(e, list1.pt[i - 1]))
        {
            return i;
        }
    }
    if (i > list1.length)
    {
        return 0;
    }
}

elemtype ClearList(sqlistptr ptrlist1)
{
    ptrlist1->length = 0;
    return OK;
}

elemtype DestroyList(sqlistptr ptrlist1)
{
    free(ptrlist1->pt);
    return OK;
}

int main()
{
    elemtype stone;
    sqlist list1;                //����һ���ṹ�崢��˳������Ϣ//
    sqlistptr ptrlist1 = &list1; //����һ���ṹ��ָ��   �洢�ṹ���ַ//

    stone = InitList(ptrlist1); //���ٿձ�    stone�Ǽ��麯����������//
    if (stone)
    {
        printf("�ձ�ɹ���ʼ��\n");
    }
    else
    {
        printf("�ձ���ʧ��\n");
    }

    elemtype i, count;
    elemtype e;
    printf("������Ҫ����ձ�ĸ�����\n");
    scanf("%d", &count);
    for (i = 1; i <= count; i++)
    {
        printf("��%d��Ԫ���ǣ�", i);
        scanf("%d", &e);
        stone = ListInsert(ptrlist1, i, e); //��˳�����Ԫ�أ�//
                                            /* ˳�����Ԫ�� */
        if (!stone)
        {
            printf("��Ӵ���\n");
            break;
        }
        else
        {
            printf("��ӳɹ�   ��ʱ˳�����Ϊ ��%d\n", list1.length);
        }
    }

    printf("��������ɾ����Ԫ��λ�� ��\n");
    scanf("%d", &i);
    stone = ListDelete(ptrlist1, i, &e); //ɾ��˳����i��Ԫ�غ���//
    if (!stone)
    {
        printf("���ִ���\n");
    }
    else
    {
        printf("ɾ���ɹ�����ʱ˳�������%d,��ɾ��Ԫ��Ϊ%d\n", ptrlist1->length, e);
    }

    stone = ListEmpty(list1);
    if (stone)
    {
        printf("�ñ�Ϊ�գ�\n"); //�жϱ��Ƿ�Ϊ��  ��output����//
    }
    else
    {
        printf("�ñ�Ϊ��,�ұ�Ϊ%d\n", ListLength(list1));
    }

    printf("������Ҫ��ȡԪ�ص�λ�� ��\n");
    scanf("%d", &i);
    e = GetElem(list1, i, &e); //��ȡԪ�أ�//
    printf("��%d��Ԫ���� %d\n", i, e);

    /*for(i = 1; i <= list1.length ; i++){
       GetElem(list1,i,&e);
       printf("%d \t",e);
   }*/

    elemtype cur_e, pre_e;
    printf("������Ҫ��ȡĳԪ�ص�ǰһλԪ�� �� \n");
    scanf("%d", &cur_e);
    PriorElem(list1, cur_e, &pre_e); //���ǰһ��Ԫ��//
    printf("��Ԫ�ص�ǰһ��Ԫ���� ��%d\n", pre_e);

    elemtype next_e;
    printf("������Ҫ��ȡĳԪ�صĺ�һλԪ�� �� \n");
    scanf("%d", &cur_e);
    NextElem(list1, cur_e, &next_e); //�����һ��Ԫ��//
    printf("��Ԫ�صĺ�һ��Ԫ���� ��%d\n", next_e);

    elemtype select(elemtype, elemtype);
    printf("������һ������Ԫ��\n");
    scanf("%d", &e);
    printf("�����һ���ܱ�%d������Ԫ�أ�\n", e);
    stone = LocateElem(list1, e, select);
    if (!stone)
    {
        printf("�����ڸ���Ԫ�أ�\n");
    }
    else
    {
        printf("��Ԫ��λ�ڵ�%dλ\n", stone);
    }

    //����Ϊ�ձ�//
    ClearList(ptrlist1);
    if (ListEmpty(list1))
    {
        printf("�ñ��ѿգ�\n");
    }
    else
    {
        printf("����ʧ�ܣ�\n");
    }

    return 0;
}

//����ԭ��//
DestroyList(ptrlist1);

elemtype select(elemtype a, elemtype b)
{
    if (a % b == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}