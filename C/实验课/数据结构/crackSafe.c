/*
753. 破解保险箱

有一个需要密码才能打开的保险箱。密码是 n 位数, 密码的每一位是 k 位序列 0, 1, ..., k-1 中的一个 。

你可以随意输入密码，保险箱会自动记住最后 n 位输入，如果匹配，则能够打开保险箱。
举个例子，假设密码是 "345"，你可以输入 "012345" 来打开它，只是你输入了 6 个字符.

请返回一个能打开保险箱的最短字符串。

提示：
    n 的范围是 [1, 4]
    k 的范围是 [1, 10]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_COUNT 10000       
int visited[MAX_COUNT] = {0};
char str[MAX_COUNT] = {0};
int len = 0;
int P = 0;

void dfs (int k, int i)
// 不断递归遍历数组，按照权值大到小遍历直到遍历回原点
// 即为遍历完欧拉回路
{
    i -= i / P * P;
    i *= 10;
    for (int j = 0; j < k; j++)
    {
        int t = i + j;
        if (!visited[t])
        {
            visited[t] = 1;
            dfs(k, t);
            str[len++] = j + '0';
        }
    }
}

char* crackSafe(int n, int k)
{
    memset(visited, 0, sizeof(visited));
    // 将数组全部初始化为0
    memset(str, 0, sizeof(str));
    // 将字符串全部初始化为0
    P = pow(10, n - 1);
    // P = 10的n-1次方
    visited[0] = 1;
    // 0号单元为1，其余为0
    len = 0;
    dfs(k, 0);
    for (int i = 0; i < n; i++) {
        str[len++] = '0';
    }
    return str;
}

int main(int argc, char const *argv[])
{
    int n = 0; int k = 0;
    scanf("%d,%d", &n, &k); getchar();
    char* x = crackSafe(n,k);
    printf("%s\n", x);
    return 0;
}
