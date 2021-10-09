#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define PerHour 1.5
#define CHECK_id if (id==(-1)) { printf("车牌输入错误！请重新输入！\n"); continue; }
#define CHECK_time if (time==(-1)) { printf("时间输入错误！请重新输入！\n"); continue; }

typedef struct Car {
    int id;
    int time;
}Car, *PtrCar;

typedef struct Stack {
    Car car_stack[201];
    int MAX;
    int length;
}Stack, *PtrStack;

typedef struct Node {
    Car car;
    struct Node* next;
}Node, *PtrNode;

typedef struct Queue {
    PtrNode header;
    PtrNode base;
}Queue, *PtrQueue;

PtrStack InitStack () {
    // 初始化栈
    PtrStack stack = (PtrStack)malloc(sizeof(Stack));
    stack->length = 0;stack->MAX = 200;
    return stack;
}

PtrQueue InitQueue () {
    // 初始化队列
    PtrQueue queue = (PtrQueue)malloc(sizeof(Queue));
    queue->header = (PtrNode)malloc(sizeof(Node));
    queue->base = queue->header; queue->header->next = NULL;
    return queue;
}

int IsEmpty (PtrStack stack) {
    // 判断是否为空栈
    if (stack->length == 0) return 1;
    else return 0;
}

int IsFull (PtrStack stack) {
    // 判断是否为满栈
    if (stack->length >= 200) return 1;
    else return 0;
}

int IsEmptyQueue (PtrQueue queue) {
    // 判断是否为空队列
    if (queue->base == queue->header) return 1;
    else return 0;
}

int PushStack (PtrStack stack, Car car) {
    // 车入库
    stack->car_stack[stack->length+1] = car;
    stack->length++; return 1;
}

int PushQueue (PtrQueue queue, Car car) {
    // 车排队
    queue->base->next = (PtrNode)malloc(sizeof(Node));
    queue->base->next->car = car;
    queue->base = queue->base->next;
    return 1;
}

Car PopStack (PtrStack stack) {
    // 车出库
    stack->length--;
    return stack->car_stack[stack->length+1];
}

Car PopQueue (PtrQueue queue) {
    // 车出队
    PtrNode temp = queue->header->next;
    Car car = queue->header->next->car;
    free(queue->header); queue->header = temp;
    return car;
}

Car QueueLeave (PtrQueue queue, Car car) {
    // 车在过道上离开
    Car res; res.id = -1; res.time = -1;
    PtrNode p = queue->header;
    PtrNode temp;
    while (p->next != NULL && p->next->car.id != car.id) {
        p = p->next;
    }
    if (p->next != NULL) {
        res = p->next->car;
        temp = p->next->next;
        free(p->next); p->next = temp;
    } else return res;
    return car;
}

Car Leave (PtrStack stack, PtrStack stack2, PtrQueue queue, Car car_out) {
    // 车离开
    int id = car_out.id;
    int num = 1;
    Car car;
    for (int i=stack->length; i>=1; i--, num++) {
        if (stack->car_stack[i].id == id) {
            for (int j=0; j<num; j++){
                PushStack(stack2, PopStack(stack));
            }
            break;
        }
    }
    if (!IsEmpty(stack2)) {
        car = PopStack(stack2);
        for (int i=0; i<stack2->length; i++) {
            PushStack(stack, PopStack(stack2));
        }
        if (!IsEmptyQueue(queue)) {
            PushStack(stack, PopQueue(queue));
        }
    } else car = QueueLeave(queue, car_out);
    return car;
}

double Price (Car car_in, Car car_out) {
    // 计算价钱
    int time = car_out.time - car_in.time;
    double price = PerHour*time;
    printf("车号 %d 的停留时间：%d小时 需要缴费：%.1f元\n", car_out.id, time, price);
    return price;
}

int Carin (PtrStack stack, PtrQueue queue, int id, int time) {
    // 车进门
    Car car_in; car_in.id = id; car_in.time = time;
    if (!IsFull(stack)) PushStack(stack, car_in);
    else {
        PushQueue(queue, car_in);
    }
    return 1;
}

int Screen () {
    PtrStack parking1 = InitStack();
    PtrStack parking2 = InitStack();
    PtrQueue queue = InitQueue();
    Car car;
    while(1) {
        printf("***************************************************\n");
        printf("******************停车场管理系统*******************\n");
        printf("********请输入要执行的操作（A/D,id,time）：********\n");
        printf("******A:入库,D:出库****id:车牌号****time:时间******\n");
        char io; int id; int time;
        scanf("%c,%d,%d", &io, &id, &time); getchar();
        switch (io) {
            CHECK_id CHECK_time
            case 'a':
            case 'A':
            Carin(parking1, queue, id, time); break;
            case 'd':
            case 'D':
            CHECK_id CHECK_time
            car.id = id; car.time = time;
            Car in = Leave(parking1,parking2,queue,car);
            if (in.id == -1)
            {
                printf("该车不存在！请重新输入！\n");
                continue;
            }
            Price(in, car);
            break;
        }
    }
}

int Test () {
    // 停车场全满的情况
    PtrStack parking1 = InitStack();
    PtrStack parking2 = InitStack();
    PtrQueue queue = InitQueue();
    Car car;
    for (int i=1; i<=200; i++) {
        Carin(parking1, queue, i, i);
    }
    while(1) {
        printf("***************************************************\n");
        printf("******************停车场管理系统*******************\n");
        printf("********请输入要执行的操作（A/D,id,time）：********\n");
        printf("******A:入库,D:出库****id:车牌号****time:时间******\n");
        char io; int id=-1; int time;
        scanf("%c,%d,%d", &io, &id, &time); getchar();
        switch (io) {
            case 'a':
            case 'A':
            CHECK_id CHECK_time
            Carin(parking1, queue, id, time); break;
            case 'd':
            case 'D':
            CHECK_id CHECK_time
            car.id = id; car.time = time;
            Car in = Leave(parking1,parking2,queue,car);
            if (in.id == -1) {
                printf("该车不存在！请重新输入！\n"); continue;
            }
            Price(in, car);
            break;
            default:
            printf("输入错误！请重新输入！\n");
            continue;
        }
    }
}

int main()
{
    Screen();
}