#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct Array {
    int* array;
}Array, *PtrArray;

typedef struct Tree {
    int elem;
    char word;
    struct Tree *left;
    struct Tree *right;
}Tree, *PtrTree;

typedef struct Huffman {
    PtrArray array;
    char* word;
    int length; 
}Huffman, *PtrHuffman;

PtrTree InitTree (int elem, char word) {
    // 初始化树
    PtrTree tree = (PtrTree)malloc(sizeof(Tree));
    tree->left = NULL; tree->right = NULL; tree->elem = elem;
    tree->word = word; return tree;
}

PtrHuffman InitHuffman (int length) {
    // 初始化哈夫曼结构
    PtrHuffman huff = (PtrHuffman)malloc(sizeof(Huffman));
    huff->array = (PtrArray)malloc(length*sizeof(Array));
    huff->word = (char*)malloc(length*sizeof(char));
    huff->array = (PtrArray)malloc(sizeof(Array));
    for (int i=0; i<huff->length; i++) {
        huff->array[i].array = (int*)malloc(8*sizeof(int));
        huff->array[i].array[0] = -1;
    }
    huff->length = length;   
}

int IsEmpty (PtrTree tree) {
    // 判断是否为空树
    if (tree->left == NULL && tree->right == NULL) return 1;
    else return 0;
}

PtrTree InsertNode (PtrTree one, PtrTree two) {
    // 合成哈夫曼树
    PtrTree root = (PtrTree)malloc(sizeof(Tree));
    root->elem = one->elem+two->elem;
    if (one->elem < two->elem) {
        root->left = one; root->right = two;
    }
    else {
        root->left = two; root->right = one;
    }
    return root;
}

int ChangeHuff (PtrTree tree, PtrHuffman huff, int num) {
    if (tree->left) {
        huff->word[num++] = tree->left->word;
        char* temp = huff->array->array;
        while(*temp++ != '\0')
        *temp++ = '0'; *temp = '\0';
    }
    if (tree->right) {
        huff->word[num++] = tree->right->word;
        char* temp = huff->array->array;
        while(*temp++ != '\0')
        *temp++ = '1'; *temp = '\0';
    }
    ChangeHuff(tree->left, huff, num);
    ChangeHuff(tree->right, huff, num);
}

int main () {
    
}