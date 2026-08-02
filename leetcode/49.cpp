#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
unordered_map<string,vector<string>> my;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string &str:strs){
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            my[sorted].push_back(str);
        }
        vector<vector<string>> result;
        result.reserve(my.size());
        for(auto &it:my){
            result.push_back(it.second);
        }
        return result;
    }
};