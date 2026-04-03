#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void Print(struct Node *p){
    if(p==NULL)return;//防止无限递归
    printf("%d",p->data);//先打印当前数据
    Print(p->next);//递归继续调用函数
}
struct Node* Insert(struct Node *head,int data){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return head;
    }
    struct Node *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    return head;
};
struct Node* Reverse(struct Node *current){
    if(current==NULL||current->next==NULL){//处理单链表或者空链表
        return current;
    }
    struct Node* newhead = Reverse(current->next);
    // 反转当前连接
    struct Node *q = current->next; 
    q->next=current;  // 让下一个节点指向当前节点
    current->next = NULL;        // 断开当前节点的原连接
    return newhead;
}
int main(){
    struct Node *head=NULL;
    head=Insert(head,2);
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,5);
    Print(head);
    printf("\n");
    head=Reverse(head);
    Print(head);
    return 0;
}
