#include <stdio.h>
#include <string.h>

int main()
{
    char a = 'a';
    int change = 0b11011111;
    a &= change;
    printf("%c\n", a);
}
