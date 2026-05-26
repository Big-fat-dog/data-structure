#include<iostream>
#include<vector>

using namespace std;
class Solution {
private: 
void getnext(int *next,const string &s){
    int j=0;
    next[0]=j;
    for(int i=1;i<s.size();i++){
        while(j>0&&s[i]!=s[j]){
            j=next[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        next[i]=j;    
    }
}
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        getnext(&next[0],s);
        int n=next.size();
        
        if(next[n-1]!=0&&n%(n-next[n-1])==0)return true;
        else
        return false;
    }
    
};