#include <stdio.h>
#include <stdlib.h>
// 65 'A'

#define Z(z) ((z++)%26)+65
// 将数字转换成 A~Z的范围内

int z=0;
// 设置z为不断增加的数来迭代字母
// 每一步，z都将自增1，相当于字母+1

enum D {right, dowm, left, up};
// 枚举方向

char** Make (int m, int n)
// 创建矩阵
{
    char **array = (char **)malloc(n * sizeof(char));
    for (int i=0; i<n; i++)
    {
        array[i] = (char*)malloc(m*sizeof(char));
    }
    return array;
}

void Print (char** array, int m, int n)
// 打印矩阵
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf("%c\t", array[j][i]);
        }
        printf("\n");
    }   
}

int Pull (char** array, int m, int n)
// 给矩阵的元素赋值
{
    enum D dir = right;
    // 初始化方向为向右
    int xr = 0;
    int yd = n;
    int xl = m;
    int yu = -1;
    // 初始化各个方向行列起始位置

    while (m != 0 && n != 0)
    // 当某个步长为0，则停止
    {
        switch (dir) 
        // 判断方向
        {
            case right :
            {
                for (int i=yu+1,x=0; x<n; i++,x++)
                // 向右赋值
                {
                    array[i][xr] = Z(z);
                }
                yd--;m--;
                // 向下的起始位置自减1，并且行数-1
                dir = dowm;
                // 因为为顺时针，方向改为向下
            }
            break;
            // 后面同理
            case dowm :
            {
                for (int i=xr+1,x=0; x<m; i++,x++)
                {
                    array[yd][i] = Z(z);
                }
                xl--;n--;
                dir = left;
            }
            break;
            case left :
            {
                for (int i=yd-1,x=0; x<n; i--,x++)
                {
                    array[i][xl] = Z(z);
                }
                yu++;m--;
                dir = up;
            }
            break;
            case up :
            {
                for (int i=xl-1,x=0; x<m; i--,x++)
                {
                    array[yu][i] = Z(z);
                }
                xr++;n--;
                dir = right;
            }
            break;
        }
        
    }   
}

int main()
{
    int m, n;
    printf("请输入矩阵行和列：\n");
    scanf("%d,%d", &m, &n);
    char** array = Make(m,n);
    Pull(array, m, n);
    Print(array,m, n);
    return 0;
}