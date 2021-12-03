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

void CreateTree (PtrTree* tree) {
    // ������
    int e; scanf("%d", &e); getchar();
    if (e == 0) {
        *tree = NULL;
    } else {
        *tree = (PtrTree)malloc(sizeof(Tree));
        (*tree)->elem = e;
        CreateTree(&(*tree)->left);
        CreateTree(&(*tree)->right);
    }
}

int SwapChild (PtrTree tree) {
    // ����ÿ���ڵ�����ҽڵ�
    // // ������ջ����
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
    PtrTree tree = (PtrTree)malloc(sizeof(Tree));
    CreateTree(&tree);
    printf("�������ҽڵ�ǰ��\n");
    VisitAll(tree, num);
    SwapChild(tree);
    printf("�������ҽڵ��\n");
    VisitAll(tree, num);
    return 0;
}

