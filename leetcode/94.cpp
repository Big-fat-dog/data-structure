
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include<iostream>
#include<vector>
using namespace std;
class Solution {
vector<int> v;

public:
    void parse(TreeNode *root,vector<int> &vv){
        if(root==nullptr)return;
        parse(root->left,v);
        vv.push_back(root->val);

        parse(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        parse(root,v);
        return v;
    }
    
};