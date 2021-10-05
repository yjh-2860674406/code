#include <stdio.h>
#include <stdlib.h>

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
    printf("������Ҫ��ӵĶ�������\n");
    scanf("%d", &numPoint); getchar();
    printf("������Ҫ��ӵı�����\n");
    scanf("%d", &numEdge); getchar();
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->numEdge = numEdge; graph->numPoint = numPoint;
    int date, w, first, second;
    for (int i=0; i<numPoint; i++) {
        printf("������Ҫ��ӵĶ��㣺\n"); int date;
        scanf("%d", &date); getchar();
        graph->arr[i].date = date; graph->arr[i].firstegde = NULL;
    }
    for (int i=0; i<numEdge; i++) {
        printf("������Ҫ��ӵıߵ������ڽӵ��Ȩ�أ�\n");
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
    printf("������Ҫ��ӵĶ��㣺\n"); int date;
    scanf("%d", &date); getchar();
    graph->arr[graph->numPoint].date = date; graph->arr[graph->numPoint++].firstegde = NULL;
    return TRUE;
}

int InsertEdge (PtrGraph graph) {
    // �����
    printf("������Ҫ��ӵ��ڽӵ��Ȩֵ��\n"); int first, second, w;
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

int FindMin (int array[], int num) {
    // ����������С��Ԫ��λ��
    int temp = array[0];
    int res = 0;
    
    for (int i=1; i<num; i++) {
        if (array[i] < temp) {
            temp = array[i]; res = i;
        }
    }
    return res;
}

int* Dijkstra (PtrGraph graph, int index) {
    // ��ĳ���ϵ㵽������������·��
    int num = graph->numPoint;
    int* array = (int*)malloc(graph->numPoint*sizeof(int));
    // ���շ��ص�����

    int** path = (int**)malloc(num*sizeof(int*));
    for (int i=0; i<num; i++) path[i] = (int*)malloc(2*sizeof(int));
    // ·����
    
    for (int i=0; i<num; i++) {
        path[0][i] = -1;
        path[1][i] = 9999;
    }
    // ��ʼ��·����

    path[1][index] = 0;
    // ��ʼ�㵽��ʼ��ľ���Ϊ0

    for (int i=0; i<num; i++) array[i] = path[1][i];

    for (int x=0; x<num; x++) {
        // �㷨�Ŀ�ʼ
        int j = FindMin(array, num); // �ҵ���С·���ĵ�
        path[0][j] = 1; array[j] = 9999; // ��¼����С·��

        PtrEdge temp = graph->arr[j].firstegde; // ��ʼ����
        while (temp) {
            int new = path[1][j] + temp->weight; int old = path[1][temp->index];
            if (new < old) {
                // ������ڵ��·�����ϵ���һ�����·��С��������һ�����·���͸���
                path[1][temp->index] = new; array[temp->index] = new;
            }
            temp = temp->next;
        }
    }

    for (int i=0; i<num; i++) {
        array[i] = path[1][i];
    }

    return array;
}

int main () {
    PtrGraph graph = InitGraph();
    printf("��������Ҫ���ĸ����㵽������������·����9999��ʾ�ﲻ������\n");
    int num = 0; scanf("%d", &num); getchar();
    int* array = Dijkstra(graph, num);
    printf("����Ϊ�����\n");
    for (int i=0; i<graph->numPoint; i++) {
        printf("%d\n", array[i]);
    }
}