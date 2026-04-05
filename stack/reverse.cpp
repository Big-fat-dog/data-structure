#include<iostream>
#include<stack>
#include <cstring>
using namespace std;
void Reverse(char *C,int n){
    stack<char> S;
    //loop for push
    for(int i=0;i<n;i++){
        S.push(C[i]);
    }
    //loop for pop
    for(int i=0;i<n;i++){
        C[i]=S.top();//从栈里写入到字符串
        S.pop();//利用pop函数清除栈顶元素
    }

}
int main(){
    char C[51];
    cout<<"Enter a string";
    cin>>C;
    Reverse(C,strlen(C));
    cout<<"OUTOUT= "<<C;
}