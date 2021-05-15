#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrToNode;
typedef struct TreeNode Tree;
typedef int ElementType;

PtrToNode MakeEmpty (PtrToNode);
PtrToNode Find (ElementType, PtrToNode);
PtrToNode FindMin (PtrToNode T);
PtrToNode FindMax (PtrToNode T);
PtrToNode InSert (ElementType X, PtrToNode T);
PtrToNode CreatTree ();
PtrToNode Delete (ElementType X, PtrToNode T);

struct TreeNode
{
    ElementType Element;
    PtrToNode Left;
    PtrToNode Right;
};

int main()
{
    PtrToNode root = CreatTree();
    InSert(3, root);
    InSert(4, root);
    Delete(3, root);
    printf("%d\n", root->Right->Element);
}

PtrToNode CreatTree ()
{
    PtrToNode T = (PtrToNode)malloc(sizeof(Tree));
    T->Left = NULL; T->Right = NULL; T->Element = 0;
    return T;
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
    // if (T == NULL) return NULL;
    // if (X < T->Element) return Find (X, T->Left);
    // else if (X > T->Element) return Find (X, T->Right);
    // else return T;
    while (T != NULL)
    {
        if (X < T->Element) T = T->Left;
        else if (X > T->Element) T = T->Right;
        else return T;
    }
    return T;
}

PtrToNode FindMin (PtrToNode T)
{
    // if (T == NULL) return NULL;
    // if (T->Left == NULL) return T;
    // else return FindMin (T->Left);
    while (T->Left != 0) T = T->Left;
    return T;
}

PtrToNode FindMax (PtrToNode T)
{
    // if (T == NULL) return NULL;
    // if (T->Right == NULL) return T;
    // else return FindMax (T->Right);
    while (T->Right != 0) T = T->Right;
    return T;
}

PtrToNode InSert (ElementType X, PtrToNode T)
{
    // if (T == NULL)
    // {
    //     T = (PtrToNode)malloc(sizeof(Tree));
    //     T->Left = NULL; T->Right = NULL;
    //     T->Element = X;
    // }
    // if (X < T->Element) T->Left = InSert (X, T->Left);
    // else if (X > T->Element) T->Right = InSert(X, T->Right);
    // return T;
    PtrToNode temp;
    while (T != NULL)
    {
        temp = T;
        if (X < T->Element)
        {
            T = T->Left;
        }
        else if (X > T->Element)
        {
            T = T->Right;
        }
    }
    T = (PtrToNode)malloc(sizeof(Tree));
    T->Element = X; T->Left = NULL; T->Right = NULL;
    if (X < temp->Element) temp->Left = T;
    else if (X > temp->Element) temp->Right = T;
}

PtrToNode Delete (ElementType X, PtrToNode T)
{
    // PtrToNode Temp;
    
    // if (X < T->Element) T->Left = Delete (X, T->Left);
    // else if (X > T->Element) T->Right = Delete (X, T->Right);
    // else if (T->Left && T->Right)
    // {
    //     Temp = FindMin(T->Right);
    //     T->Element = Temp->Element;
    //     T->Right = Delete(T->Element, T->Right);
    // }
    // else
    // {
    //     Temp = T;
    //     if (T->Left == NULL) T = T->Right;
    //     else if (T->Right == NULL) T = T->Left;
    //     free(Temp);
    // }
    // return T;
    PtrToNode temp;
    while (T != NULL)
    {
        if (X < T->Element) 
        {
            temp = T;
            T = T->Left;
        }
        else if (X > T->Element) 
        {
            temp = T;
            T = T->Right;
        }
        else break;
    }
    if (T == NULL) return NULL;
    else if (T->Left == NULL && T->Right == NULL)
    {
        if (X < temp->Element) temp->Left = NULL;
        else temp->Right = NULL;
        free (T);
    }
    else if (T->Left != NULL && T->Right != NULL)
    {
        T->Element = FindMin(T)->Element;
        free(FindMin(T));
    }
    else 
    {
        if (T->Left != NULL) 
        {
            if (X < temp->Element) temp->Left = T->Left;
            else temp->Right = T->Left;
        }
        else 
        {
            if (X < temp->Element) temp->Left = T->Right;
            else temp->Right = T->Right;
        }
        free (T);
    }
}