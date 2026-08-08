#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        
        unordered_map<char, int> need;  // p 中需要的字符计数
        unordered_map<char, int> window; // 窗口中字符计数

        for (char c : p) {
            need[c]++;
        }
        
        int left = 0, right = 0;
        int valid = 0;  // 记录窗口中满足 need 条件的字符种类数

        while(right<s.size()){
            char c = s[right];
            right++;

            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    valid++;
                }
            }
            //更新窗口
            while(right-left>=p.size()){
                //是否找到亦为此
                if(valid==need.size()){
                    result.push_back(left);
                }
                char d = s[left];
                left++;

                if(need.count(d)){
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                }
            }
        return result;
    }
};