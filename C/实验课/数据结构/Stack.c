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

typedef struct Stack {
    PtrNode header;
}Stack, *PtrStack;

PtrStack InitStack () {
    // 初始化
    PtrStack stack = (PtrStack)malloc(sizeof(Stack));
    stack->header = (PtrNode)malloc(sizeof(Node));
    stack->header->next = NULL;
    return stack;
}

int IsEmpty (PtrStack stack) {
    // 判断是否为空
    if (stack->header->next == NULL) return 1;
    else return 0;
}

int Push (PtrStack stack, int e) {
    // 入栈
    PtrNode temp = (PtrNode)malloc(sizeof(Node));
    if (!temp) return FALSE;
    temp->elem = e; temp->next = stack->header->next;
    stack->header->next = temp; return TRUE;
}

int Pop (PtrStack stack) {
    // 出栈
    while (!IsEmpty(stack)) {
        int temp = stack->header->next->elem;
        free(stack->header->next); stack->header->next = stack->header->next->next;
        return temp;
    }
}

int GetTop (PtrStack stack) {
    // 获取栈顶元素
    while (!IsEmpty(stack)) {
        return stack->header->next->elem;
    }
}

int main () {
    
}