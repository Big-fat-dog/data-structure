#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        priority_queue<int> pq; 
        int len = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1){
                len++;
            }
            else if(nums[i]==nums[i+1]){
                continue;
            }
            else{
                pq.push(len);
                len=1;
            }
        }
        pq.push(len);
        return pq.top();
    }
};