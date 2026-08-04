#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        循环不变量：在循环过程中，nums 的数据分布始终如下图
        [ 非零元素 | 零元素 | 尚未遍历 ]
          ^         ^       ^
          0         start0  i
        */
        int start0 = 0;
        for (int& x : nums) { // 注意 x 是引用
            if (x) {
                swap(x, nums[start0]);
                start0++;
            }
        }
    }
};
