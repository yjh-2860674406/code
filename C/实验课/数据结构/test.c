#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Type {Day, Food};

typedef struct Commodity {
    long id;
    char name[5];
    enum Type type;
    int nums;
    int price;
}Commodity, *PtrComodity;

typedef struct Shop {
    PtrComodity commoditys;
    int day_nums;
    int food_nums;
    int all_nums;
    double ave_day;
    double ave_food;
    int size;
}Shop, *PtrShop;

PtrShop CreatShop () {
    PtrShop shop = (PtrShop)malloc(sizeof(Shop));
    shop->day_nums = shop->food_nums = shop->all_nums = 0;
    shop->ave_day = shop->ave_food = 0; shop->size = 20;
    shop->commoditys = (PtrComodity)malloc(sizeof(Commodity)*20);
}

int IsFull (PtrShop shop) {
    if (shop->all_nums == shop->size) return 1;
    else return 0;
}

void extend (PtrShop shop) {
    shop->size += 20;
    shop->commoditys = (PtrComodity)realloc(shop->commoditys, sizeof(Commodity)*shop->size);
}

void Updata (PtrShop shop) {
    int day_nums = 0, food_nums = 0, price_day = 0, price_food = 0;
    for (int i=0; i<shop->all_nums; i++) {
        if (shop->commoditys[i].type == Day) {
            day_nums += 1;
            price_day += shop->commoditys[i].price*shop->commoditys[i].nums;
        } else {
            food_nums += 1;
            price_food += shop->commoditys[i].price*shop->commoditys[i].nums;
        }
    }
    shop->day_nums = day_nums; shop->food_nums = food_nums;
    if (day_nums!=0) shop->ave_day = price_day/day_nums; else shop->ave_day = 0;
    if (food_nums!=0) shop->ave_food = price_food/food_nums; else shop->ave_food = 0;
}

int Find (PtrShop shop, long id) {
    for (int i=0; i<shop->all_nums; i++) {
        if (id == shop->commoditys[i].id) return i;
    } return -1;
}

int Add (PtrShop shop) {
    if (IsFull(shop)) extend(shop);
    long id; char name[5]; int nums; int price;
    printf("请输入要添加的商品编号：\n");
    scanf("%ld", &id); getchar();
    if (Find(shop, id) == -1) {
        shop->commoditys[shop->all_nums].id = id;
        printf("请输入要添加的商品名称：\n");
        scanf("%s", name); getchar();
        for (int i=0; i<5; i++) {
            shop->commoditys[shop->all_nums].name[i] = name[i];
        }
        printf("请输入要添加的商品类别：\n");
        scanf("%s", name); getchar();
        if (strcmp(name, "日用品")) {
            shop->commoditys[shop->all_nums].type = Day;
        } else shop->commoditys[shop->all_nums].type = Food;
        printf("请输入要添加的库存数量：\n");
        scanf("%d", &nums); getchar();
        shop->commoditys[shop->all_nums].nums = nums;
        printf("请输入要添加到商品单价：\n");
        scanf("%d", &price); getchar();
        shop->commoditys[shop->all_nums].price = price;
        printf("添加完成！\n");
        shop->all_nums++;
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("这个商品已经存在于仓库中！");
        return 0;
    }
    
}

int Change (PtrShop shop) {
    printf("请输入要修改的商品编号：\n");
    long id; char name[5]; int nums; int price;
    scanf("%ld", &id); getchar();
    if (Find(shop, id) != -1) {
        int index = Find(shop, id);
        printf("请输入要修改后的商品名称：\n");
        scanf("%s", name); getchar();
        for (int i=0; i<5; i++) {
            shop->commoditys[index].name[i] = name[i];
        }
        printf("请输入要修改后的商品类别：\n");
        scanf("%s", name); getchar();
        if (strcmp(name, "日用品")) {
            shop->commoditys[index].type = Day;
        } else shop->commoditys[index].type = Food;
        printf("请输入要修改后的库存数量：\n");
        scanf("%d", &nums); getchar();
        shop->commoditys[index].nums = nums;
        printf("请输入要修改后到商品单价：\n");
        scanf("%d", &price); getchar();
        shop->commoditys[index].price = price;
        shop->all_nums--;
        printf("修改完成！\n");
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("仓库中没有该商品编号！");
        return 0;
    }
}

int Delete (PtrShop shop) {
    printf("请输入要删除的商品编号：\n");
    long id; scanf("%ld", &id); getchar();
    if (Find(shop, id) != -1) {
        int index = Find(shop, id);
        for (int i=index; i<shop->all_nums-1; i++) {
            shop->commoditys[i] = shop->commoditys[i+1];
        }
        printf("删除成功！\n");
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("仓库中没有该商品编号！");
        return 0;
    }
}

void PrintAll (PtrShop shop) {
    for (int i=0; i<shop->all_nums; i++) {
        printf("商品编号：%ld\t商品名称：%s\t", shop->commoditys[i].id, shop->commoditys[i].name);
        if (shop->commoditys[i].type == Day) printf("类别：日用品\t");
        else printf("类别：食品\t");
        printf("库存数量：%d\t单价：%d\n", shop->commoditys[i].nums, shop->commoditys[i].price);
    }
}

void Print (PtrShop shop) {
    printf("日用品库存数量：%d\t日用品平均价格：%d\t食品库存数量：%d\t食品平均价格：%d\n", shop->day_nums, shop->ave_day, 
    shop->food_nums, shop->ave_food);
}

void Sort (PtrShop shop) {
    for (int i=1; i<shop->all_nums; i++) {
        if (shop->commoditys[i].nums > shop->commoditys[i-1].nums) {
            for (int j=i; j>0; j--) {
                if (shop->commoditys[j].nums > shop->commoditys[j-1].nums) {
                    Commodity temp = shop->commoditys[j];
                    shop->commoditys[j] = shop->commoditys[j-1];
                    shop->commoditys[j-1] = temp;
                }
            }
        }
    }
    PrintAll(shop);
}

int main(int argc, char const *argv[])
{
    PtrShop shop = CreatShop();
    Add(shop);
    Add(shop);
    Add(shop);
    Add(shop);
    Add(shop);
    Add(shop);
    Sort(shop);
    PrintAll(shop);
    return 0;
}
