#include <stdio.h>
#include <stdlib.h>

typedef int* P;
// ���¶��� int* �����õıȽ϶�

void Print (int row,int column, P* A)
// ��ӡ����
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            printf("%d\t", A[j][i]);
        }
        printf("\n");
    }
}

P* Creat(void) 
// ����һ�����󣬶�̬�����к���
{
    int row;
    int column;

    printf("��������Ҫ�����ľ����������\n");
    scanf("%d", &row);
    getchar();
    printf("��������Ҫ�����ľ����������\n");
    scanf("%d", &column);
    getchar();

    P *A = (P*)malloc((column)*sizeof(P));
    // ����һ��һά��ָ������
    // ���Ҵ�Ÿ�������ĵ�ַ

    for (int i=0; i<column; i++)
    {
        A[i] = (P)malloc((row)*sizeof(int));
        // ��ָ�������е�ÿ��Ԫ�أ�ָ�룩�����ڴ�
        // ÿ��Ԫ��Ϊ����ָ��
        // �����˶�ά����
    }

    printf("��������������ʽ��ֵ(���������ÿ�и�ֵ)\n");
    int array[column*row];
    // ����һ��������Ҫ����������
    for (int i=0; i<row*column; i++)
    {
        scanf("%d", &array[i]);
        getchar();
        // �Ե����з�
    }
    int n=0;
    for (int i=0; i<row; i++)
    // ��Ƕ��forѭ�������󣨶�ά���飩��ֵ
    {
        for (int j=0; j<column; j++)
        {
            A[j][i] = array[n];
            n++;
        }
    }
    
    printf("����Ҫ�����ľ���\n");
    Print(row, column, A);
    return A;
    // ���ؾ����ַ
}

P* T (int row, int column, P* A)
// ת��
{
    P *AT = (P*)malloc(row*sizeof(P));
    
    for (int i=0; i<row; i++)
    {
        AT[i] = (P)malloc(column*sizeof(int));
    }
    // ������ά���鲢�����ڴ�

    int a;
    for (int i=0; i<row; i++)
    // �����ɵĶ�ά���鸳ֵ  
    // �±�ȡ��������
    {
        for (int j=0; j<column; j++)
        {
            AT[i][j] = A[j][i];
            a = A[j][i];
        }
    }

    printf("ת�ú����Ϊ��\n");
    Print(column, row, AT);
    return AT;
    // ���ؾ����ַ
}

P* mul (int row, int column, P* A, P* B)
// �˷�
{
    P* C = (P*)malloc(row*sizeof(P));
    for (int i=0; i<row; i++)
    {
        C[i] = (P)malloc(row*sizeof(int));
    }
    // ������ά���ݲ������ڴ�

    int temp = 0;
    // ����������˺����ֵ
    int array[row*row];
    // ����������Ҫ��������ֵ

    int num = 0;

    for (int i=0; i<row; i++)
    // ������Ƕ����������A �� ����B �����������
    {
        for (int j=0; j<row; j++)
        {
            for (int k=0; k<column; k++)
            {
                temp += A[k][i]*B[j][k];
                // �ۼ� Aĳ��Ԫ�ء�Bĳ��Ԫ�ص�ֵ
            }
            array[num] = temp;
            num +=1;
            temp = 0;
        }
    }

    num = 0;

    for (int i=0; i<row; i++)
    // �������е�ֵ�������
    {
        for (int j=0; j<row; j++)
        {
            C[j][i] = array[num];
            num += 1;
        }
    }
    printf("��˺�ľ���\n");
    Print(row,row,C);
    return C;
}

P* sub (int row, int columu, P*A, P* B)
// ����
{
    P* C = (P*)malloc(columu*sizeof(P));
    for (int i=0; i<columu; i++)
    {
        C[i] = (P)malloc(row*sizeof(int));
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<columu; j++)
        {
            C[j][i] = A[j][i] - B[j][i];
        }
    }

    printf("�����ľ���\n");
    Print(row, columu, C);
    return C;
}

P* add (int row, int columu, P*A, P* B)
// �ӷ�
{
    P* C = (P*)malloc(columu*sizeof(P));
    for (int i=0; i<columu; i++)
    {
        C[i] = (P)malloc(row*sizeof(int));
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<columu; j++)
        {
            C[j][i] = A[j][i] + B[j][i];
        }
    }

    printf("�����ľ���\n");
    Print(row, columu, C);
    return C;
}

P* power (int row, P* A)
// ������
{
    printf("��Ҫ��������Ĵη���\n");
    int n=0;
    scanf("%d", &n);
    getchar();
    P* a = (P*)malloc(row*sizeof(P));
    for (int i=0; i<row; i++)
    {
        a[i] = (P)malloc(row*sizeof(int));
    }    
    // ������ά���鲢�����ڴ�

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            a[i][j] = A[i][j];
        }
    }
    // ��ʱ a = A

    for (int i=n; i>1; i--)
    // ��n��ʼ��Ȼ��ݼ�1
    // ��forѭ������������
    // �ȵݹ��
    {
        a = mul(row,row,A,a);
    }

    printf("%d���ݵĽ����\n", n);
    Print(row, row, a);
    return a;
}

int main()
{
    int row = 2;
    int column = 3;
    printf("��������A��\n");
    P *A = Creat();
    P *AT = T(row, column, A);
    printf("A����ת�ã�\n");
    P *AAT = mul(row,column,A,AT);
    printf("��������B��\n");
    P *B = Creat();
    P *AsubB = sub(row,column,A,B);
    P *AaddB = add(row,column,A,B);

    printf("��������C\n");
    P *C = Creat();
    P *C3 = power(2,C);
}

