#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};
int findmin(BstNode *root){
    //优先处理空树的情况
    if(root==NULL){
        cout<<"This is a empty tree!\n";
    }
    //写上终止条件哦！！！！！！！！！！！！
    if(root->left==NULL){
        return root->data;
    }
    return findmin(root->left);
}
