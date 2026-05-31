#include<iostream>
using namespace std;
int main(){
    string a = "abcd12345";
    int left=0;
    int right = a.size()-1;
    while(left<right){
        swap(a[left],a[right]);
        left++;
        right--;
    }
    cout<<a;
}