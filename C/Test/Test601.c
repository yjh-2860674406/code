#include <stdio.h>
#include <stdlib.h>

struct Age
{
    int age;
    // 存储年龄
    int num;
    // 存储人数
    struct Age* next;
};

void Pull(struct Age* head, int value, int n)
{
    // 将年龄和人数作为信息域添加一个链表节点
    while (head->next != NULL)
    {
        head = head->next;
    }
    if (head->next == NULL)
    {
        struct Age* temp = (struct Age*)malloc(sizeof(struct Age));
        head->next = temp;
        temp->age = value;
        temp->num = n;
        temp->next = NULL;
    }
}

void Check (struct Age* head)
// 打印出年龄和人数
{
    struct Age* temp = head->next;
    while (temp != NULL)
    {
        printf("年龄：%d   人数：%d\n", temp->age, temp->num);
        temp = temp->next;
    }
}

void InsertSort(int array[], int n)
// 插入排序
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
        // 当第 i 个 小于 第 i-1 个时, 启动排序, 直到比下一个大为止.
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }
}

void ShellSort (int array[], int n)
// 在插入排序的基础上进行希尔排序 提高效率
{
    int temp = n;
    do
    {
        temp = (temp/3)+1;
        for (int i=1; i<n; i+=temp)
        {
            for (int j=i; j>0&&array[j]<array[j-temp]; j-=temp)
            {
                int m = array[j];
                array[j] = array[j-=temp];
                array[j-=temp] = m;
            }            
        }
    } while (temp==1);
    InsertSort(array, n);
}

struct Age* force (int array[], int n)
// 统计某年龄相同的人数
// 并加入链表中
// 返回一个链表指针
{
    struct Age head;
    head.next = NULL;
    // 创建一个空链表
    int x = 1;
    // 统计 年龄相同的人数 初始化为1
    int y = array[0];
    // 存储 年龄
    for (int i=0; i<n; i++)
    {
        if (array[i] == array[i+1])
        {
            x++;
            // 如果 和下一个 相等就 +1
        }
        else 
        {
            // 否 则将该年龄和人数加入链表中
            Pull(&head, y, x);
            x = 1; 
            y = array[i+1];
        }
    }
    struct Age* temp = &head;
    return temp;
    // 返回链表指针
}

int main()
{
    struct Age* head;
    int n = 30000;
    int array[n];
    for (int i=0; i<n; i++)
    {
        array[i] = rand()%7+18;
    }
    // 随机 添加 18-24 进入数组
    InsertSort(array, n);
    // 插入排序
    for (int i=0; i<n; i++)
    {
        printf("%4d", array[i]);
        while ((i+1)%10 == 0)
        {
            printf("\n");
            break;
        }
    }
    // 打印 排序后的 数组
    head = force(array, n);
    // 统计同年龄的人数和年龄 加入链表中
    Check(head);
    // 便利链表
}