#include <stdio.h>
#include <stdlib.h>

struct Tree 
{
    int data;
    struct Tree *left ;
    struct Tree *right ;
};

struct Tree* insert(struct Tree *tree, int num);
struct Tree* check(struct Tree *tree, int num);
void delete(struct Tree *tree, int num);
struct Tree* rightmin (struct Tree *tree);

int main ()
{
    struct Tree tree;
    tree.left = NULL;
    tree.right = NULL;
    tree.data = 40;
    insert(&tree, 4);insert(&tree, 50);insert(&tree, 100);insert(&tree, 49);
    insert(&tree, 1);insert(&tree, 2);insert(&tree, 3);insert(&tree, 30);
    insert(&tree, 31);insert(&tree, 29);insert(&tree, 90);insert(&tree, 110);
    delete(&tree, 50);delete(&tree, 60);
    return 0;
}


struct Tree* insert (struct Tree *tree, int num)
{
    if (tree == NULL)  // 如果 tree = NULL 就是到了尽头, 分配内存, 新建节点
    {
        // 分配内存
        tree = (struct Tree*)malloc(sizeof(struct Tree));
        // 初始化节点
        tree->right = tree->left = NULL;
        tree->data = num;
    }
    else
    if (num < tree->data) // 没到尽头就递归
    {
        tree->left = insert(tree->left, num);
    }
    else
    if (num > tree->data)
    {
        tree->right = insert(tree->right, num);
    }
    return tree;
}

struct Tree* check (struct Tree* tree, int num)
{
    if (tree == NULL) // 如果尽头没有找到, 那就是没有了
    {
        printf("%d isn't in this tree!\n");
        return NULL;
    }
    if (num < tree->data) // 找不到就递归
    {
        return check(tree->left, num);
    }
    else
    if (num > tree->data)
    {
        return check(tree->right, num);
    }
    else
    {
        // 找到了, 打印结果并返回地址
        printf("%d is in this tree.\n", num);
        return tree;
    } 
}

void delete(struct Tree *tree, int num)
{
    printf("Starting:\n"); // 开始
    if ((check(tree, num)) == NULL)
    {
        printf("Error!");
        return;
    }
    else
    {
    struct Tree* temp = NULL;
    while (tree != NULL)
    {
        if (num < tree->data)
        {
            temp = tree;
            tree = tree->left;
        }
        else if (num > tree->data)
        {
            temp = tree;
            tree = tree->right;
        }
        else 
        {
            break;
        }
    }   
    if (temp->right == tree)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            temp->right = NULL;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            temp->right = tree->left;
            free(tree);
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            temp->right = tree->right;
            free(tree);
        }
        else
        {
            temp = rightmin(tree);
            tree->data = temp->data;
            free(temp);
        }
    }
    else 
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            temp->left = NULL;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            temp->left = tree->left;
            free(tree);
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            temp->left = tree->right;
            free(tree);
        }
        else 
        {
            temp = rightmin(tree);
            tree->data = temp->data;
            free(temp);
        }
    }
    printf("Finsh.\n");
    }
}

struct Tree* rightmin (struct Tree *tree)
{
    tree = tree->right;         // 转到右节点
    while (tree->left != NULL)  // 递归找到最小(左)
    {
        tree = tree->left;
    }
    return tree;
}



/*   自己写的代码
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
}*/

/*     自己写的代码
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
}*/

