#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
stack<char> a;
public:
    string removeDuplicates(string s) {
        for(int i=0;i<s.size();i++){
            if(a.size()>0){
                char b = a.top();
                if(s[i]==b){
                    a.pop();
                    continue;
                }
            }
            a.push(s[i]);
        }
        string result = "";
        while (!a.empty()) { // 将栈中元素放到result字符串汇总
            result += a.top();
            a.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};