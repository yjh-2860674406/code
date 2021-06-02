#include <stdio.h>
#include <stdlib.h>
// 65 'A'

#define Z(z) ((z++)%26)+65
// ������ת���� A~Z�ķ�Χ��

int z=0;
// ����zΪ�������ӵ�����������ĸ
// ÿһ����z��������1���൱����ĸ+1

enum D {right, dowm, left, up};
// ö�ٷ���

char** Make (int m, int n)
// ��������
{
    char **array = (char **)malloc(n * sizeof(char));
    for (int i=0; i<n; i++)
    {
        array[i] = (char*)malloc(m*sizeof(char));
    }
    return array;
}

void Print (char** array, int m, int n)
// ��ӡ����
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
// �������Ԫ�ظ�ֵ
{
    enum D dir = right;
    // ��ʼ������Ϊ����
    int xr = 0;
    int yd = n;
    int xl = m;
    int yu = -1;
    // ��ʼ����������������ʼλ��

    while (m != 0 && n != 0)
    // ��ĳ������Ϊ0����ֹͣ
    {
        switch (dir) 
        // �жϷ���
        {
            case right :
            {
                for (int i=yu+1,x=0; x<n; i++,x++)
                // ���Ҹ�ֵ
                {
                    array[i][xr] = Z(z);
                }
                yd--;m--;
                // ���µ���ʼλ���Լ�1����������-1
                dir = dowm;
                // ��ΪΪ˳ʱ�룬�����Ϊ����
            }
            break;
            // ����ͬ��
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
    printf("����������к��У�\n");
    scanf("%d,%d", &m, &n);
    char** array = Make(m,n);
    Pull(array, m, n);
    Print(array,m, n);
    return 0;
}