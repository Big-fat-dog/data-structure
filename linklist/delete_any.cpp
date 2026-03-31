#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head;
void Insert(int data){
    Node* temp = new Node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    Node* temp2;
    temp2 = head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}//插在尾部
void Print(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n){
    Node* temp1=head;
    if(n==1){
        head=temp1->next;//处理删除头部的特殊情况
        delete temp1;
        return;
    }
    int i;
    for(i=0;i<n-2;i++){
        temp1=temp1->next;//实现到达n-1的位置
    }
    Node* temp2=temp1->next;//实现获得目标节点的位置！
    temp1->next=temp2->next;//n-1连上第n+1的节点
    delete temp2;
}//删除指定位置的节点
int main(){
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    cout<<("Enter a position\n");
    cin>>n;
    Delete(n);
    Print();
    return 0;
}