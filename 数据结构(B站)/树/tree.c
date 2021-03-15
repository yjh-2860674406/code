#include <stdio.h>
#include <stdlib.h>

struct Tree 
{
    int data;
    struct Tree *left ;
    struct Tree *right ;
};

void insert(struct Tree *tree, int num);
void check(struct Tree *tree, int num);
//void delete(struct Tree *tree, int num);

int main ()
{
    struct Tree tree;
    tree.left = NULL;
    tree.right = NULL;
    tree.data = 40;
    insert(&tree, 4);
    insert(&tree, 50);
    insert(&tree, 100);
    printf("%d\n", tree.left->data);
    printf("%d\n", tree.right->data);
    printf("%d\n", tree.right->right->data);
    check(&tree, 100);
    check(&tree, 20);
    return 0;
}

void insert(struct Tree *tree, int num)
{
    struct Tree *l = (struct Tree*)malloc(sizeof(struct Tree));
    l->left = NULL;
    l->right = NULL;

    struct Tree *temp = tree;
    
    while (temp->left != NULL && temp->right != NULL)
        if (num < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    if (num < temp->data)
    {
        temp->left = l;
        l->data = num;
    }
    else
    {
        temp->right = l;
        l->data = num;
    }
}

void check (struct Tree *tree, int num)
{
    int l=0;
    int r=0;
    struct Tree *temp = tree;
    while (temp->data != num && (temp->left != NULL || temp->right != NULL))
    {
        if (num < temp->data)
        {
            temp = temp->left;
            l ++;
        }
        else 
        {
            temp = temp->right;
            r ++;
        }
    }
    if (temp->data == num)
    {
        printf("%d in left : %d and right : %d\n", num, l ,r);   
    }
    else 
    {
        printf("%d isn't in this tree\n", num);
    }
}
/*
void delete(struct Tree *tree, int num)
{
    struct Tree *temp = tree;
    while (temp->data != num && (temp->left != NULL || temp->right != NULL))
    {
        if (num < temp->data)
        {
            temp = temp->left;
        }
        else 
        {
            temp = temp->right;
        }
    }
    if (num = temp->data)
    {
        temp = NULL;
        free(temp);
        printf("Succeseful delete %d\n", num);
    }
    else
    {
        printf("%d isn't in this tree!\n", num);
    }
}*/