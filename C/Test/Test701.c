#include <stdio.h>
#include <math.h>

// �Ժ���������ֵ
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

// ��ȡ�ַ����еĲ���
int* change ()
{
    char x;
    int num = 0;
    int time = 0;
    static int temp[2];
    int i=0;
    printf("��������Ҫ��ӡ�ĺ���ͼ��\n");
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

// ��ʼ����ά����,����������
void creat (int n, int m, char array[n][m])
{
    // ��һ�ų�ʼ��Ϊ |
    for (int i=0; i<n; i++)
    {
        array[i][0] = '|';
    }
    // ��һ�г�ʼ��Ϊ ��
    for (int j=0; j<m; j++)
    {
        array[0][j] = '-';
    }
    // �����ʼ��Ϊ�ո�
    for (int i=1; i<n; i++)
    {
        for (int j=1; j<m; j++)
        {
            array[i][j] = ' ';
        }
    }
}

// ����ض����ض���Ϊ *
void addtion(int n, int m, char array[n][m], int* k)
{
    // ����i�� ��fx(i)�� ���* 
    for (int i=1; i<m; i++)
    {
    int y = fx(k[0], k[1], i);
    array[y][i] = '*';
    }
}

// ��ӡ����ά����(ͼ��)
void paint (int x)
{
    int* k;
    // ���ַ����л�ò���
    k = change();
    // ���ݵ�һ������ȷ��y��ĳ���
    int y = x*k[0];
    // ����һ����ά����
    char array[x][y];
    // ��ʼ��
    creat(x,y,array);
    // ��ǣ�x��y��
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