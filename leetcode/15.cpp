#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)return result;
            //对第一个数字去重
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            //获取双指针
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    result.push_back({nums[i], nums[left], nums[right]});
                    //对left去重
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
        return result;
    }
};