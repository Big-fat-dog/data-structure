#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node* findmin(Node *root){
    //优先处理空树的情况
    if(root==NULL){
        cout<<"This is a empty tree!\n";
    }
    //写上终止条件哦！！！！！！！！！！！！
    if(root->left==NULL){
        return root;
    }
    return findmin(root->left);
}

struct Node *Delete(Node* root,int data){
    if(root==NULL)return root;//处理空树
    //利用递归找到要删除的节点。
    else if(data<=root->data){//如果我们要找的树比根的值小，那么问题被降级为从左子树删除。
        root->left=Delete(root->left,data);
    }
    else if(data>root->data){
        root->right=Delete(root->right,data);
    }
    else{//小节点在吗，here is 胖狗，我要来删你咯！🤫
        //case1:no child
        if(root->left==NULL&&root->right==NULL){
            delete root;//虽然root指的内存被删了，但是root此时为悬空指针里面还有值，危险！
            root=NULL;//懂什么叫内存安全吗！
        }
        //case2:one child
        else if(root->left==NULL){
            Node *temp=root;
            root=root->right;
            delete temp;

        }
        else if(root->right==NULL){
            Node *temp=root;
            root=root->left;
            delete temp;

        }
        //case3:two child
        else{
            Node *temp;
            temp=findmin(root->right);//查找右子树最小值
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}