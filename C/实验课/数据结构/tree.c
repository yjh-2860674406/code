#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Tree {
    int elem;
    struct Tree *left;
    struct Tree *right;
}Tree, *PtrTree;

PtrTree InitTree (int elem) {
    // ��ʼ����
    PtrTree tree = (PtrTree)malloc(sizeof(Tree));
    tree->left = NULL; tree->right = NULL; tree->elem = elem;
    return tree;
}

int IsEmpty (PtrTree tree) {
    // �ж��Ƿ�Ϊ����
    if (tree->left == NULL && tree->right == NULL) return 1;
    else return 0;
}

PtrTree FindNode (PtrTree tree, int elem) {
    // ����Ԫ�ؽڵ�
    PtrTree temp = tree;
    while (1) {
        if (temp->elem > elem && temp->left != NULL) temp = temp->left;
        else if (temp->elem < elem && temp->right != NULL) temp = temp->right;
        else if (temp->elem > elem && temp->left == NULL) return NULL;
        else if (temp->elem < elem && temp->right == NULL) return NULL;
        else return temp;
    }
}

PtrTree InsertNode (PtrTree tree, int elem) {
    // ����Ԫ�ؽڵ�
    PtrTree temp = tree;
    PtrTree new;
    while (TRUE) {
        if (temp->elem > elem && temp->left != NULL) temp = temp->left;
        else if (temp->elem < elem && temp->right != NULL) temp = temp->right;
        else if (temp->elem > elem && temp->left == NULL) break;
        else if (temp->elem < elem && temp->right == NULL) break;
        else return temp;
    }
    if (temp->elem > elem) {
        temp->left = (PtrTree)malloc(sizeof(Tree));
        new = temp->left;
    }
    else {
        temp->right = (PtrTree)malloc(sizeof(Tree));
        new = temp->right;
    }
    new->elem = elem; new->left = NULL; new->right = NULL;
    return new;
}

// int DeleteNode (PtrTree tree, int elem) {
//     // ɾ��Ԫ�ؽڵ�
//     PtrTree temp = FindNode(tree, elem);
//     if (temp) {
        
//     }
// }

int SwapChild (PtrTree tree) {
    // ����ÿ���ڵ�����ҽڵ�
    // ������ջ����
    if (tree->left) SwapChild(tree->left);
    if (tree->right) SwapChild(tree->right);
    PtrTree temp = tree->left; tree->left = tree->right; tree->right = temp;
    return TRUE;
}

int VisitAll (PtrTree tree, int num) {
    // ����
    // ������ջ����
    num += 2;
    char* space = (char*)malloc(num);
    for (int i=0; i<num-1; i++) space[i] = ' ';
    space[num-1] = '\0';
    if (tree->left) VisitAll(tree->left, num);
    printf("%s%d\n", space, tree->elem);
    if (tree->right) VisitAll(tree->right, num);
    return TRUE;
}

int main ()
{
    int num=0;
    PtrTree tree = InitTree(50);
    InsertNode(tree, 40);
    InsertNode(tree, 60);
    InsertNode(tree, 30);
    InsertNode(tree, 45);
    InsertNode(tree, 20);
    InsertNode(tree, 35);
    InsertNode(tree, 70);
    SwapChild(tree);
    VisitAll(tree, num);
    return 0;
}

