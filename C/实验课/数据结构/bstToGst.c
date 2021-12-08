/*
1038. 把二叉搜索树转换为累加树

给定一个二叉搜索树，请将它的每个节点的值替换成树中
大于或者等于该节点值的所有节点值之和。

提醒一下，二叉搜索树满足下列约束条件：
    节点的左子树仅包含键 小于 节点键的节点。
    节点的右子树仅包含键 大于 节点键的节点。
    左右子树也必须是二叉搜索树。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int e;
    struct Node* l;
    struct Node* r;
}Node, *PtrNode;

PtrNode InitTree (int e) {
    PtrNode root = (PtrNode)malloc(sizeof(Node));
    root->e = e; root->l = NULL; root->r = NULL;
    return root;
}

int num;

int Insert (PtrNode root, int e) {
    PtrNode temp = root; PtrNode p = root;
    while (temp) {
        if (temp->e < e) {
            p = temp; temp = temp->r;
        }
        else if (temp->e > e) {
            p = temp;
            temp = temp->l;
        }
        else return 0;
    }
    if (p->e < e) p->r = InitTree(e);
    else p->l = InitTree(e);
    return 1;
}

void test (PtrNode root) {
    Insert(root, 1); Insert(root, 0); Insert(root, 2);
    Insert(root, 3); Insert(root, 6); Insert(root, 5);
    Insert(root, 7); Insert(root, 8);
}

void bstToGst (PtrNode root) {
    /*
    反向中序遍历二叉树 即 右-中-左
    */
    if (root->r) bstToGst(root->r);
    num += root->e; root->e = num;
    if (root->l) bstToGst(root->l);
}

void Vist (PtrNode root, int num) {
    if (root->r) Vist(root->r, num+1);
    for (int i=0; i<num; i++) printf("\t");
    printf("%d\n", root->e);
    if (root->l) Vist(root->l, num+1);
}

int main()
{
    PtrNode root = InitTree(4);
    test(root);
    printf("**********替换前**********\n");
    Vist(root, 0);
    num = 0;
    bstToGst(root);
    printf("**********替换后**********\n");
    Vist(root, 0);
    return 0;
}
