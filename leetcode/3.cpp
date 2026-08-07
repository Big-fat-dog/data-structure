#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),ans=0,left=0;
        unordered_map<char,int> cnt;
        for(int right=0;right<n;right++){
            char c=s[right];
            cnt[c]++;
            while(cnt[c]>1){
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};