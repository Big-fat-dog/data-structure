#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++){
            //剪枝
            if(nums[k]>target&&nums[k]>=0){
                break;
            }
            //一层去重
            if(k>0&&nums[k]==nums[k-1]){
                continue;
            }
            for(int i=k+1;i<nums.size();i++){
                //二次剪纸
                if(nums[k]+nums[i]>target&&nums[i]>=0){
                    break;
                }
                //二次去重
                if(i>k+1&&nums[i-1]==nums[i]){
                    continue;
                }
                int left = i+1;
                int right = nums.size()-1;
                while(left<right){
                    long long sum = (long long)nums[i] + nums[k] + nums[left] + nums[right];
                    if(sum>target){
                        right--;
                    }else if(sum<target){
                        left++;
                    }
                    else
                    {
                    result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        //去重
                    while(left<right&&nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                    }
                    
                }
            }
        }
        return result;
    }
};