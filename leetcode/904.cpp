//滑动窗口，写麻烦了并且是错的，把自己绕进去了，队列其实完全没必要
#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int left=0;
        int maxlength=0;
        for(int right=0;right<fruits.size();right++){
            basket[fruits[right]]++;
            while(basket.size()>2){
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
    }
};