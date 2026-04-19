#include<iostream>
using namespace std;
struct Node{
    char data;
    Node* left;
    Node* right;
};
//前序遍历(root->left->right)
void preorder(Node* root){
    if(root==NULL){//处理空树，亦是退出递归条件（如果一颗树或者子树为空，就退出。
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    
}
void Inorder(Node *root){
    if(root==NULL){//处理空树，亦是退出递归条件（如果一颗树或者子树为空，就退出。
        return;
    }
    preorder(root->left);
    cout<<root->data;
    preorder(root->right);
}