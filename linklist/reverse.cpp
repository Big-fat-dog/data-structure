#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head;
void Print(){
    Node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}
void Insert(int data){
    Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    Node *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
};
Node *Reverse(Node *head){
    Node *next,*prev,*current;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;//这里别忘了哦！
    }
    head=prev;//处理末尾连接
    return head;//便于打印链表
}
int main(){
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    head = Reverse(head);
    Print();
    return 0;
}
