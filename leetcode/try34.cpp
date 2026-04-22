#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
        int findleftborder(vector<int>& nums,int target){
            int left=0;
            int right=nums.size()-1;
            int leftborder=-2;
            while(left<=right){
                int middle=left+(right-left)/2;
                if(nums[middle]>=target){
                    right=middle-1;
                    leftborder=right;
                }
                else {
                    left=middle+1;
                }
            }
            return leftborder;
        }
        int findrightborder(vector<int>& nums,int target){
            int left=0;
            int right=nums.size()-1;
            int rightborder=-2;
            while(left<=right){
                int middle=left+(right-left)/2;
                if(nums[middle]<=target){
                    left=middle+1;
                    rightborder=left;
                }
                else {
                    right=middle-1;
                }
            }
            return rightborder;
        }
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int leftborder=findleftborder(nums,target);
            int rightborder=findrightborder(nums,target);
            if(leftborder!=-2&&rightborder!=-2){
                return {leftborder+1,rightborder-1};
            }
            else return {-1,-1};
        }
    };
int main(){
    Solution S;
    vector<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(7);
a.push_back(7);
a.push_back(7);
a.push_back(7);
a.push_back(8);
a.push_back(9);
    vector<int> ccb= S.searchRange(a,7);
    for(int i=0;i<ccb.size();i++){
        cout<<ccb[i];
    }
}