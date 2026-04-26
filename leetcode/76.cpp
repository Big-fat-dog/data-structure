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
            auto temp = sample.find(key);
            if(temp!=target.end()){
                auto val2=sample.at(key);
                if(val2<val1){
                    return false;
                }
            }else return false;
        }
        return true;
    };
public:
    string minWindow(string s, string t) {
        int left=0;
        string minstring="";
        unordered_map<char,int> target;
        unordered_map<char,int> sample;
        for(int i=0;i<t.size();i++){
            target[t[i]]++;
        }
        for(int right=0;right<s.size();right++){
            auto temp = target.find(s[right]);
            if(temp==target.end()){
                continue;
            }
            else{
                sample[s[right]]++;
            }
            while(isequal(target,sample)){
                auto temp = target.find(s[left]);
                if(temp!=target.end()){
                    sample[s[left]]--;
                }
                minstring=s.substr(left,right-left+1);
                left++;
            }
        }
        return minstring;
    }
};
int main(){
    string s="cabwefgewcwaefgcf";
    string t="cae";
    Solution my;
    my.minWindow(s,t);
};