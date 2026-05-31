#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    //移除多余空格
    void removespace(string &s){
        int slow=0;
        int fast=0;
        while(fast<s.size()&&s[fast]==' '){
                fast++;
            }
        for(;fast<s.size();fast++){
            if(fast>0&&s[fast]==s[fast-1]&&s[fast]==' '){
                continue;
            }
            s[slow]=s[fast];
            slow++;
        }
        if(slow>0&&s[slow-1]==' ')slow--;
        s.resize(slow);
    }
    string reverseWords(string s) {
        removespace(s);
        reverse(s.begin(),s.end());
        int left=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                int right = i-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                left=i+1;
            }
        }
        int right=s.size()-1;
        while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
        return s;
    }
};