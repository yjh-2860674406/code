#include <stdio.h>
// a = 97 z = 122 Z = 90 A = 65
void change (char);

int main()
{
    char char_x;
    change(char_x);
    return 0;
}

void change (char char_x)
{
    int i = 0;
    printf("请输入字母(大小写均可):\n");
    scanf("%c", &char_x);
    i = char_x;
    if (i >= 65 && i <= 90)
    {
        int j = i - 64;
        i += j;
        if (i > 90)
        {
            i -= 26;
        }
        printf("%c\n", i);
    }
    else if (i>=97 && i<=122)
    {
        int j = i - 96;
        i += j;
        if (i > 122)
        {
            i -= 26;
        }
        printf("%c\n", i);
    }
    else 
    {
        printf("输入错误!\n");
        change(char_x);
    }
}
