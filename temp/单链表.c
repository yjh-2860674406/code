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
    nodelink newbase;                               //��ʼ��ͷ��� �˽���dataΪ����//
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
    nodelink p;                                         //ͷ�巨//
    for (elemtype i = 1; i <= n ; i++)
    {
        p = (nodelink)malloc(sizeof(node));
        if(!p){
            return OVERFLOW;
        }
        else{
            printf("��%d��Ԫ���ǣ�\n",i);
            scanf("%d",&p->data);
            p->next = head->next;
            head->next = p;
            head->data++;
        }
    }
    return OK;
    
}

status Tailcreatelist(nodelink head,elemtype n){                  //β�巨//
    nodelink p;
    nodelink q = head;
    while (q->next != NULL)                                     
    {
        q = q->next;                        //��λ������β//
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
            printf("��%d��Ԫ���ǣ�\n", i);
            scanf("%d", &p->data);
            p->next = NULL;
            q->next = p;
            q = p;
            head->data++;
        }
    }
    return OK;
}



void Getallnode(nodelink head){           //���Ժ���   ��ӡ��������//
    nodelink p;
    p = head->next;
    for(elemtype i = 1 ;; i++){
        if(!p){
            break;
            printf("��ʾ��ϣ�\n");
        }
        printf("��%d��Ԫ���ǣ�%d\n",i,p->data);
        p = p->next;
    }
}

status Getelem_L(nodelink head,elemtype i,elemtype *e_link){
    if(i>head->data){
        return ERROR;
    }
    nodelink p = head->next;
    for(elemtype j = 1; j < i; j++){          //��ȡĳ�����ݺ���//
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

status Makenode(nodelink head,nodelink *p_link, elemtype e){          //ָ��ָ��ָ��ָ��Ԫ�����ڽ��//
    nodelink p = head->next;
    while(p->data != e || p->next != NULL ){
        p = p->next;
    }
    if(p->next == NULL && p->data !=e){
        printf("�������޴�Ԫ�أ�\n");
        return ERROR;
    } 
    else{
        (*p_link) = p;
        return OK;
    }
}

status Clearlist(nodelink head){          //�������//
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
        p = p->next;                                  //pָ���i-1��Ԫ��//
    }
    q = p->next;                                     //qָ���i��Ԫ�أ�//
    p->next = q->next;
    free(q);
    head->data--;
}

void Getlistlen(nodelink head){
    printf("������%d����λ\n",head->data);
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
        printf("�����ʼ���ɹ���\n");
    }
    else{
        printf("����\n");
    }

    elemtype n;
    printf("���빹����ٸ����?\n");
    scanf("%d",&n);
    if(Tailcreatelist(head,n)){
        printf("��ӳɹ���\n");
    }
    else{
        printf("����\n");
    }
    
    // elemtype i,e;
    // printf("������ʵڼ���Ԫ�أ�\n");
    // scanf("%d",&i);
    // Getelem_L(head,i,&e);
    // printf("��Ԫ���ǣ�%d\n",e);


    // printf("����Ҫ����ʲô���ݣ�\n");
    // scanf("%d",&e);
    // printf("������뵽�ڼ���λ�ã�\n");
    // scanf("%d",&i);
    // if(Listinsert_L(head, i, e)){
    //     printf("����ɹ���\n");
    // }
    // else{
    //     printf("����\n");
    // }

    // printf("����ɾ���ڼ���Ԫ�أ�\n");
    // scanf("%d",&i);
    // if(Listdelete_L(head, i, &e)){
    //     printf("ɾ���ɹ���\n");
    // }
    // else{
    //     printf("����\n");
    // }

    // nodelink plink;
    // printf("��Ҫ�ͷŵ�Ԫ��: \n");
    // scanf("%d",&e);
    // if(Makenode(head,&plink, e)){                //��plinkָ����������Ҫ��Ԫ�أ�//
    //     printf("��׼�����\n");
    // }
    // else{
    //     printf("ERROR!\n");
    // }

    // Getallnode(head);
    // Getlistlen(head);

    nodelink head2 = NULL;
    if (Initlist(&head2))
    {
        printf("�����ʼ���ɹ���\n");
    }
    else
    {
        printf("����\n");
    }

    int num;

    printf("���빹����ٸ����?\n");
    scanf("%d",&num);
    if (Tailcreatelist(head2, num))
    {
        printf("��ӳɹ���\n");
    }
    else
    {
        printf("����\n");
    }
    // Append(head,head2);               //�ϲ���������//

    nodelink head3 = Mergelist(head,head2,compare);

    Getallnode(head3);

    return 0;
}