
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
        parse(root->right,v);
        vv.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        parse(root,v);
        return v;
    }
};