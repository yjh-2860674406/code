#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 //能容纳100个elemtype//
#define SIZE_ADD 10        //多开10个elemtype//

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
    elemtype *pt; /*pt是顺序表地址  length是当前顺序表的长度  list_size是当前顺序表的容量*/
    elemtype length;
    elemtype list_size;
} sqlist;
typedef struct sqlist *sqlistptr;

status InitList(sqlistptr ptrlist1)
{ //初始化顺序表函数//
    ptrlist1->pt = (elemtype *)malloc(LIST_INIT_SIZE * sizeof(elemtype));
    if (!ptrlist1->pt)
    {
        exit(OVERFLOW); //确认空间成功开辟//
    }
    else
    {
        ptrlist1->length = 0; //完善结构体信息//
        ptrlist1->list_size = LIST_INIT_SIZE;
    }
    return OK;
}

status ListInsert(sqlistptr ptrlist1, elemtype i, elemtype e)
{ //元素插入函数//

    elemtype *q1, *q2;
    if (i < 1 || i > ptrlist1->length + 1)
    {
        printf("i不合法！\n"); //i不合法的情况//
        return ERROR;
    }
    else if (ptrlist1->length >= ptrlist1->list_size)
    {
        elemtype *newbase;
        newbase = (elemtype *)realloc(ptrlist1->pt, (SIZE_ADD + LIST_INIT_SIZE) * sizeof(elemtype));
        //当开辟的空间不能满足数组的长度时//
        if (!newbase)
        {
            exit(OVERFLOW);
        }
        ptrlist1->pt = newbase;
        ptrlist1->list_size += SIZE_ADD;
    }

    q1 = &ptrlist1->pt[i - 1]; //获取数组中第i个元素的地址！//
    if (ptrlist1->length)
    {
        q2 = &ptrlist1->pt[ptrlist1->length - 1]; //获取数组中表尾元素的地址//
        for (; q1 <= q2; q2--)
        {
            *(q2 + 1) = *(q2); //如果表是空表则直接插入表中//
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
        printf("输入i不合法！\n");
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
{ //判断表空函数！//
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
{ //输出表长！//
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
        printf("表中无此元素！\n");
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
        printf("表中无此元素！\n");
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
    sqlist list1;                //定义一个结构体储存顺序表的信息//
    sqlistptr ptrlist1 = &list1; //定义一个结构体指针   存储结构体地址//

    stone = InitList(ptrlist1); //开辟空表    stone是检验函数完成情况！//
    if (stone)
    {
        printf("空表成功初始化\n");
    }
    else
    {
        printf("空表建立失败\n");
    }

    elemtype i, count;
    elemtype e;
    printf("请输入要加入空表的个数：\n");
    scanf("%d", &count);
    for (i = 1; i <= count; i++)
    {
        printf("第%d个元素是；", i);
        scanf("%d", &e);
        stone = ListInsert(ptrlist1, i, e); //按顺序插入元素！//
                                            /* 顺序添加元素 */
        if (!stone)
        {
            printf("添加错误！\n");
            break;
        }
        else
        {
            printf("添加成功   此时顺序表长度为 ：%d\n", list1.length);
        }
    }

    printf("请输入想删除的元素位置 ：\n");
    scanf("%d", &i);
    stone = ListDelete(ptrlist1, i, &e); //删除顺序表第i个元素函数//
    if (!stone)
    {
        printf("出现错误！\n");
    }
    else
    {
        printf("删除成功！此时顺序表长度是%d,且删除元素为%d\n", ptrlist1->length, e);
    }

    stone = ListEmpty(list1);
    if (stone)
    {
        printf("该表为空！\n"); //判断表是否为空  并output表长！//
    }
    else
    {
        printf("该表不为空,且表长为%d\n", ListLength(list1));
    }

    printf("输入想要获取元素的位置 ：\n");
    scanf("%d", &i);
    e = GetElem(list1, i, &e); //获取元素！//
    printf("第%d个元素是 %d\n", i, e);

    /*for(i = 1; i <= list1.length ; i++){
       GetElem(list1,i,&e);
       printf("%d \t",e);
   }*/

    elemtype cur_e, pre_e;
    printf("输入想要获取某元素的前一位元素 ： \n");
    scanf("%d", &cur_e);
    PriorElem(list1, cur_e, &pre_e); //输出前一个元素//
    printf("该元素的前一个元素是 ；%d\n", pre_e);

    elemtype next_e;
    printf("输入想要获取某元素的后一位元素 ： \n");
    scanf("%d", &cur_e);
    NextElem(list1, cur_e, &next_e); //输出后一个元素//
    printf("该元素的后一个元素是 ；%d\n", next_e);

    elemtype select(elemtype, elemtype);
    printf("请输入一个关联元素\n");
    scanf("%d", &e);
    printf("输出第一个能被%d整除的元素！\n", e);
    stone = LocateElem(list1, e, select);
    if (!stone)
    {
        printf("不存在该类元素！\n");
    }
    else
    {
        printf("该元素位于第%d位\n", stone);
    }

    //重置为空表//
    ClearList(ptrlist1);
    if (ListEmpty(list1))
    {
        printf("该表已空！\n");
    }
    else
    {
        printf("重置失败！\n");
    }

    return 0;
}

//销毁原表//
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