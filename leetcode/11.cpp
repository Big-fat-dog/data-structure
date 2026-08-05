#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size()-1;
        int left=0;
        int maxa = 0;
        while(left<right){
            maxa = max(maxa,(right-left)*min(height[left],height[right]));
            if(height[left]>=height[right]){
                right--;
            }
            else left++;
        }
        return maxa;
    }
};