#include <stdio.h>
#include <stdlib.h>

typedef int* P;
// 重新定义 int* 后面用的比较多

void Print (int row,int column, P* A)
// 打印矩阵
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
// 创建一个矩阵，动态分配行和列
{
    int row;
    int column;

    printf("请输入您要创建的矩阵的行数：\n");
    scanf("%d", &row);
    getchar();
    printf("请输入您要创建的矩阵的列数：\n");
    scanf("%d", &column);
    getchar();

    P *A = (P*)malloc((column)*sizeof(P));
    // 创建一个一维的指针数组
    // 并且存放各个数组的地址

    for (int i=0; i<column; i++)
    {
        A[i] = (P)malloc((row)*sizeof(int));
        // 给指针数组中的每个元素（指针）分配内存
        // 每个元素为数组指针
        // 构成了二维数组
    }

    printf("请输入您的行列式的值(将会从左到右每行赋值)\n");
    int array[column*row];
    // 创建一个数组存放要填入矩阵的数
    for (int i=0; i<row*column; i++)
    {
        scanf("%d", &array[i]);
        getchar();
        // 吃掉换行符
    }
    int n=0;
    for (int i=0; i<row; i++)
    // 用嵌套for循环给矩阵（二维数组）赋值
    {
        for (int j=0; j<column; j++)
        {
            A[j][i] = array[n];
            n++;
        }
    }
    
    printf("您所要创建的矩阵：\n");
    Print(row, column, A);
    return A;
    // 返回矩阵地址
}

P* T (int row, int column, P* A)
// 转置
{
    P *AT = (P*)malloc(row*sizeof(P));
    
    for (int i=0; i<row; i++)
    {
        AT[i] = (P)malloc(column*sizeof(int));
    }
    // 创建二维数组并分配内存

    int a;
    for (int i=0; i<row; i++)
    // 将生成的二维数组赋值  
    // 下标取反就行了
    {
        for (int j=0; j<column; j++)
        {
            AT[i][j] = A[j][i];
            a = A[j][i];
        }
    }

    printf("转置后矩阵为：\n");
    Print(column, row, AT);
    return AT;
    // 返回矩阵地址
}

P* mul (int row, int column, P* A, P* B)
// 乘法
{
    P* C = (P*)malloc(row*sizeof(P));
    for (int i=0; i<row; i++)
    {
        C[i] = (P)malloc(row*sizeof(int));
    }
    // 创建二维数据并分配内存

    int temp = 0;
    // 储存行列相乘后的数值
    int array[row*row];
    // 创建数组存放要填入矩阵的值

    int num = 0;

    for (int i=0; i<row; i++)
    // 用三层嵌套来将矩阵A 和 矩阵B 进行行列相乘
    {
        for (int j=0; j<row; j++)
        {
            for (int k=0; k<column; k++)
            {
                temp += A[k][i]*B[j][k];
                // 累加 A某行元素×B某列元素的值
            }
            array[num] = temp;
            num +=1;
            temp = 0;
        }
    }

    num = 0;

    for (int i=0; i<row; i++)
    // 将数组中的值填入矩阵
    {
        for (int j=0; j<row; j++)
        {
            C[j][i] = array[num];
            num += 1;
        }
    }
    printf("相乘后的矩阵：\n");
    Print(row,row,C);
    return C;
}

P* sub (int row, int columu, P*A, P* B)
// 减法
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

    printf("相减后的矩阵：\n");
    Print(row, columu, C);
    return C;
}

P* add (int row, int columu, P*A, P* B)
// 加法
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

    printf("相减后的矩阵：\n");
    Print(row, columu, C);
    return C;
}

P* power (int row, P* A)
// 幂运算
{
    printf("您要的幂运算的次方：\n");
    int n=0;
    scanf("%d", &n);
    getchar();
    P* a = (P*)malloc(row*sizeof(P));
    for (int i=0; i<row; i++)
    {
        a[i] = (P)malloc(row*sizeof(int));
    }    
    // 创建二维数组并分配内存

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
        {
            a[i][j] = A[i][j];
        }
    }
    // 此时 a = A

    for (int i=n; i>1; i--)
    // 从n开始乘然后递减1
    // 用for循环进行幂运算
    // 比递归快
    {
        a = mul(row,row,A,a);
    }

    printf("%d次幂的结果：\n", n);
    Print(row, row, a);
    return a;
}

int main()
{
    int row = 2;
    int column = 3;
    printf("创建矩阵A：\n");
    P *A = Creat();
    P *AT = T(row, column, A);
    printf("A与其转置：\n");
    P *AAT = mul(row,column,A,AT);
    printf("创建矩阵B：\n");
    P *B = Creat();
    P *AsubB = sub(row,column,A,B);
    P *AaddB = add(row,column,A,B);

    printf("创建方阵C\n");
    P *C = Creat();
    P *C3 = power(2,C);
}

