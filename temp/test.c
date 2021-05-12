#include <stdio.h>
#include <string.h>

int main()
{
    char a[10];
    scanf("%s", a);
    printf("%d\n", sizeof(a));
    printf("%d\n", strlen(a));
}
