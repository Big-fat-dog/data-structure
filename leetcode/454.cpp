#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int count = 0;
        int n = nums1.size();
        unordered_map<int, int> fs_sum;
        unordered_map<int, int> tf_sum;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int p = nums1[i] + nums2[j];
                int q = nums3[i] + nums4[j];
                fs_sum[p]++;
                tf_sum[q]++;
            }
        }
        for (auto& pair : fs_sum) {
            int key = pair.first; // 拿到键（int）,存两数之和
            int count1 = pair.second;
            int target = -key;
            auto iter = tf_sum.find(target);
            if (iter!= tf_sum.end()) {
                int count2 = iter->second;
                count += count1*count2;
            }
        }
        return count;
    }
};