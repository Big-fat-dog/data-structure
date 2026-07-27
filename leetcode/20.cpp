#include<iostream>

#include<stack>
using namespace std;
class Solution {
stack<char> mystack;
public:
    bool isValid(string s) {
        for(int i=0;i<s.size();i++){
            if(mystack.size()>0){
                char a = mystack.top();
                if(a=='{'&&s[i]=='}'){
                    mystack.pop();
                    continue;
                }
                else if(a=='('&&s[i]==')'){
                    mystack.pop();
                    continue;

                }
                else if(a=='['&&s[i]==']'){
                    mystack.pop();
                    continue;

                }
            }
            mystack.push(s[i]);
        }
        if(mystack.size()==0)return true;
        return false;
    }
};