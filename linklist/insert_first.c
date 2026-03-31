#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
struct Node* head;//这里声明了全局变量!
void Insert(int x){
    Node* temp=(Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
};
void Print(){
	struct Node *temp=head;
    printf("链表是:");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
};
int main(){
    head=NULL;//到目前为止，我们只有一个指向null的head指针
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);//输入一个数保存在n中
    for(i=0;i<n;i++){
        printf("Enter the number \n");
        scanf("%d",&x);//用x存储
        Insert(x);//我们要实现，在头部插入一个节点
        Print();//这里要实现打印完整链表
    }
    return 0;
};