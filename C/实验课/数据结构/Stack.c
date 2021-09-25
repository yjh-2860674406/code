#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef int Elem;

struct Node {
    Elem elem;
    struct Node * next;
    int true;
};

typedef struct Stack {
    int length;
    int size;
    struct Node * header;    
}stack,*ptrstack;

ptrstack InitStack () {
    // 构造一个空表
    ptrstack Sq = (ptrstack)malloc(sizeof(stack));
    if (!Sq) return NULL;
    else {
        Sq->header = (struct Node*)malloc(sizeof(struct Node));
        Sq->length = 0;
        Sq->header->next = NULL;
        Sq->header->elem = 0;
        Sq->size = 1;
        Sq->header->true = 1;
        return Sq;
    }
}

int DestoryStack (ptrstack Sq) {
    // 销毁栈 Sq
    struct Node * temp = Sq->header;
    for (int i=0; i<Sq->length+1; i++) {
        temp = temp->next;
        free(Sq->header);
        Sq->header = temp;
    }
    free(Sq); Sq = NULL; return TRUE;
}

int ClearStack (ptrstack Sq) {
    // 把 S 置为空表
    Sq->length = 0; 
    while (Sq->header->next != NULL) {
        Sq->header->next->true = 0;
        Sq->header->next = Sq->header->next->next;
    }
    return 0;
}

int StackEmpty (ptrstack Sq) {
    // 判断是否为空表
    if (Sq->length == 0) return TRUE; else return FALSE;
}

int StackLength (ptrstack Sq) {
    return Sq->length;
}

int GetTop (ptrstack Sq, Elem* e) {
    if (!StackEmpty(Sq)) return FALSE;
    *e = Sq->header->next->elem; return TRUE;
}

int Push (ptrstack Sq, Elem* e) {
    if (!StackEmpty(Sq)) return FALSE;
    *e = Sq->header->next->elem;
    Sq->header->next->true = 0; Sq->length--; return TRUE;
}

// int Pop (ptrstack Sq, Elem e) {
//     if(!StackEmpty(Sq)) {
//         while (Sq->header->next != NULL) {
//             Sq->header = Sq->header->next;
//         }
//         Sq->header->elem = e; return TRUE;
//     }
// }