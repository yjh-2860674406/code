#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert (char* s, int numRows)
{
    int len = strlen(s);
    while(numRows == 1) return s;
    char* copy = (char*)malloc(len);
    int pian = numRows*2-2;
    int mov = pian;
    int num=0;
    for (int j=0; j<numRows; j++)
    {
        int k=0;
        int odd = -1;
        while (k<len)
        {
            odd++;
            copy[num] = s[j+k];
            num++;
            if ((odd+2)%2==0) 
            {
                if (mov!=0) k+=mov; else k+=pian-mov;
            }
            else if (pian-mov == 0) num--; else k+= (pian-mov);
        }
        mov -= 2;
    }
    return copy;
}

int main()
{
    char s[] = "AABB";
    char* cpoy = convert(s,2);
    for (int i=0; i<4; i++)
    {
        printf("%c", cpoy[i]);
    }
}