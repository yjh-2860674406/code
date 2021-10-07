#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define MAXPOINT 50

typedef struct EdgeNode { // 边
    int index; // 邻接点的下标
    int weight; // 边的权值
    struct EdgeNode* next; // 链域
}EdgeNode, *PtrEdge;

typedef struct Node { // 顶点
    int date; // 顶点信息
    char name[10];
    char information[30];
    PtrEdge firstegde; // 边表头指针
}Node, *PtrNode;

typedef struct Graph {
    Node arr[MAXPOINT];
    int numPoint; // 顶点数量
    int numEdge;  // 边的数量
    int visited[MAXPOINT]; 
}Graph, *PtrGraph;

PtrGraph InitGraph () {
    // 初始化图
    int numPoint; int numEdge;
    printf("请输入要添加的景点数：\n");
    scanf("%d", &numPoint); getchar();
    printf("请输入要添加的边数：\n");
    scanf("%d", &numEdge); getchar();
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->numEdge = numEdge; graph->numPoint = numPoint;
    int date, w, first, second;
    for (int i=0; i<numPoint; i++) {
        printf("请输入要添加的景点代号：\n"); 
        int date; char name[10]; char information[30];
        scanf("%d", &date); getchar();
        printf("请输入要添加的景点名称：\n");
        puts(graph->arr[i].name);
        printf("请输入要添加的景点简介：\n");
        puts(graph->arr[i].information);
        graph->arr[i].date = date; strcpy(graph->arr[i].information, information);
        strcpy(graph->arr[i].name, name); graph->arr[i].firstegde = NULL;
    }
    for (int i=0; i<numEdge; i++) {
        printf("请输入要添加的边的两个邻接景点和路径长度(m)：\n");
        scanf("%d, %d, %d", &first, &second, &w); getchar();
        if (!graph->arr[first].firstegde) {
            graph->arr[first].firstegde = (PtrEdge)malloc(sizeof(EdgeNode));
            graph->arr[first].firstegde->index = second;
            graph->arr[first].firstegde->next = NULL;
            graph->arr[first].firstegde->weight = w;
        }
        else {
            PtrEdge temp = graph->arr[first].firstegde;
            while (temp->next) temp = temp->next;
            temp->next = (PtrEdge)malloc(sizeof(EdgeNode));
            temp->next->index = second, temp->next->next = NULL; temp->next->weight = w;
        }
    }
    return graph;
}

int InsertPoint (PtrGraph graph) {
    // 插入顶点
    printf("请输入要添加的景点代号, 名称, 简介：\n"); 
    int date; char name[10]; char information[30];
    scanf("%d，%s，%s", &date, name, information); getchar();
    graph->arr[graph->numPoint].date = date; strcpy(graph->arr[graph->numPoint].information, information);
    strcpy(graph->arr[graph->numPoint].name, name); graph->arr[graph->numPoint].firstegde = NULL;
    graph->numPoint++; return TRUE;
}

int InsertEdge (PtrGraph graph) {
    // 插入边
    printf("请输入要添加的邻接景点和路径长度(m)：\n"); int first, second, w;
    scanf("%d, %d, %d", &first, &second, &w); getchar();
    if (!graph->arr[first].firstegde) {
            graph->arr[first].firstegde = (PtrEdge)malloc(sizeof(EdgeNode));
            graph->arr[first].firstegde->index = second;
            graph->arr[first].firstegde->next = NULL;
            graph->arr[first].firstegde->weight = w;
        }
        else {
            PtrEdge temp = graph->arr[first].firstegde;
            while (temp->next) temp = temp->next;
            temp->next = (PtrEdge)malloc(sizeof(EdgeNode));
            temp->next->index = second, temp->next->next = NULL; temp->next->weight = w;
        }
    return TRUE;
}

void GetAll (PtrGraph graph) {
    // 获取全部景点信息
    for (int i=0; i<graph->numPoint; i++) {
        printf("景点：%s\t代号：%d\t简介：%s\n", graph->arr[i].name, graph->arr[i].date, graph->arr[i].information);
    }
}

void GetOne (PtrGraph graph) {
    // 获取某个景点信息
    printf("请输入你要查询的景点名称：\n");
    char name[10]; puts(name);
    for (int i=0; i<graph->numPoint; i++) {
        if (strcmp(name, graph->arr[i].name)) {
        printf("景点：%s\t代号：%d\t简介：%s\n", graph->arr[i].name, graph->arr[i].date, graph->arr[i].information);
        break;
        }
    }
}

int main () {
    PtrGraph graph = InitGraph();
}