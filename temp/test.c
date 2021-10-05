#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define MAXPOINT 50

typedef struct Node {
    int date; // 数据域
    struct Node* next; // 指针域
}Node, *PtrNode;

typedef struct Queue {
    int size; // 队列大小
    PtrNode rear; // 队尾指针
}Queue, *PtrQueue;

PtrQueue InitQueue () {
    // 初始化队列
    PtrQueue queue = (PtrQueue)malloc(sizeof(Queue));
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int InQueue (PtrQueue queue, int data) {
    while (queue->size == 0) {
        queue->rear = (PtrNode)malloc(sizeof(Node));
        queue->rear->date = data; queue->rear->next = queue->rear;
        queue->size = 1; return 1;
    }
    PtrNode temp = (PtrNode)malloc(sizeof(Node));
    temp->next = queue->rear->next; temp->date = data;
    queue->rear->next = temp; queue->rear = temp;
    return 1;
}