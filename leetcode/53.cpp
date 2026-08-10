#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0,maxAns=nums[0];
        for(const auto &x:nums){
            pre = max(pre+x,x);
            maxAns = max(maxAns,pre);
        }
        return maxAns;
    }
};