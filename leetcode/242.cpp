#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mydict1;
        unordered_map<char,int> mydict2;
        for(const char &ch :s){
            mydict1[ch]++;
        }
        for(const char &ch :t){
            mydict2[ch]++;
        }
        if(mydict1.size()!=mydict2.size())return false;
        for(auto &p:mydict1){
            auto it = mydict2.find(p.first);
            if(it==mydict2.end()||it->second!=p.second){
                return false;
            }
        }
        return true;
    }
};