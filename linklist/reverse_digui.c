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
void RPrint(struct Node *p){
    if(p==NULL)return;//防止无限递归
    Print(p->next);//递归继续调用函数
    printf("%d",p->data);//先打印当前数据
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

int main(){
    struct Node *head=NULL;
    head=Insert(head,2);
    head=Insert(head,4);
    head=Insert(head,6);
    head=Insert(head,5);
    Print(head);
    printf("\n");
    RPrint(head);
}