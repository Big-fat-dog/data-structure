#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
    TreeNode* head = nullptr;
public:
    void flatten(TreeNode* root) {
        //采用头插法
        if(root==nullptr)return;
        //右左根
        flatten(root->right);
        flatten(root->left);
        root->left=nullptr;
        root->right=head;
        head = root;
    }
};