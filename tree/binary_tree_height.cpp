#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};
int findheight(BstNode *root){
    if(root==NULL){//处理空树的情况，亦是递归终止条件
        return -1;
    }
    return max(findheight(root->left),findheight(root->right))+1;
}
int main(){
    BstNode *root=NULL;
    int height = findheight(root);
    cout<<height;
}