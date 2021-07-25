#include <stdio.h>

int main()
{
    int a = 99;
    FILE* f = fopen("Store.txt","w+");
    fwrite(&a,sizeof(int),1,f);
    int b = 100;
    rewind(f);
    fread(&b,sizeof(int),1,f);
    printf("%d\n", b);
    fclose(f);
}