#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int rest = s.size();
        int current= 0;
        while(rest>0){
            int left=current;
            if(rest<k){
                int right = s.size()-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
            }
            else if(k<=rest&&rest<2*k){
                int right=left+k-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
            }
            else if(rest==2*k){
                int right = left+k-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
            }
            else if(rest>2*k){
                int right= left+k-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                current+=2*k;
            }
            rest-=2*k;
        }
        return s;
    }
};