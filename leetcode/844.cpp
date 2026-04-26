#include<iostream>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slow1=0;
        int slow2=0;
   
        for(int fast=0;fast<s.size();fast++){
            if(s[fast]!='#'){
                s[slow1]=s[fast];
                slow1++;
            }
            else{
                if(slow1>0)
                slow1--;
            }
          
        }
        s=s.substr(0,slow1);
        for(int fast=0;fast<t.size();fast++){
            if(t[fast]!='#'){
                t[slow2]=t[fast];
                slow2++;
            }
            else{
                if(slow2>0)
                slow2--;
            }
        }
        t=t.substr(0,slow2);
        return s==t;
       
    }
};