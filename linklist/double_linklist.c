#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;//定义全局头指针
struct Node *GetNewNode(int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void InsertAtHead(int x){
    struct Node *newNode=GetNewNode(x);
    if(head==NULL){
        //处理空节点的情况
        head = newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void Print(){
    struct Node* temp=head;
    printf("forward:");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void ReversePrint(){
    struct Node *temp=head;
    if(temp==NULL)return;//如果是空链表直接退出
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("reverse:");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main(){
    head =NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtHead(4);
    Print();
    ReversePrint();
    InsertAtHead(6);
    Print();
    ReversePrint();
    return 0;
}