#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct BiTree {
    int data;
    struct BiTree* l;
    struct BiTree* r;
}BiTree, *PtrBiTree;

PtrBiTree InitBiTree (int data) {
    // 创造空树
    PtrBiTree root = (PtrBiTree)malloc(sizeof(BiTree));
    root->data = data; root->l = NULL; root->r = NULL;
    return root;
}

int IsEmpty (PtrBiTree root) {
    // 判断是否为空树
    if (root->l && root->r) return 0;
    else return 1;
}

PtrBiTree RightMin (PtrBiTree root) {
    // 找出右子树的最小节点
    PtrBiTree temp = root->r;
    if (temp->l) {
        while (!temp->l->l) temp = temp->l;
        return temp;
    } else return NULL;
}

PtrBiTree Insert (PtrBiTree root, int data) {
    // 插入元素
    PtrBiTree temp = root, new;
    while (temp) {
        new = temp;
        if (temp->data < data) temp = temp->r;
        else if (temp->data > data) temp = temp->l;
        else return temp;
    }
    
    temp = (PtrBiTree)malloc(sizeof(BiTree));
    temp->data = data; temp->l = NULL; temp->r = NULL;

    if (new->data < data) new->r = temp;
    else if (new->data > data) new->l = temp;
    return temp;
}

PtrBiTree FindData (PtrBiTree root, int data) {
    PtrBiTree temp = root;
    while (temp) {
        if (temp->data < data) temp = temp->r;
        else if (temp->data > data) temp = temp->l;
        else return temp;
    }
    return NULL;
}

int Delete (PtrBiTree root, int data) {
    // 删除元素
    
}

int main ()
{
    PtrBiTree root = InitBiTree(50);
    
    return 0;
}
