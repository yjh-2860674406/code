#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define MAXPOINT 50

typedef struct EdgeNode
{                          // ��
    int index;             // �ڽӵ���±�
    int weight;            // �ߵ�Ȩֵ
    struct EdgeNode *next; // ����
} EdgeNode, *PtrEdge;

typedef struct Node
{                      // ����
    int date;          // ������Ϣ
    PtrEdge firstegde; // �߱�ͷָ��
} Node, *PtrNode;

typedef struct Graph
{
    Node arr[MAXPOINT];
    int numPoint; // ��������
    int numEdge;  // �ߵ�����
} Graph, *PtrGraph;

typedef struct Array
{
    int array[10];
    int len;
} Array, *PtrArray;

PtrGraph InitGraph()
{
    // ��ʼ��ͼ
    // ��������
    int numPoint;
    int numEdge;
    printf("������Ҫ��ӵĶ�������\n");
    scanf("%d", &numPoint);
    getchar();
    printf("������Ҫ��ӵı�����\n");
    scanf("%d", &numEdge);
    getchar();
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->numEdge = numEdge;
    graph->numPoint = numPoint;
    int date, w, first, second;
    for (int i = 0; i < numPoint; i++)
    {
        printf("������Ҫ��ӵĶ��㣺\n");
        int date;
        scanf("%d", &date);
        getchar();
        graph->arr[i].date = date;
        graph->arr[i].firstegde = NULL;
    }
    for (int i = 0; i < numEdge; i++)
    {
        printf("������Ҫ��ӵıߵ������ڽӵ��Ȩ�أ�\n");
        scanf("%d, %d, %d", &first, &second, &w);
        getchar();
        if (!graph->arr[first].firstegde)
        {
            graph->arr[first].firstegde = (PtrEdge)malloc(sizeof(EdgeNode));
            graph->arr[first].firstegde->index = second;
            graph->arr[first].firstegde->next = NULL;
            graph->arr[first].firstegde->weight = w;
        }
        else
        {
            PtrEdge temp = graph->arr[first].firstegde;
            while (temp->next)
                temp = temp->next;
            temp->next = (PtrEdge)malloc(sizeof(EdgeNode));
            temp->next->index = second, temp->next->next = NULL;
            temp->next->weight = w;
        }
    }
    return graph;
}

int Locate(PtrGraph graph, int t)
{
    for (int i = 0; i < graph->numPoint; i++)
    {
        if (graph->arr[i].date == t)
            return i;
    }
}

int FindMin(int array[], int num)
{
    // ����������С��Ԫ��λ��
    int temp = array[0];
    int res = 0;

    for (int i = 1; i < num; i++)
    {
        if (array[i] < temp)
        {
            temp = array[i];
            res = i;
        }
    }
    return res;
}

void addPaths(PtrArray paths, int new, int old)
{
    // ��ӽ�·��
    if (paths[new].array[paths[new].len] != paths[old].array[paths[old].len - 1])
    {
        paths[new].len = paths[old].len;
        for (int i = 1; i <= paths[old].len; i++)
        {
            paths[new].array[i] = paths[old].array[i];
        }
    }
    paths[new].len++;
    paths[new].array[paths[new].len] = old;
}

void InitPath(int **path, int num)
{
    // ��ʼ��·����
    for (int i = 0; i < num; i++)
    {
        path[0][i] = -1;
        path[1][i] = 9999;
    }
}

int *Dijkstra(PtrGraph graph, PtrArray paths, int index)
{
    // ��ĳ���ϵ㵽������������·��
    int num = graph->numPoint;
    int *array = (int *)malloc(graph->numPoint * sizeof(int));
    // ���շ��ص�����

    // path[0] -> ����Ƿ���ӽ����·����
    // path[1] -> ��㵽�õ�ľ���

    int **path = (int **)malloc(num * sizeof(int *));
    for (int i = 0; i < num; i++)
        path[i] = (int *)malloc(2 * sizeof(int));
    // ·����

    InitPath(path, num);

    for (int i = 0; i < num; i++)
    {
        paths[i].len = 0;
    }

    path[1][index] = 0;
    // ��ʼ�㵽��ʼ��ľ���Ϊ0

    for (int i = 0; i < num; i++)
        array[i] = path[1][i];

    for (int x = 0; x < num; x++)
    {
        // �㷨�Ŀ�ʼ
        int j = FindMin(array, num); // �ҵ���С·���ĵ�
        path[0][j] = 1;
        array[j] = 9999; // ��¼����С·��

        PtrEdge temp = graph->arr[j].firstegde; // ��ʼ����
        while (temp)
        {
            int new = path[1][j] + temp->weight;
            int old = path[1][temp->index];
            // ��ǰ��ã��Ż�if
            if (new < old)
            {
                // ������ڵ��·�����ϵ���һ�����·��С��������һ�����·���͸���
                path[1][temp->index] = new;
                array[temp->index] = new;
                addPaths(paths, temp->index, j);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < num; i++)
        array[i] = path[1][i];

    for (int i = 0; i < num; i++)
    {
        paths[i].len++;
        paths[i].array[paths[i].len] = i;
    }

    return array;
}

int main()
{
    PtrGraph graph = InitGraph();
    printf("��������Ҫ���ĸ����㵽������������·����9999��ʾ�ﲻ������\n");
    int num = 0;
    scanf("%d", &num);
    getchar();
    PtrArray paths = (PtrArray)malloc((graph->numPoint + 1) * sizeof(Array));
    int *array = Dijkstra(graph, paths, num);
    printf("����Ϊ�����\n");
    for (int i = 0; i < graph->numPoint; i++)
    {
        printf("�ڵ� %d �� �ڵ� %d �� ���롡��%d", num, i, array[i]);
        printf(" ·��Ϊ��");
        for (int j = 1; j <= paths[i].len; j++)
            printf("%d ", paths[i].array[j]);
        printf("\n");
    }
}