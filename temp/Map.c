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

typedef struct EdgeNode { // ��
    int index; // �ڽӵ���±�
    int weight; // �ߵ�Ȩֵ
    struct EdgeNode* next; // ����
}EdgeNode, *PtrEdge;

typedef struct Node { // ����
    int date; // ������Ϣ
    char name[10];
    char information[30];
    PtrEdge firstegde; // �߱�ͷָ��
}Node, *PtrNode;

typedef struct Graph {
    Node arr[MAXPOINT];
    int numPoint; // ��������
    int numEdge;  // �ߵ�����
    int visited[MAXPOINT]; 
}Graph, *PtrGraph;

PtrGraph InitGraph () {
    // ��ʼ��ͼ
    int numPoint; int numEdge;
    printf("������Ҫ��ӵľ�������\n");
    scanf("%d", &numPoint); getchar();
    printf("������Ҫ��ӵı�����\n");
    scanf("%d", &numEdge); getchar();
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->numEdge = numEdge; graph->numPoint = numPoint;
    int date, w, first, second;
    for (int i=0; i<numPoint; i++) {
        printf("������Ҫ��ӵľ�����ţ�\n"); 
        int date; char name[10]; char information[30];
        scanf("%d", &date); getchar();
        printf("������Ҫ��ӵľ������ƣ�\n");
        puts(graph->arr[i].name);
        printf("������Ҫ��ӵľ����飺\n");
        puts(graph->arr[i].information);
        graph->arr[i].date = date; strcpy(graph->arr[i].information, information);
        strcpy(graph->arr[i].name, name); graph->arr[i].firstegde = NULL;
    }
    for (int i=0; i<numEdge; i++) {
        printf("������Ҫ��ӵıߵ������ڽӾ����·������(m)��\n");
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
    // ���붥��
    printf("������Ҫ��ӵľ������, ����, ��飺\n"); 
    int date; char name[10]; char information[30];
    scanf("%d��%s��%s", &date, name, information); getchar();
    graph->arr[graph->numPoint].date = date; strcpy(graph->arr[graph->numPoint].information, information);
    strcpy(graph->arr[graph->numPoint].name, name); graph->arr[graph->numPoint].firstegde = NULL;
    graph->numPoint++; return TRUE;
}

int InsertEdge (PtrGraph graph) {
    // �����
    printf("������Ҫ��ӵ��ڽӾ����·������(m)��\n"); int first, second, w;
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
    // ��ȡȫ��������Ϣ
    for (int i=0; i<graph->numPoint; i++) {
        printf("���㣺%s\t���ţ�%d\t��飺%s\n", graph->arr[i].name, graph->arr[i].date, graph->arr[i].information);
    }
}

void GetOne (PtrGraph graph) {
    // ��ȡĳ��������Ϣ
    printf("��������Ҫ��ѯ�ľ������ƣ�\n");
    char name[10]; puts(name);
    for (int i=0; i<graph->numPoint; i++) {
        if (strcmp(name, graph->arr[i].name)) {
        printf("���㣺%s\t���ţ�%d\t��飺%s\n", graph->arr[i].name, graph->arr[i].date, graph->arr[i].information);
        break;
        }
    }
}

int main () {
    PtrGraph graph = InitGraph();
}