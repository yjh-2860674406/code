#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef struct {
    char* ch;
    int length;
}HString, *PtrHString;

int Replace (PtrHString S, char T[], char V[]) {
    
}