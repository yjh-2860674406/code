#include <stdlib.h>
#include <stdio.h>

typedef struct Graph {
    int** matrix;
    int num;
    int tag[5];
}Graph, *PtrGraph;

PtrGraph Creat (int num) {
    PtrGraph graph = (PtrGraph)malloc(sizeof(Graph));
    graph->num = num; graph->matrix = (int**)malloc(sizeof(int*)*num);
    for (int i=0; i<num; i++) {
        graph->matrix[i] = (int*)malloc(sizeof(int)*num);
    }
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            graph->matrix[i][j] = 999;
        }
    }
    for (int i=0; i<5; i++) {
        graph->tag[i] = 0;
    }
}

void Add (PtrGraph graph, int x, int y, int w) {
    graph->matrix[x][y] = w;
    graph->matrix[y][x] = w;
}

int FindMin (int* array) {
    int res = 0; int min = array[0];
    for (int i=0; i<5; i++) {
        if (array[i] <= min) {
            res = i;
            min = array[i];
        }
    }
    return res;
}

void Print () {

}

int Find (PtrGraph graph) {
    int array[5] = {0};
    graph->tag[0] = 1;
    array[0] = 1;
    int min[5] = {999};
    for (int i=1; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (array[j] == 1) {
                min[j] = FindMin(graph->matrix[j]);
            }
        }
        int index = FindMin(min);
        
    }
}

int main(int argc, char const *argv[])
{
    PtrGraph graph = Creat(5);
    Add(graph, 0,1,3);
    Add(graph, 0,2,4);
    Add(graph, 0,4,9);
    Add(graph, 1,2,8);
    Add(graph, 1,3,13);
    Add(graph, 1,4,11);
    Add(graph, 2,3,7);
    Add(graph, 3,4,4);
    return 0;
}


