#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    char data;
    struct BiTNode *l, *r;
