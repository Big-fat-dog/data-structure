#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    
    void trackback(vector<int>& candidates,int target,int sum,int index){
        if(sum==target){
            result.push_back(path);
            return;
        }
        // 剪枝：和超过 target，直接返回
        if (sum > target) {
            return;
        }
        //做选择
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);              // 做选择
            trackback(candidates, target, sum + candidates[i], i);  // 递归，传 i
            path.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        trackback(candidates,target,0,0);
        return result;
    }
};