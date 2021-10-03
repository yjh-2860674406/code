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

int IsEmpty (PtrTree tree) {
    // 判断是否为空树
    if (tree->left == NULL && tree->right == NULL) return 1;
    else return 0;
}

PtrTree FindNode (PtrTree tree, int elem) {
    // 查找元素节点
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
    // 插入元素节点
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
//     // 删除元素节点
//     PtrTree temp = FindNode(tree, elem);
//     if (temp) {
        
//     }
// }

int SwapChild (PtrTree tree) {
    // 交换每个节点的左右节点
    // 可以用栈改良
    if (tree->left) SwapChild(tree->left);
    if (tree->right) SwapChild(tree->right);
    PtrTree temp = tree->left; tree->left = tree->right; tree->right = temp;
    return TRUE;
}

int VisitAll (PtrTree tree) {
    // 遍历
    // 可以用栈改良
    if (tree->left) VisitAll(tree->left);
    printf("%d\n", tree->elem);
    if (tree->right) VisitAll(tree->right);
    return TRUE;
}

int main ()
{
    PtrTree tree = InitTree(50);
    InsertNode(tree, 40);
    InsertNode(tree, 60);
    InsertNode(tree, 30);
    InsertNode(tree, 45);
    SwapChild(tree);
    VisitAll(tree);
    return 0;
}

