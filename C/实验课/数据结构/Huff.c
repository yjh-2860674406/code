#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct
{
    int w;
    int p;
    int l;
    int r;
} Node, *PtrNode;

typedef struct
{
    Node nodes[20];
    int length;
} Huff, *PtrHuff;

typedef struct
{
    char *array;
    int length;
    int size;
    int *w;
} Word, *PtrWord;

typedef struct
{
    char best[10];
    int len;
} Best, *PtrBest;

PtrWord InitWords()
{
    // ��ʼ�� words
    // ԭ�Ӳ���
    PtrWord words = (PtrWord)malloc(sizeof(Word));
    // �����ڴ�

    words->size = 10;
    words->array = (char *)malloc(10 * sizeof(char));
    words->w = (int *)malloc(sizeof(int));
    words->length = 1;
    // ��ʼ������

    return words;
}

void JudgeSize(PtrWord words)
{
    // �ж��Ƿ��������������ӳ���
    // ԭ�Ӳ���
    if (words->length > words->size)
    {
        // ��ʼ������
        words->size += 10;
        words->array = (char *)realloc(words->array, words->size * sizeof(char));
        words->w = (int *)realloc(words->w, words->size * sizeof(int));
    }
}

PtrWord getWords()
{
    // ���������� words
    // ��ԭ�Ӳ���
    PtrWord words = InitWords();
    int w;
    char word;
    while (printf("��������ĸ����Ȩֵ(��ĸ,Ȩֵ):\n"), scanf("%c,%d", &word, &w), getchar(),
           word != '0')
    {
        if (word == '#')
            continue;

        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z'))
        {
            JudgeSize(words); // �жϳ��ȣ��Ƿ���Ҫ��ӿռ�

            words->array[words->length] = word;
            words->w[words->length] = w;
            words->length++;
        }
        else
        {
            printf("�������!���������(��ʽ:��ĸ,Ȩֵ)\n");
        }
    }

    return words;
}

void Set(PtrHuff huff, int start, int end)
{
    // ���½ڵ�
    // ԭ�Ӳ���
    for (int i = start; i <= end; i++)
    {
        huff->nodes[i].p = huff->nodes[i].l = huff->nodes[i].r = 0;
    }
}

void InitHuff(PtrHuff huff, int len, PtrWord array)
{
    // ��ʼ�� huff ����
    // ԭ�Ӳ���
    huff->length = 2 * len;
    // ��ʼ������
    Set(huff, 1, len); // ���½ڵ�
    for (int i = 1; i <= len; i++)
        huff->nodes[i].w = array->w[i];
    for (int i = len + 1; i < huff->length; i++)
        huff->nodes[i].w = 9999;
    // ��ʼ������
}

void Findmin(PtrHuff array, int *min_index, int len, int last)
{
    // �ҵ����� last ����Сֵ
    // ԭ�Ӳ���
    *min_index = last + 1;
    int min = array->nodes[*min_index].w;
    for (int i = 1; i < len; i++)
    {
        if (i == last)
            continue;
        if (min > array->nodes[i].w)
        {
            min = array->nodes[i].w;
            *min_index = i;
        }
    }
}

void SetPK(PtrHuff array, int p, int one, int two)
{
    // �ϲ����½ڵ�
    // ԭ�Ӳ���
    array->nodes[p].w = array->nodes[one].w + array->nodes[two].w;
    array->nodes[one].p = array->nodes[two].p = p;
    if (array->nodes[one].w < array->nodes[two].w)
    {
        array->nodes[p].l = one;
        array->nodes[p].r = two;
    }
    else
    {
        array->nodes[p].r = one;
        array->nodes[p].l = two;
    }
    array->nodes[p].p = 0;
    array->nodes[one].w = 9999;
    array->nodes[two].w = 9999;
}

void CreatHuff(PtrHuff array)
{
    // ���� ��������
    int time = (array->length / 2) - 1;
    int one, two;
    int len = time + 2;
    for (int i = 0; i < time; i++)
    {
        Findmin(array, &one, array->length, 0);
        Findmin(array, &two, array->length, one);
        SetPK(array, len, one, two);
        len++;
    }
}

PtrBest ChangeHuff(PtrBest bestes, PtrHuff huff)
{
    // ������������
    int length = huff->length;

    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bestes[i].best[j] = '\0';
        }
    }

    int p;
    bestes[length - 1].len = -1;

    for (int i = length - 2; i > 0; i--)
    {
        p = huff->nodes[i].p;
        bestes[i].len = bestes[p].len + 1;
        strcpy(bestes[i].best, bestes[p].best);
        if (i == huff->nodes[p].l)
        {
            bestes[i].best[bestes[i].len] = '0';
        }
        else
        {
            bestes[i].best[bestes[i].len] = '1';
        }
    }
    return bestes;
}

void Print(PtrBest bestes, PtrWord words, int len)
{
    char word[10];
    printf("\n");
    printf("����������\n");
    printf("\n");
    printf("| ��ĸ   ����\n");
    for (int i = 1; i < len; i++)
    {
        printf("������������������������\n");
        printf("|  %c  |  %s\n", words->array[i], bestes[i].best);
    }
    printf("������������������������\n");
}

void Screen()
{
    // ����
    printf("******����������ϵͳ*******\n");
    printf("**************************\n");
    printf("����������,������0��������\n");
    printf("**************************\n");
    printf("����������,������#��ʾ����\n");
    printf("***************************\n");
    PtrWord words = getWords();
    Huff huff;
    InitHuff(&huff, words->length - 1, words);
    CreatHuff(&huff);
    Best bestes[40];
    ChangeHuff(bestes, &huff);
    Print(bestes, words, words->length);
}

int main()
{
    Screen();
    return 0;
}