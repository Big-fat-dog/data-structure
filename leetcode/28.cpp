#include<iostream>
#include<vector>

using namespace std;
class Solution {
private:
//利用减一实现存长度变存索引
    void getNext(int *next,const string &s){
        //j是模式串前缀起始位置
        int j=-1;
        next[0]=j;//初始化next数组第一个，包为-1的！
        //-1代表没有匹配的前后缀长度
        for(int i=1;i<s.size();i++){
            //i是后缀的初始位置，用于控制循环
            while(j>=0&&s[i]!=s[j+1]){
                j=next[j];
            }
            if(s[i]==s[j+1]){
                j++;
            }
            next[i]=j;
        }
    }
public:

    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0],needle);
        int j=-1;
        for(int i=0;i<haystack.size();i++){
            while(j>=0&&haystack[i]!=needle[j+1]){
                j=next[j];
            }
            if(haystack[i]==needle[j+1]){
                j++;
            }
            if(j==(needle.size() - 1)){
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};