#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=0;
        if(nums.empty()) return 0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=nums[slow]){
                slow++;
                nums[slow]=nums[fast];
            }
            
    }
    return slow+1;
    }
};