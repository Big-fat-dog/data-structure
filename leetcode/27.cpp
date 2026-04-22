#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> A;
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                A.push_back(nums[i]);
            }
        }
        nums=A;
        return nums.size();
    }
};