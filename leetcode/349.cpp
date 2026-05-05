#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> list;
        unordered_set<int> myset;
        for (int i = 0; i < nums1.size(); i++) {
            if(myset.count(nums1[i])==0){
                myset.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(myset.count(nums2[i])==1){
                list.push_back(nums2[i]);
                myset.erase(nums2[i]);
            }
        }
        return list;
    }
};