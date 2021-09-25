#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int elemtype;
typedef int status;
typedef struct node{
    elemtype data;
    struct node* next;
}node, *nodelink;


status Initlist(nodelink* head_link){
    nodelink newbase;                               //初始化头结点 此结点的data为表长！//
    newbase = (nodelink)malloc(sizeof(node));
    if(!newbase){
        return OVERFLOW;
    }
    else{
        (*head_link) = newbase;
        (*head_link)->data = 0;
        (*head_link)->next = NULL;
        return OK;
    }
}

status headcreatelist(nodelink head,elemtype n){
    nodelink p;                                         //头插法//
    for (elemtype i = 1; i <= n ; i++)
    {
        p = (nodelink)malloc(sizeof(node));
        if(!p){
            return OVERFLOW;
        }
        else{
            printf("第%d个元素是：\n",i);
            scanf("%d",&p->data);
            p->next = head->next;
            head->next = p;
            head->data++;
        }
    }
    return OK;
    
}

status Tailcreatelist(nodelink head,elemtype n){                  //尾插法//
    nodelink p;
    nodelink q = head;
    while (q->next != NULL)                                     
    {
        q = q->next;                        //定位到链表尾//
    }
    for (elemtype i = 1; i <= n; i++)
    {
        p = (nodelink)malloc(sizeof(node));
        if (!p)
        {
            return OVERFLOW;
        }
        else
        {
            printf("第%d个元素是：\n", i);
            scanf("%d", &p->data);
            p->next = NULL;
            q->next = p;
            q = p;
            head->data++;
        }
    }
    return OK;
}



void Getallnode(nodelink head){           //测试函数   打印链表数据//
    nodelink p;
    p = head->next;
    for(elemtype i = 1 ;; i++){
        if(!p){
            break;
            printf("出示完毕！\n");
        }
        printf("第%d个元素是：%d\n",i,p->data);
        p = p->next;
    }
}

status Getelem_L(nodelink head,elemtype i,elemtype *e_link){
    if(i>head->data){
        return ERROR;
    }
    nodelink p = head->next;
    for(elemtype j = 1; j < i; j++){          //获取某个数据函数//
        p = p->next;
        if(!p)
        {
            return ERROR;
        }  
    }
    *e_link = p->data;
    return OK;
}

status Listinsert_L(nodelink head, elemtype i, elemtype e){
    if(i > head->data+1 || i <= 0 ){
        return ERROR;
    }
    else{
        nodelink p = (nodelink)malloc(sizeof(node));
        if (!p)
        {
            return OVERFLOW;
        }
        else{
            nodelink q = head->next;
            for(elemtype j = 1; j < i-1 ; j++){
                q = q->next;
            }
            p->data = e;
            p->next = q->next;
            q->next = p;
            head->data++;
            return OK;
        }
        
    }
}

status Makenode(nodelink head,nodelink *p_link, elemtype e){          //指定指针指向指定元素所在结点//
    nodelink p = head->next;
    while(p->data != e || p->next != NULL ){
        p = p->next;
    }
    if(p->next == NULL && p->data !=e){
        printf("链表中无此元素！\n");
        return ERROR;
    } 
    else{
        (*p_link) = p;
        return OK;
    }
}

status Clearlist(nodelink head){          //清空链表//
    elemtype i;
    nodelink p = head->next;
    nodelink q;
    for( i = 1; i <= head->data; i++){
        q = p;
        p = p->next;
        free(q);
        head->data--;
    }
    head->next = NULL;
    return OK;
}


status Destroylist(nodelink *head_link){
    Clearlist((*head_link));
    free((*head_link));
    (*head_link) = NULL;
    return OK;
}


status Listdelete_L(nodelink head, elemtype i, elemtype *e_link){
    nodelink p = head->next;
    nodelink q = NULL;
    for(elemtype j = 1; j < i-1; j++){
        p = p->next;                                  //p指向第i-1个元素//
    }
    q = p->next;                                     //q指向第i个元素！//
    p->next = q->next;
    free(q);
    head->data--;
}

void Getlistlen(nodelink head){
    printf("该链表长%d个单位\n",head->data);
}


status Append(nodelink head, nodelink head2){
    nodelink p = head->next;
    nodelink q = head2->next;
    while(p->next!=NULL && p!=NULL ){
        p = p->next;
    }
    p->next = q;
}


nodelink Mergelist(nodelink head, nodelink head2,elemtype (*func)() ){
    nodelink p1 = head->next;
    nodelink p2 = head2->next;
    nodelink temp;
    nodelink head3 = (nodelink)malloc(sizeof(node));
    head3->data = 0;   head3->next = NULL;
    nodelink p3 = head3;
    while (p1 && p2)
    {
        switch ((*func)(p1->data,p2->data))
        {
        case 1:
            temp = (nodelink)malloc(sizeof(node));
            temp->data = p2->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = temp;
            p2 = p2->next; 
            break;
        
        case 0:
            temp = (nodelink)malloc(sizeof(node));
            temp->data = p2->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = temp;
            p1 = p1->next;
            p2 = p2->next;
            break;

        case -1:
            temp = (nodelink)malloc(sizeof(node));
            temp->data = p1->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = temp;
            p1 = p1->next;
            break;
        }
    }
    if(!p1){
        while(p2){
            temp = (nodelink)malloc(sizeof(node));
            temp->data = p2->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = temp;
            p2 = p2->next;
        }
    }
    else {
        while (p1)
        {
            temp = (nodelink)malloc(sizeof(node));
            temp->data = p1->data;
            temp->next = NULL;
            p3->next = temp;
            p3 = temp;
            p1 = p1->next;
        }
    }
    return head3;
}

elemtype compare (elemtype a, elemtype b) {

    if(a > b) return 1;
    else if (a == b) return 0;
    else if(a < b) return -1;
}





int main() {
    nodelink head = NULL;
    if(Initlist(&head)){
        printf("链表初始化成功！\n");
    }
    else{
        printf("出错！\n");
    }

    elemtype n;
    printf("你想构造多少个结点?\n");
    scanf("%d",&n);
    if(Tailcreatelist(head,n)){
        printf("添加成功！\n");
    }
    else{
        printf("出错！\n");
    }
    
    // elemtype i,e;
    // printf("你想访问第几号元素：\n");
    // scanf("%d",&i);
    // Getelem_L(head,i,&e);
    // printf("该元素是：%d\n",e);


    // printf("你想要插入什么数据：\n");
    // scanf("%d",&e);
    // printf("你想插入到第几个位置？\n");
    // scanf("%d",&i);
    // if(Listinsert_L(head, i, e)){
    //     printf("插入成功！\n");
    // }
    // else{
    //     printf("出错！\n");
    // }

    // printf("你想删除第几个元素：\n");
    // scanf("%d",&i);
    // if(Listdelete_L(head, i, &e)){
    //     printf("删除成功！\n");
    // }
    // else{
    //     printf("出错！\n");
    // }

    // nodelink plink;
    // printf("想要释放的元素: \n");
    // scanf("%d",&e);
    // if(Makenode(head,&plink, e)){                //将plink指向链表中想要的元素！//
    //     printf("已准备完毕\n");
    // }
    // else{
    //     printf("ERROR!\n");
    // }

    // Getallnode(head);
    // Getlistlen(head);

    nodelink head2 = NULL;
    if (Initlist(&head2))
    {
        printf("链表初始化成功！\n");
    }
    else
    {
        printf("出错！\n");
    }

    int num;

    printf("你想构造多少个结点?\n");
    scanf("%d",&num);
    if (Tailcreatelist(head2, num))
    {
        printf("添加成功！\n");
    }
    else
    {
        printf("出错！\n");
    }
    // Append(head,head2);               //合并两个函数//

    nodelink head3 = Mergelist(head,head2,compare);

    Getallnode(head3);

    return 0;
}