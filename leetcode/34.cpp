#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int getrightborder(int left, int right, int target,vector<int>& nums) {
        int rightborder = -2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] <= target) {
                left = middle + 1;
                rightborder = left;
            }
        }
        return rightborder;
    }

    int getleftborder(int left,int  right,int target,vector<int> &nums) {
        int leftborder = -2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
                leftborder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftborder;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        vector<int> A;
        int right = nums.size() - 1;
        int rightBorder = getrightborder(left, right, target,nums);
        int leftBorder = getleftborder(left, right, target,nums);
        // 情况一：target处在左或者右边界外。
        if (leftBorder == -2 || rightBorder == -2)
            return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1)
            return {leftBorder + 1, rightBorder - 1};
        // 情况二
        return {-1, -1};
    }
};