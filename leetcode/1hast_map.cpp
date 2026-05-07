#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //键存数值，值存下标
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++){
            int val = target-nums[i];
            auto iter=mymap.find(val);
            if(iter!=mymap.end()){
                return {i,iter->second};
            }
            mymap.insert({nums[i],i});
        }
    return {};
    }
};