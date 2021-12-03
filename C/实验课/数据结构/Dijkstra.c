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
{                          // 边
    int index;             // 邻接点的下标
    int weight;            // 边的权值
    struct EdgeNode *next; // 链域
} EdgeNode, *PtrEdge;

typedef struct Node
{                      // 顶点
    int date;          // 顶点信息
    PtrEdge firstegde; // 边表头指针
} Node, *PtrNode;

typedef struct Graph
{
    Node arr[MAXPOINT];
    int numPoint; // 顶点数量
    int numEdge;  // 边的数量
} Graph, *PtrGraph;

typedef struct Array
{
    int array[10];
    int len;
} Array, *PtrArray;

PtrGraph InitGraph()
{
    // 初始化图
    // 基本操作
    int numPoint;
    int numEdge;
    printf("请输入要添加的顶点数：\n");
    scanf("%d", &numPoint);
    getchar();
    printf("请输入要添加的边数：\n");
    scanf("%d", &numEdge);
    getchar();
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->numEdge = numEdge;
    graph->numPoint = numPoint;
    int date, w, first, second;
    for (int i = 0; i < numPoint; i++)
    {
        printf("请输入要添加的顶点：\n");
        int date;
        scanf("%d", &date);
        getchar();
        graph->arr[i].date = date;
        graph->arr[i].firstegde = NULL;
    }
    for (int i = 0; i < numEdge; i++)
    {
        printf("请输入要添加的边的两个邻接点和权重：\n");
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
    // 找数组中最小的元素位置
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
    // 添加进路径
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
    // 初始化路径表
    for (int i = 0; i < num; i++)
    {
        path[0][i] = -1;
        path[1][i] = 9999;
    }
}

int *Dijkstra(PtrGraph graph, PtrArray paths, int index)
{
    // 找某个断点到各个顶点的最短路径
    int num = graph->numPoint;
    int *array = (int *)malloc(graph->numPoint * sizeof(int));
    // 最终返回的数组

    // path[0] -> 标记是否添加进最短路径中
    // path[1] -> 起点到该点的距离

    int **path = (int **)malloc(num * sizeof(int *));
    for (int i = 0; i < num; i++)
        path[i] = (int *)malloc(2 * sizeof(int));
    // 路径表

    InitPath(path, num);

    for (int i = 0; i < num; i++)
    {
        paths[i].len = 0;
    }

    path[1][index] = 0;
    // 初始点到初始点的距离为0

    for (int i = 0; i < num; i++)
        array[i] = path[1][i];

    for (int x = 0; x < num; x++)
    {
        // 算法的开始
        int j = FindMin(array, num); // 找到最小路径的点
        path[0][j] = 1;
        array[j] = 9999; // 收录入最小路径

        PtrEdge temp = graph->arr[j].firstegde; // 开始遍历
        while (temp)
        {
            int new = path[1][j] + temp->weight;
            int old = path[1][temp->index];
            // 提前算好，优化if
            if (new < old)
            {
                // 如果现在点的路径加上到另一个点的路径小于现在另一个点的路径就更新
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
    printf("请输入你要找哪个顶点到其他顶点的最短路径（9999表示达不到）：\n");
    int num = 0;
    scanf("%d", &num);
    getchar();
    PtrArray paths = (PtrArray)malloc((graph->numPoint + 1) * sizeof(Array));
    int *array = Dijkstra(graph, paths, num);
    printf("以下为结果：\n");
    for (int i = 0; i < graph->numPoint; i++)
    {
        printf("节点 %d 到 节点 %d 的 距离　：%d", num, i, array[i]);
        printf(" 路径为：");
        for (int j = 1; j <= paths[i].len; j++)
            printf("%d ", paths[i].array[j]);
        printf("\n");
    }
}