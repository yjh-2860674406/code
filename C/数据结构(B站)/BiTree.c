#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    char data;
    struct BiTNode *l, *r;
    
}BiTNode, *BiTree;

void CreatBiTree (BiTree *T)
{
    char c;
    scanf("%c", &c);
    if (' ' == c)
    {
        *T = NULL;   
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreatBiTree(&((*T)->l));
        CreatBiTree(&((*T)->r));
    }
}

void vist (BiTree T, int value)
{
    printf("%cÔÚµÚ%d²ã\n", T->data, value);
}

void Previou (BiTree T, int value)
{
    if (T != NULL)
    {
        vist(T, value);
        Previou(T->l, value+1);
        Previou(T->r, value+1);
    }
}

int main()
{
    BiTree head  = (BiTree)malloc(sizeof(BiTNode));
    CreatBiTree(&head);
    Previou(head, 1);
}