#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> A;
        for(int i=0;i<nums.size()-1;i++){
            if(A.size()<2){
            for(int j=1;j<nums.size();j++){
                if(j!=i&&nums[j]+nums[i]==target){
                    A.push_back(i);
                    A.push_back(j);
                    break;
                }
            }
        }
       else
       break;
        }
        return A;
    }
};