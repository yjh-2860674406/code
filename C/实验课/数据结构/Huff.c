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
    // 初始化 words
    // 原子操作
    PtrWord words = (PtrWord)malloc(sizeof(Word));
    // 分配内存

    words->size = 10;
    words->array = (char *)malloc(10 * sizeof(char));
    words->w = (int *)malloc(sizeof(int));
    words->length = 1;
    // 初始化参数

    return words;
}

void JudgeSize(PtrWord words)
{
    // 判断是否满，若满则增加长度
    // 原子操作
    if (words->length > words->size)
    {
        // 初始化参数
        words->size += 10;
        words->array = (char *)realloc(words->array, words->size * sizeof(char));
        words->w = (int *)realloc(words->w, words->size * sizeof(int));
    }
}

PtrWord getWords()
{
    // 将数据填入 words
    // 亚原子操作
    PtrWord words = InitWords();
    int w;
    char word;
    while (printf("请输入字母及其权值(字母,权值):\n"), scanf("%c,%d", &word, &w), getchar(),
           word != '0')
    {
        if (word == '#')
            continue;

        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z'))
        {
            JudgeSize(words); // 判断长度，是否需要添加空间

            words->array[words->length] = word;
            words->w[words->length] = w;
            words->length++;
        }
        else
        {
            printf("输入错误!请继续输入(格式:字母,权值)\n");
        }
    }

    return words;
}

void Set(PtrHuff huff, int start, int end)
{
    // 更新节点
    // 原子操作
    for (int i = start; i <= end; i++)
    {
        huff->nodes[i].p = huff->nodes[i].l = huff->nodes[i].r = 0;
    }
}

void InitHuff(PtrHuff huff, int len, PtrWord array)
{
    // 初始化 huff 数组
    // 原子操作
    huff->length = 2 * len;
    // 初始化参数
    Set(huff, 1, len); // 更新节点
    for (int i = 1; i <= len; i++)
        huff->nodes[i].w = array->w[i];
    for (int i = len + 1; i < huff->length; i++)
        huff->nodes[i].w = 9999;
    // 初始化参数
}

void Findmin(PtrHuff array, int *min_index, int len, int last)
{
    // 找到除了 last 的最小值
    // 原子操作
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
    // 合并更新节点
    // 原子操作
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
    // 创建 哈夫曼树
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
    // 解析哈夫曼树
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
    printf("哈夫曼编码\n");
    printf("\n");
    printf("| 字母   编码\n");
    for (int i = 1; i < len; i++)
    {
        printf("－－－－－－－－－－－－\n");
        printf("|  %c  |  %s\n", words->array[i], bestes[i].best);
    }
    printf("－－－－－－－－－－－－\n");
}

void Screen()
{
    // 交互
    printf("******哈夫曼编码系统*******\n");
    printf("**************************\n");
    printf("如果输入完毕,请输入0结束输入\n");
    printf("**************************\n");
    printf("如果输入错误,请输入#表示回退\n");
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