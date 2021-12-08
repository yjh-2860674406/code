/* 
445. 两数相加 II

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    short e;
    struct Node* next;
}Node, *PtrNode;

typedef struct Link {
    PtrNode head;
    PtrNode tag;
}Link, *PtrLink;

typedef struct Stack {
    short* array;
    int length;
    int size;
    int top;
}Stack, *PtrStack;

PtrStack InitStack () {
    PtrStack stack = (PtrStack)malloc(sizeof(Stack));
    stack->size = 10; stack->length = 0; stack->top = 0;
    stack->array = (short*)malloc(sizeof(short)*stack->size);
    return stack;
}

int IsFull (PtrStack stack) {
    if (stack->length == stack->size) return 1;
    else return 0;
}

int IsEmpty (PtrStack stack) {
    if (stack->length == 0) return 1;
    else return 0;
}

void Extend (PtrStack stack) {
    if (IsFull(stack)) {
        stack->size += 10;
        stack->array = (short*)realloc(stack->array, stack->size);
    }
}

void Push (PtrStack stack, short e) {
    Extend(stack);
    stack->array[stack->top] = e;
    stack->top = (stack->top+1)%stack->size;
    stack->length++;
}

short GetTop (PtrStack stack) {
    if (!IsEmpty(stack)) {
        return stack->array[(stack->top+stack->size-1)%stack->size];
    }
}

short Pop (PtrStack stack) {
    if (!IsEmpty(stack)) {
        int index = (stack->top+stack->size-1)%stack->size;
        short temp = stack->array[index];
        stack->top = index; stack->length--;
        return temp;
    }
}

PtrLink InitLink () {
    PtrLink link = (PtrLink)malloc(sizeof(Link));
    link->head = (PtrNode)malloc(sizeof(Node));
    link->head->next = NULL; link->tag = link->head;
    return link;
}

void Insert (PtrLink link, short e) {
    link->tag->next = (PtrNode)malloc(sizeof(Node));
    link->tag->next->e = e; link->tag->next->next = NULL;
    link->tag = link->tag->next;
}

void PrintLink (PtrLink link) {
    PtrNode temp = link->head;
    while(temp = temp->next, temp) printf("%d", temp->e);
    printf("\n");
}

PtrLink addTwoNumbers (PtrLink link1, PtrLink link2) {
    PtrStack stack1 = InitStack(), stack2 = InitStack();
    PtrNode temp = link1->head; PtrStack stack_res = InitStack();
    while (temp = temp->next, temp) Push(stack1, temp->e);
    temp = link2->head;
    while (temp = temp->next, temp) Push(stack2, temp->e);
    short c = 0; // 进位
    PtrLink link_res = InitLink(); short x, y, z;
    while (!IsEmpty(stack1) && !IsEmpty(stack2)) {
        x = Pop(stack1); y = Pop(stack2); z = x+y+c;
        Push(stack_res, z%10); if (z>=10) c = 1; else c = 0;
    }
    while (!IsEmpty(stack1)) {
        x = Pop(stack1); z = x+c;
        Push(stack_res, z%10); if (z>=10) c = 1; else c = 0;
    }
    while (!IsEmpty(stack2)) {
        y = Pop(stack2); z = y+c;
        Push(stack_res, z%10); if (z>=10) c = 1; else c = 0;
    }
    while (GetTop(stack_res) == 0) Pop(stack_res);
    while (!IsEmpty(stack_res)) Insert(link_res, Pop(stack_res));
    return link_res;
}

int main()
{
    PtrLink link1 = InitLink(), link2 = InitLink();
    Insert(link1, 7); Insert(link1, 2); Insert(link1, 4); Insert(link1, 3);
    // 7243
    Insert(link2, 5); Insert(link2, 6); Insert(link2, 4);
    // 564
    PrintLink(link1); PrintLink(link2);
    PtrLink link3 = addTwoNumbers(link1, link2);
    PrintLink(link3);
    return 0;
}
