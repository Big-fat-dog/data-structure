#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool Check(const char* exp){
    stack<char> S;
    int n=strlen(exp);
    for(int i=0;i<n;i++){
        char c=exp[i];
        if(c=='{'||c=='('||c=='['){
            S.push(c);
        }
        else if(c=='}'||c==']'||c==')'){
            if(S.empty()) return false;//先检查一下是否直接就是右括号！
            char d=S.top();
            if(
                (c==')'&&d=='(')||
                (c=='}'&&d=='{')||
                (c==']'&&d=='[')
            ){
                S.pop();
            }
        else{
            //类型不匹配
            return false;
        }
        }
    }
    return S.empty();
}
int main(){
    char exp[1000];
    cout<<"please input text： ";
    cin.getline(exp,1000);
    if(Check(exp)){
        cout<<"success!";
    }
    else{
        cout<<"defeat!";
    }
    return 0;
}