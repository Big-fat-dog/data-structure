#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetnewNode(int data){
    BstNode* newNode=new BstNode();//在堆上面申请内存,地址保存在指针里面，方便我们操作
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
bool Search(BstNode* root,int data){
    if(root==NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data)return Search(root->left,data);
    else return Search(root->right,data);
}
BstNode* Insert(BstNode *root,int data){
    if(root==NULL){//处理空树的情况
        BstNode* newNode=GetnewNode(data);
        root = newNode;
        return root;
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
}
int main(){
    BstNode *root =NULL;//创建一个空树
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,20);
    int number;
    cout<<"please input number";
    cin>>number;
    if(Search(root,number)==true)cout<<"found";
    else cout<<"not found";
}