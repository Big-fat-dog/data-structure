#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n); // 准备一个新数组
        int left = 0, right = n - 1;
        int pos = n - 1; // 从结果数组的最后一位开始填（填最大的）

        while (left <= right) {
            // 比较两端的平方
            if (nums[left] * nums[left] > nums[right] * nums[right]) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }
        return result;
    }
};