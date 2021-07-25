#include <stdio.h>
#include <math.h>

// 对函数进行求值
int fx (int a, int b, float x)
{
    x = x/10;
    int y = 10*((a*x)+(b/x));
    return y;
}

int fx1 (int a, int b, float x)
{
    x = x/10;
    int y = 10*((a*x)+b);
    return y;
}

// 提取字符串中的参数
int* change ()
{
    char x;
    int num = 0;
    int time = 0;
    static int temp[2];
    int i=0;
    printf("请输入您要打印的函数图：\n");
    while ( (x=getchar()) != '\n')
    {
        if ((int)x >= 49 && (int)x <= 58 )
        {
            num *= 10;
            num += ((int)x-48);
        }
        else if (x == 'x' || x == '/' || x == 'q')
        {
            temp[i] = num;
            num = 0;
            i++;
        }
    }
    return temp;
}

// 初始化二维数组,创建坐标轴
void creat (int n, int m, char array[n][m])
{
    // 第一排初始化为 |
    for (int i=0; i<n; i++)
    {
        array[i][0] = '|';
    }
    // 第一行初始化为 —
    for (int j=0; j<m; j++)
    {
        array[0][j] = '-';
    }
    // 其余初始化为空格
    for (int i=1; i<n; i++)
    {
        for (int j=1; j<m; j++)
        {
            array[i][j] = ' ';
        }
    }
}

// 标记特定行特定列为 *
void addtion(int n, int m, char array[n][m], int* k)
{
    // 将第i列 第fx(i)行 标记* 
    for (int i=1; i<m; i++)
    {
    int y = fx(k[0], k[1], i);
    array[y][i] = '*';
    }
}

// 打印出二维数组(图像)
void paint (int x)
{
    int* k;
    // 从字符串中获得参数
    k = change();
    // 根据第一个参数确定y轴的长度
    int y = x*k[0];
    // 创建一个二维数组
    char array[x][y];
    // 初始化
    creat(x,y,array);
    // 标记（x，y）
    addtion(x, y, array, k);
    for (int i=x-1; i>=0; i--)
    {
        for (int j=0; j<y; j++)
        {
            printf("%c",array[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int x = 151;
    paint(x);
}