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

typedef struct Node {
    int id;
    char name[10];
    char information[30];
}Node, *PtrNode;

typedef struct Graph {
    int** matrix;
    int num_Node;
    PtrNode nodes;
}Graph, *PtrGraph;

PtrGraph InitGraph () {
    // ��ʼ����ͼ
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    printf("�����뾰�������\n");
    int num_Node = 0; scanf("%d", &num_Node); getchar();
    graph->num_Node = num_Node;
    graph->nodes = (PtrNode)malloc(num_Node*sizeof(Node));
    graph->matrix = (int**)malloc(num_Node*sizeof(int*));
    for (int i=0; i<num_Node; i++) graph->matrix[i] = (int*)malloc(num_Node*sizeof(int));

    for (int i = 0; i < num_Node; i++) {
        for (int j=0; j<num_Node; j++) {
            graph->matrix[i][j] = 9999;
        }
    }
    char* name = (char*)malloc(10*sizeof(char)); int id = 0;
    char* information = (char*)malloc(30*sizeof(char));
    for (int i=0; i<num_Node; i++) graph->matrix[i] = (int*)malloc(num_Node*sizeof(int));
    for (int i=0; i<num_Node; i++) {
        printf("���������뾰�����ơ�id�ͼ�飺\n");
        scanf("%s", name); getchar(); strcpy(graph->nodes[i].name, name);
        scanf("%d", &id); getchar(); graph->nodes[i].id = id;
        scanf("%s", information); getchar(); strcpy(graph->nodes[i].information, information);
    }
    printf("�������ǳ�ʼ��·��������\n");
    printf("��������ʼ���㣺(ֹͣ����������-1)��\n");

    int one = 0; int two = 0; int w = 0;
    scanf("%d", &one); getchar();
    while (one >= 0) {
        printf("������Ŀ�ľ��㼰��ʼ���㵽Ŀ�Ķ���ľ��룺\n");
        scanf("%d,%d", &two, &w);
        graph->matrix[one][two] = w;
        graph->matrix[two][one] = w;
        printf("��������ʼ���㣺(ֹͣ����������-1)��\n");
        scanf("%d", &one);
    }
    return graph;
}

void FindAll (PtrGraph graph) {
    // �������о���
    int num_Node = graph->num_Node;
    for (int i=0; i<num_Node; i++) {
        printf("���㣺%s �����ǣ�%d\n��飺%s\n", graph->nodes[i].name, graph->nodes[i].id, graph->nodes[i].information);
        for (int j=0; j<num_Node; j++) {
            if (graph->matrix[i][j] != 9999 && i != j) {
                printf("    ������%s �ľ����ǣ�%d\n", graph->nodes[j].name, graph->matrix[i][j]);
            }
        }
    }
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
    // ��ĳ�����㵽�����������С����
    int num_Node = graph->num_Node;
    int* array = (int*)malloc(num_Node*sizeof(int));
    
    int** path = (int**)malloc(num_Node*sizeof(int*));
    for (int i=0; i<num_Node; i++) path[i] = (int*)malloc(2*sizeof(int));
    for (int i=0; i<num_Node; i++) {
        path[0][i] = -1;
        path[1][i] = 9999;
    }

    path[1][index] = 0;

    for (int i=0; i<num_Node; i++) array[i] = path[1][i];

    for (int i=0; i<num_Node; i++) {
        int k = FindMin(array, num_Node);
        path[0][k] = 1; array[k] = 9999;

        for (int j=0; j<num_Node; j++) {
            if (graph->matrix[j][i] != 9999) {
                int new = path[1][k] + graph->matrix[j][i];
                int old = path[1][j];
                if (new < old) {
                    path[1][j] = new; array[j] = new;
                }
            }
        }
    }

    for (int i=0; i<num_Node; i++) {
        array[i] = path[1][i];
    }

    return array;
}

void OneToAll (PtrGraph graph, int index) {
    // ��ӡ��ĳ���㵽�����ľ������С����
    int* array = Dijkstra(graph, index);
    printf("%s �����������̾��룺\n", graph->nodes[index].name);
    for (int i=0; i<graph->num_Node; i++) {
        if (array[i] != 0 && array[i] != 9999)
        printf("    ��%s��%d\n", graph->nodes[i].name, array[i]);
    }
}

int Floyd (PtrGraph graph, int x, int y) {
    // ��ĳ�����㵽��һ���������̾���
    int num_Node = graph->num_Node;
    int** path = (int**)malloc(num_Node*sizeof(int*));
    for (int i=0; i<num_Node; i++) path[i] = (int*)malloc(num_Node*sizeof(int));
    for (int i=0; i<num_Node; i++) {
        for (int j=0; j<num_Node; j++) {
            path[i][j] = graph->matrix[i][j];
        }
    }
    for (int k=0; k<num_Node; k++) {
        for (int i=0; i<num_Node; i++) {
            for (int j=0; j<num_Node; j++) {
                if (path[i][j] > path[i][k] + path[k][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }    
        }
    }
    return path[x][y];
}

void OneToOne (PtrGraph graph, int x, int y) {
    // ��ӡ��ĳ�����㵽��һ���������̾���
    printf("%s �� %s ����̾���Ϊ��%d\n", graph->nodes[x].name, graph->nodes[y].name, Floyd(graph, x, y));
}

int main()
{
    return 0;
}
