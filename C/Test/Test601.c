#include <stdio.h>
#include <stdlib.h>

struct Age
{
    int age;
    // �洢����
    int num;
    // �洢����
    struct Age* next;
};

void Pull(struct Age* head, int value, int n)
{
    // �������������Ϊ��Ϣ�����һ������ڵ�
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
// ��ӡ�����������
{
    struct Age* temp = head->next;
    while (temp != NULL)
    {
        printf("���䣺%d   ������%d\n", temp->age, temp->num);
        temp = temp->next;
    }
}

void InsertSort(int array[], int n)
// ��������
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
        // ���� i �� С�� �� i-1 ��ʱ, ��������, ֱ������һ����Ϊֹ.
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }
}

void ShellSort (int array[], int n)
// �ڲ�������Ļ����Ͻ���ϣ������ ���Ч��
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
// ͳ��ĳ������ͬ������
// ������������
// ����һ������ָ��
{
    struct Age head;
    head.next = NULL;
    // ����һ��������
    int x = 1;
    // ͳ�� ������ͬ������ ��ʼ��Ϊ1
    int y = array[0];
    // �洢 ����
    for (int i=0; i<n; i++)
    {
        if (array[i] == array[i+1])
        {
            x++;
            // ��� ����һ�� ��Ⱦ� +1
        }
        else 
        {
            // �� �򽫸��������������������
            Pull(&head, y, x);
            x = 1; 
            y = array[i+1];
        }
    }
    struct Age* temp = &head;
    return temp;
    // ��������ָ��
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
    // ��� ��� 18-24 ��������
    InsertSort(array, n);
    // ��������
    for (int i=0; i<n; i++)
    {
        printf("%4d", array[i]);
        while ((i+1)%10 == 0)
        {
            printf("\n");
            break;
        }
    }
    // ��ӡ ������ ����
    head = force(array, n);
    // ͳ��ͬ��������������� ����������
    Check(head);
    // ��������
}