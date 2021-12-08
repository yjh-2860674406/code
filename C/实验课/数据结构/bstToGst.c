/*
1038. �Ѷ���������ת��Ϊ�ۼ���

����һ���������������뽫����ÿ���ڵ��ֵ�滻������
���ڻ��ߵ��ڸýڵ�ֵ�����нڵ�ֵ֮�͡�

����һ�£�������������������Լ��������
    �ڵ���������������� С�� �ڵ���Ľڵ㡣
    �ڵ���������������� ���� �ڵ���Ľڵ㡣
    ��������Ҳ�����Ƕ�����������
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
    ����������������� �� ��-��-��
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
    printf("**********�滻ǰ**********\n");
    Vist(root, 0);
    num = 0;
    bstToGst(root);
    printf("**********�滻��**********\n");
    Vist(root, 0);
    return 0;
}
