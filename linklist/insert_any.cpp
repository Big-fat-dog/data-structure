#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void Insert(int data,int n){
    Node* temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;
    //处理特殊情况
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    Node* temp2=head;
    for(int i=0;i<n-2;i++){//注意这里的n-2，从0到n-2实现了达到n-1的效果，所以也可以写成i<=n-1;画个图就很好理解了！
        temp2=temp2->next;//这个循环实现的效果就是让指针到达n位置~！
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head =NULL;//表示空链表
    Insert(2,1);//List:2
    Insert(3,2);//List:2,3
    Insert(4,1);//List:4,2,3
    Insert(5,2);//List:4,5,2,3
    Print();
}