#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int temp=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=0){
                nums[slow]=nums[fast];
                slow++;
            }
            else temp++;
        }
        for(int i=0;i<temp;i++){
            nums[nums.size()-1-i]=0;
        }
    }
};