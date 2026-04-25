#include<iostream>
#include<vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum=0;
        int i =0; //滑动窗口的起始位置
        int sublength=0;//滑动窗口的长度
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                sublength=j-i+1;
                result = min(result,sublength);
                sum-=nums[i];
                i++;
            }
        }
        return result==INT32_MAX?0:result;
    }
};