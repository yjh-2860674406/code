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
    printf("������Ҫ��ӵ���Ʒ��ţ�\n");
    scanf("%ld", &id); getchar();
    if (Find(shop, id) == -1) {
        shop->commoditys[shop->all_nums].id = id;
        printf("������Ҫ��ӵ���Ʒ���ƣ�\n");
        scanf("%s", name); getchar();
        for (int i=0; i<5; i++) {
            shop->commoditys[shop->all_nums].name[i] = name[i];
        }
        printf("������Ҫ��ӵ���Ʒ���\n");
        scanf("%s", name); getchar();
        if (strcmp(name, "����Ʒ")) {
            shop->commoditys[shop->all_nums].type = Day;
        } else shop->commoditys[shop->all_nums].type = Food;
        printf("������Ҫ��ӵĿ��������\n");
        scanf("%d", &nums); getchar();
        shop->commoditys[shop->all_nums].nums = nums;
        printf("������Ҫ��ӵ���Ʒ���ۣ�\n");
        scanf("%d", &price); getchar();
        shop->commoditys[shop->all_nums].price = price;
        printf("�����ɣ�\n");
        shop->all_nums++;
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("�����Ʒ�Ѿ������ڲֿ��У�");
        return 0;
    }
    
}

int Change (PtrShop shop) {
    printf("������Ҫ�޸ĵ���Ʒ��ţ�\n");
    long id; char name[5]; int nums; int price;
    scanf("%ld", &id); getchar();
    if (Find(shop, id) != -1) {
        int index = Find(shop, id);
        printf("������Ҫ�޸ĺ����Ʒ���ƣ�\n");
        scanf("%s", name); getchar();
        for (int i=0; i<5; i++) {
            shop->commoditys[index].name[i] = name[i];
        }
        printf("������Ҫ�޸ĺ����Ʒ���\n");
        scanf("%s", name); getchar();
        if (strcmp(name, "����Ʒ")) {
            shop->commoditys[index].type = Day;
        } else shop->commoditys[index].type = Food;
        printf("������Ҫ�޸ĺ�Ŀ��������\n");
        scanf("%d", &nums); getchar();
        shop->commoditys[index].nums = nums;
        printf("������Ҫ�޸ĺ���Ʒ���ۣ�\n");
        scanf("%d", &price); getchar();
        shop->commoditys[index].price = price;
        shop->all_nums--;
        printf("�޸���ɣ�\n");
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("�ֿ���û�и���Ʒ��ţ�");
        return 0;
    }
}

int Delete (PtrShop shop) {
    printf("������Ҫɾ������Ʒ��ţ�\n");
    long id; scanf("%ld", &id); getchar();
    if (Find(shop, id) != -1) {
        int index = Find(shop, id);
        for (int i=index; i<shop->all_nums-1; i++) {
            shop->commoditys[i] = shop->commoditys[i+1];
        }
        printf("ɾ���ɹ���\n");
        Updata(shop);
        Print(shop);
        return 1;
    } else {
        printf("�ֿ���û�и���Ʒ��ţ�");
        return 0;
    }
}

void PrintAll (PtrShop shop) {
    for (int i=0; i<shop->all_nums; i++) {
        printf("��Ʒ��ţ�%ld\t��Ʒ���ƣ�%s\t", shop->commoditys[i].id, shop->commoditys[i].name);
        if (shop->commoditys[i].type == Day) printf("�������Ʒ\t");
        else printf("���ʳƷ\t");
        printf("���������%d\t���ۣ�%d\n", shop->commoditys[i].nums, shop->commoditys[i].price);
    }
}

void Print (PtrShop shop) {
    printf("����Ʒ���������%d\t����Ʒƽ���۸�%d\tʳƷ���������%d\tʳƷƽ���۸�%d\n", shop->day_nums, shop->ave_day, 
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
