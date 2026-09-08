
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
private:
    int dfs(TreeNode* node,long long cursum,int targetSum,unordered_map<long long,int> &prefix_sum){
        if(!node)return 0;

        //深度优先，构建前缀和以及查账
        cursum+=node->val;

        //判断是否符合公式,注意哈希表存的是前缀和和次数
        //注意这一步，必须先查账再插入，否则将会有错误
        int count = prefix_sum[cursum-targetSum];

        //存入哈希表
        prefix_sum[cursum]++;
        
        count+=dfs(node->left,cursum,targetSum,prefix_sum);
        count+=dfs(node->right,cursum,targetSum,prefix_sum);

        //回溯,在一侧的子树遍历完后，不能让他干扰另一侧的子树
        prefix_sum[cursum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        //利用前缀和公式：pre = cur - target，以及哈希表。如果表里有这个记录则说明是存在这么一条路径的
        unordered_map<long long,int> prefix_sum;
        prefix_sum[0]=1;//初始化哈希表，防止漏掉root即为target
        return dfs(root,0,targetSum,prefix_sum);
    }
};