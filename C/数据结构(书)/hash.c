#include <stdio.h>

struct Hash 
{
    int key;
    struct Table* NEXT;
};

struct Table
{
    int Element;
    struct Table* NEXT;
};

void InsertElement (struct Hash array[],int n,int key,int element)
{
    struct Hash* temp;
    for (int i; i<n; i++)
    {
        if (array[i].key = key)
        {
            temp = array;
        }
    }
    struct Table* temptable;
}

int main ()
{
    struct Hash array[10];
    for (int i=0; i<10; i++)
    {
        array[i].key = i;
    }
    struct Table Array[10];
    for (int i=0; i<10; i++)
    {
        array[i].NEXT = &Array[i];
    }
}

