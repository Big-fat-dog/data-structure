#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
    private:
        bool isequal(
            unordered_map<char,int> &target,
            unordered_map<char,int> &sample
        ){
            for(const auto&p: target){
                char key = p.first;
                int val1 = p.second;
                if(sample.find(key)==sample.end()||sample[key]<val1){
                    return false;
                }
            }
            return true;
        };
public:
    string minWindow(string s, string t) {
        int left = 0;
        string minstring = "";
        int start=0;
        int length=INT_MAX;
        unordered_map<char, int> target;
        unordered_map<char, int> sample;
        for (int i = 0; i < t.size(); i++) {
            target[t[i]]++;
        }
        for (int right = 0; right < s.size(); right++) {
            if (target.find(s[right]) != target.end()) {
                sample[s[right]]++;
            }
            while (isequal(target,sample)) {
                if (target.find(s[left]) != target.end()) {
                    sample[s[left]]--;
                }
                if((right-left+1)<length){
                    length=right-left+1;
                    start=left;
                }
                left++;
            }
        }
        minstring= length==INT_MAX ? "" : s.substr(start, length);
        return minstring;
    }
};