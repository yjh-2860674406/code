#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int element;
    struct Queue* next;
};

typedef struct Queue* Node;

Node MakeEmpty (void)
{
    Node queue = (Node)malloc(sizeof(struct Queue));
    queue->element = 0;
    queue->next = NULL;
    return queue;
}

int QueueEmpty(Node queue)
{
    if (queue->next == NULL) return 1;
    else return 0;
}

void Push (int value, Node queue)
{
    while (queue->next != NULL && queue->next->element > value) // 下一个指针不为空 且 下一个指针的元素大于要加入的值 (顺序不能变!)
    {
        queue = queue->next;
    }
    if (queue->next == NULL)
    {
        queue->next = (Node)malloc(sizeof(struct Queue));
        queue->next->element = value;
        queue->next->next = NULL;
        // 如果为空 即是队列中的最小值(末尾) 
    }
    else 
    {
        Node temp = (Node)malloc(sizeof(struct Queue));
        temp->element = value;
        temp->next = queue->next;
        queue->next = temp;
        // 否则在队列中
    }
}

void PopMax (Node queue)
{
    if (QueueEmpty(queue) == 1)
    {
        printf("这是空队列!");   
    }
    else 
    {
        Node temp = queue->next->next;
        free(queue->next);
        queue->next = temp;
    }
}

void PopMin (Node queue)
{
    if (QueueEmpty(queue) == 1)
    {
        printf("这是空列表!");
    }
    else 
    {
        while (queue->next->next != NULL)
        {
            queue = queue->next;
        }
        free(queue->next);
        queue->next = NULL;
    }
}

int main()
{
    Node queue = MakeEmpty();
    Push(3, queue);
    Push(4, queue);
    Push(10, queue);
    Push(2, queue);
    Push(1, queue);
    PopMax(queue);
    PopMin(queue);
    printf("%d", queue->next->next->next->element);
    return 0;
}