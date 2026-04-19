#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
void Leverorder(Node *root){
    if(root=NULL)return;
    queue<Node*> Q;
    Q.push(root);//处理根节点
    while(!Q.empty()){
        Node* current= Q.front();//放回队首指针
        cout<<current->data<<" ";
        if(current->left!=NULL){
            Q.push(current->left);
        }
        if(current->right!=NULL){
            Q.push(current->right);
        }
        Q.pop();
    }
}