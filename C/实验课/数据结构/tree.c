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
    // 初始化树
    PtrTree tree = (PtrTree)malloc(sizeof(Tree));
    tree->left = NULL; tree->right = NULL; tree->elem = elem;
    return tree;
}

void CreateTree (PtrTree* tree) {
    // 创造树
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
    // 交换每个节点的左右节点
    // // 可以用栈改良
    if (tree->left) SwapChild(tree->left);
    if (tree->right) SwapChild(tree->right);
    PtrTree temp = tree->left; tree->left = tree->right; tree->right = temp;
    return TRUE;
}

int VisitAll (PtrTree tree, int num) {
    // 遍历
    // 可以用栈改良
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
    printf("交换左右节点前：\n");
    VisitAll(tree, num);
    SwapChild(tree);
    printf("交换左右节点后：\n");
    VisitAll(tree, num);
    return 0;
}

