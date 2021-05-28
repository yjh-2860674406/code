#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check (char x)
// 检测 字符是否是字母（在字母的范围内）
{
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) return 1;
    else return 0;
}

int Judge (char x, char y)
// 通过 两个字符的差值进行判断是否为同一个字母
// 如果绝对值为0 则都是大写或小写
// 如果绝对值为32 则分别为大小写
{
    int n = (int) x-y;
    switch (n)
    // switch语句效率比if语句高
    {
        case 0 : return 1;
        case 32 : return 1;
        case -32 : return 1;
        default : return 0;
    }
}

int main()
{
    char input[100];
    // 创建数组
    gets(input);
    // scanf() 函数会漏掉空格
    int len = strlen(input);
    // 获取字符串的长度
    
    char* left = input;
    // 左指针为数组首地址
    char* right = left + len - 1;
    // 右指针为数组最后一个元素的地址

    while (left <= right)
    // 当左指针没遇到右指针时
    {
        if (Check(*left))
        // 判断左指针是否为字母
        {
            if (Check(*right))
            // 判断右指针是否为字母
            {
                if (Judge(*left++, *right--));
                // 判断两个字母是否相等 判断完后 左指针自动加一 右指针自动减一
                else { printf("Not a Palindrome"); return 0;}
                // 不是则打印提示并结束程序
            }
            else right--;
            // 不是则右指针减一
        }
        else left++;
        // 不是则左指针加一
    }
    printf("Palindrome");
}