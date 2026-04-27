#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        vector<int> result;
        if(array.empty()||array[0].empty())return {};
        int top=0;
        int right=array[0].size()-1;
        int left=0;
        int bottom=array.size()-1;
        while(1){
            for(int i=left;i<=right;i++){
                result.push_back(array[top][i]);
            }
            top++;
            if(top>bottom)break;
            
            for(int i=top;i<=bottom;i++){
                result.push_back(array[i][right]);
            }
            right--;
            if(left>right)break;
            
            for(int i=right;i>=left;i--){
                result.push_back(array[bottom][i]);
            }
            bottom--;
            if(top>bottom)break;
            
            for(int i=bottom;i>=top;i--){
                result.push_back(array[i][left]);
            }
            left++;
            if(left>right)break;
        }
        return result;
    }
};