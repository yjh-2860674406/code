#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrToNode;
typedef struct TreeNode Tree;
typedef int ElementType;

PtrToNode MakeEmpty (PtrToNode);
PtrToNode Find (ElementType, PtrToNode);
PtrToNode FindMin (PtrToNode T);
PtrToNode FindMax (PtrToNode T);

struct TreeNode
{
    ElementType Element;
    PtrToNode Left;
    PtrToNode Right;
};

int main()
{

}

PtrToNode MakeEmpty (PtrToNode T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

PtrToNode Find (ElementType X, PtrToNode T)
{
    if (T == NULL) return NULL;
    if (X < T->Element) return Find (X, T->Left);
    else if (X > T->Element) return Find (X, T->Right);
    else return T;
}

PtrToNode FindMin (PtrToNode T)
{
    if (T == NULL) return NULL;
    if (T->Left == NULL) return T;
    else return FindMin (T->Left);
}

PtrToNode FindMax (PtrToNode T)
{
    if (T == NULL) return NULL;
    if (T->Right == NULL) return T;
    else return FindMax (T->Right);
}

