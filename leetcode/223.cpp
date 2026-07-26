#include<iostream>
#include<queue>

using namespace std;
class MyStack {
queue<int> q1;
queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()!=1){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            return temp;
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            return temp;
        }
    }
    
    int top() {
        if(q1.empty()==1)return q2.back();
        else return q1.back();
    }
    
    bool empty() {
        if(q1.empty()&&q2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */