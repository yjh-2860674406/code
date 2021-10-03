#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Node {
    int elem;
    struct Node* next;
}Node, *PtrNode;

typedef struct Queue {
    PtrNode header;
    PtrNode base;
}Queue, *PtrQueue;

PtrQueue InitQueue () {
    // 初始化队列
    PtrQueue queue = (PtrQueue)malloc(sizeof(Queue));
    queue->header = (PtrNode)malloc(sizeof(Node));
    queue->base = queue->header;
    return queue;
}

int IsEmpty (PtrQueue queue) {
    // 判断是否为空
    if (queue->base == queue->header) return 1;
    else return 0;
}

int Push (PtrQueue queue, int e) {
    // 入队
    queue->base->next = (PtrNode)malloc(sizeof(Node));
    if (!queue->base->next) return FALSE;
    queue->base->next->elem = e; queue->base->next->next = NULL;
    queue->base = queue->base->next; return TRUE;
}

int Pop (PtrQueue queue) {
    // 出队
    while (IsEmpty(queue)) return FALSE;
    int temp = queue->header->next->elem;
    free(queue->header); queue->header = queue->header->next;
    return temp;
}

int GetTop (PtrQueue queue) {
    // 获取队头
    while (IsEmpty(queue)) {
        return FALSE;
    }
    return queue->header->next->elem;
}

int main () {
    
}