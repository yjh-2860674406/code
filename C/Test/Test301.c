#include <stdio.h>
// a = 97 z = 122 Z = 96 A = 65
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
    printf("��������ĸ(��Сд����):\n");
    scanf("%s", &char_x);
    i = char_x;
    if (i >= 65 && i <= 96)
    {
        int j = i - 64;
        i += j;
        if (i > 96)
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
        printf("�������!\n");
        change(char_x);
    }
}
