#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
};
struct Node *top = NULL;//在栈里，我们习惯用top代替head
void Push(int x)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top;
    top=temp;
}
void Pop(){
    struct Node *temp;
    if(top==NULL)return;//处理空栈
    temp=top;
    top=top->link;
    free(temp);
}