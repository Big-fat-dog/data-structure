#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void Enqueue(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    //针对空队列的情况
    if(front==NULL&&rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void Dequeue(){
    struct Node* temp=front;
    //处理空的情况
    if(front==NULL)return;
    //只有一个节点的情况
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}