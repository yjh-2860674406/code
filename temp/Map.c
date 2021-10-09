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
    // 初始化地图
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    printf("请输入景点个数：\n");
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
        printf("请依次输入景点名称、id和简介：\n");
        scanf("%s", name); getchar(); strcpy(graph->nodes[i].name, name);
        scanf("%d", &id); getchar(); graph->nodes[i].id = id;
        scanf("%s", information); getchar(); strcpy(graph->nodes[i].information, information);
    }
    printf("接下来是初始化路径操作：\n");
    printf("请输入起始景点：(停止输入则输入-1)：\n");

    int one = 0; int two = 0; int w = 0;
    scanf("%d", &one); getchar();
    while (one >= 0) {
        printf("请输入目的景点及起始顶点到目的顶点的距离：\n");
        scanf("%d,%d", &two, &w);
        graph->matrix[one][two] = w;
        graph->matrix[two][one] = w;
        printf("请输入起始景点：(停止输入则输入-1)：\n");
        scanf("%d", &one);
    }
    return graph;
}

void FindAll (PtrGraph graph) {
    // 遍历所有景点
    int num_Node = graph->num_Node;
    for (int i=0; i<num_Node; i++) {
        printf("景点：%s 代码是：%d\n简介：%s\n", graph->nodes[i].name, graph->nodes[i].id, graph->nodes[i].information);
        for (int j=0; j<num_Node; j++) {
            if (graph->matrix[i][j] != 9999 && i != j) {
                printf("    到景点%s 的距离是：%d\n", graph->nodes[j].name, graph->matrix[i][j]);
            }
        }
    }
}

int FindMin (int array[], int num) {
    // 找数组中最小的元素位置
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
    // 找某个景点到其他景点的最小距离
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
    // 打印出某景点到其他的景点的最小距离
    int* array = Dijkstra(graph, index);
    printf("%s 到各景点的最短距离：\n", graph->nodes[index].name);
    for (int i=0; i<graph->num_Node; i++) {
        if (array[i] != 0 && array[i] != 9999)
        printf("    到%s：%d\n", graph->nodes[i].name, array[i]);
    }
}

int Floyd (PtrGraph graph, int x, int y) {
    // 求某个顶点到另一个顶点的最短距离
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
    // 打印出某个顶点到另一个顶点的最短距离
    printf("%s 到 %s 的最短距离为：%d\n", graph->nodes[x].name, graph->nodes[y].name, Floyd(graph, x, y));
}

int main()
{
    return 0;
}
