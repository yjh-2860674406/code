#include <stdio.h>

struct Card
// 建立扑克牌的结构体（模型）
{
    char suit;
    int ranks;
};

struct Card cards[5]; // 5张扑克牌组成的数组
int array[5] = {1,2,3,4,5}; // 后面会用到的数组 1.存储每个牌的标识符
                            //                   = [(int)suit*10-ranks]
                            //                 2.存储每个数字出现的次数
                            //                   用来给不同的组合分类

int change (char c)
{
    // 将每个输入的字符转换成 2~14的数字 表示ranks
    if ((int)c < 58 && (int)c > 48) return (int)c-48;
    else if (c = 't') return (int)c-106;
    else if (c = 'j') return (int)c-95;
    else if (c = 'q') return (int)c-101;
    else if (c = 'k') return (int)c-94;
    else if (c = 'a') return (int)c-83;
}

int Check1 ()
{
    // 嵌套两层for循环 查看是否重复输入了牌  用标识符判断 （上面提到过）
    for (int i=0; i<5; i++)
    {
        for (int j=4; j>i; j--)
        {
            if (array[i] == array[j])
            {
                // 存在同样的标识符既重复输入一张牌 打印错误提示并返回0
                printf("Duplicate card, ignored.\n");
                return 0;
            }
        }   
    }
    return 1;
}

int Check2(char suit, int rank)
{
    // 检测是否输入的牌点数和花色不符合条件 
    if ((rank<2 || rank>14) || (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's'))
    {
        // 不符合则打印错误提示并返回0
        printf("Bad card,ignored.\n");
        return 0;
    }
    return 1;
}

void Input ()
{
    // 输入5张牌进入扑克牌数组中
    for (int i=0; i<5; i++)
    {
        int rank;
        char suit;

        printf("Enter a card: "); // 提示输入牌点数和花色
        scanf("%c%c", &rank, &suit); // 获取信息
        getchar(); // 吃掉一个换行符

        rank = change(rank); // 转化字符成点数 (上面有函数)

        array[i] = ((int)suit*10-rank); // 计算每张牌的标识符并推入数组
        if (Check1() == 0 || Check2(suit, rank) == 0) // 如果标识符数组内存在同样的标识符
                                                      // 如果牌点数和花色不符合条件
                                                      // 从现在的 i 重新开始
        {
            array[i] = i;
            i--;
            continue;
        }
        // 符合所以条件既将扑克牌存入数组中
        cards[i].ranks = rank;
        cards[i].suit = suit;
    }
}

void Sort ()
{
    // 用插入排序对扑克牌的点数进行排序 以便后面的判断
    for (int i=0; i<5; i++)
    {
        for (int j=i; j>0; j--)
        {
            if (cards[j].ranks < cards[j-1].ranks)
            {
                struct Card temp = cards[j];
                cards[j] = cards[j-1];
                cards[j-1] = temp;
            }
        }
    }
}

int IsFlush ()
{
    // 通过花色是否一样判断是否为同花
    if (cards[0].suit == cards[1].suit && cards[1].suit == cards[2].suit
    && cards[2].suit == cards[3].suit &&cards[3].suit == cards[4].suit) return 1;
    else return 0;
}

int IsStraight ()
{
    // 通过点数的差判断是否为顺子 （已经排序好）
    int num = 0;
    for (int i=1; i<5; i++)
    {
        if (cards[i].ranks - cards[i-1].ranks == 1) num++;
    }
    if (num == 4) return 1;
    else return 0;
}

int IsStraightFlush ()
{
    // 如果同时为同花和顺子即为同花顺
    if ((IsStraight() == 1) && (IsFlush() == 1)) return 1;
    else return 0;
}

void Statistics ()
{
    // 统计每张牌点数出现的次数
    int num=1;
    int index=0;

    for (int i=0; i<5; i++) array[i] = 0;
    // 将原来的标识符数组初始化为0

    for (int i=0; i<5; i++)
    {
        if (cards[i].ranks == cards[i+1].ranks) num++;
        else 
        {
            // 原来的标识符数组现在存储牌出现的次数
            array[index] = num;
            num = 1;
            index++;
        }
    }
}

int IsFour()
{
    // 如果只有两种点数的牌
    while (array[2] == 0)
    {
        // 且有一种牌的数量为1，则另一种为4，则为four-of-a-kind
        if ( array[0] == 1 || array[1] == 1) return 1;
        else return 0;
    }
    return 0;
}

int IsFullHouse()
{
    // 如果只有两种点数的牌
    while (array[2] == 0)
    {
        // 且有一种牌的数量为2，则另一种为3，则为full house
        if (array[0] == 2 || array[1] == 2) return 1;
        else return 0;
    }
    return 0;
}

int IsThree ()
{
    // 如果只有三种点数的牌
    while (array[3] == 0)
    {
        // 且只要一种牌的数量为3,则其他两种为1,1,则为three-of-a-kind
        if (array[0] == 3 || array[1] == 3 || array[2] ==3) return 1;
        else return 0;
    }
    return 0;
}

int IsTwoPair ()
{
    // 如果只有三种点数的牌
    while (array[3] == 0)
    {
        // 且只要其中一直牌的数量为2,则其他两种为2,1,则为two pairs
        if (array[0] == 2 || array[1] == 2) return 1;
        else return 0;
    }
    return 0;
}

int IsPair ()
{
    // 如果有四种点数的牌,则为pair
    while (array[4] == 0)
    {
        return 1;
    }
    return 0;
}

int Group()
{
    // 通过优先级将牌组的类型打印出来
    if (IsStraightFlush() == 1)
    {
        printf("Straight Flush\n");
        return 0;
    }
    else if (IsFour() == 1)
    {
        printf("Four-of-a-kind\n");
        return 0;
    }
    else if (IsFullHouse() == 1)
    {
        printf("Full House\n");
        return 0;
    }
    else if (IsFlush() == 1)
    {
        printf("Flush\n");
        return 0;
    }
    else if (IsStraight() == 1)
    {
        printf("Straight\n");
        return 0;
    }
    else if (IsThree() == 1)
    {
        printf("Three-of-a-kind\n");
        return 0;
    }
    else if (IsTwoPair() == 1)
    {
        printf("Two Pair\n");
        return 0;
    }
    else if (IsPair() == 1)
    {
        printf("Pair\n");
        return 0;
    }
    else
    {
        printf("High Card\n");
        return 0;
    }
}

int main()
{
    Input(); // 输入扑克牌
    Sort(); // 排序
    Statistics(); // 判断

    Group(); // 优先级打印
}