#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
private:
    int get_sum(int n){
        int sum=0;
        while(n!=0){
            int num = (n%10)*(n%10);
            sum+=num;
            n/=10;
        }
        return sum;
    };
public:
    bool isHappy(int n) {
        unordered_set<int> myset;
        while(n!=1){
            if(myset.count(n)){
                return false;
            }
            myset.insert(n);
            n=get_sum(n);
        }
        return true;
    }
};