#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* findmin(Node *root){
    if(root==NULL)return NULL;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node *find(Node *root,int data);
Node* Getsuccessor(Node* root,int data){
    //找到该节点
    Node* current=find(root,data);
    if(current==NULL)return NULL;
    //case1:node has right subtree
    if(current->right!=NULL){
        Node* temp= current->right;
        while(temp->left!=NULL)temp=temp->left;
        return temp;
    }
    //case2:no right subtree
    else {
        Node *successor=NULL;
        Node *ancestor=root;//祖先节点从根走下来
        while(ancestor!=current){//判断从根一步步走下来的ancestor是否和当前节点重合
            if(current->data<ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;//在最后一次，ancestor会被赋值成current。
            }
            else ancestor=ancestor->right;
        }
        return successor;
    }
}