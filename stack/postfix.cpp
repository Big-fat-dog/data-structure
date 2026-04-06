#include<iostream>
#include<string>
#include<stack>
using namespace std;
//判断是操作数类型
bool isOperand(char c){
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
//操作符优先级
int precedence(char a){
    if (a == '+' || a == '-') return 1;
    if (a == '*' || a == '/') return 2;
    return 0; // '(' '[' '{' 优先级最低
}
//判断是否为左括号
bool isLeftBracket(char a){
    if(a=='{'||a=='('||a=='[')
    return true;
    return false;
}
// ✅ 判断是否是右括号
bool isRightBracket(char c) {
    return c == ')' || c == ']' || c == '}';
}
string Postfix(const string &exp){
    stack<char> S;
    string res="";
    for(int i=0;i<exp.length();i++){
        if(exp[i]==' ')continue;
        if(isOperand(exp[i])){
            res +=exp[i];
        }
        else if(isLeftBracket(exp[i])){
            S.push(exp[i]);
        }
        else if(isRightBracket(exp[i])){
            while(!S.empty()&&!isLeftBracket(S.top())){
                char k =S.top();
                res +=k;
                S.pop();
            }
            if (!S.empty()) S.pop(); // 弹出左括号
        }
        else{
            // 重点：循环弹出所有优先级 >= 当前的运算符！
            while (!S.empty() && 
                   !isLeftBracket(S.top()) && 
                   precedence(S.top()) >= precedence(exp[i])) {
                res += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
    }
    // 清空栈！
    while (!S.empty()) {
        res += S.top();
        S.pop();
    }
    return res;
}

int main(){
    char exp[1000];
    cout<<"enter a opertion: ";
    cin.getline(exp,1000);
    string res = Postfix(exp);
    cout<<res;
    return 0;
}