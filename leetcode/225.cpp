#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
stack<int> s1;
stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()==1)
        {while(s1.empty()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    
    int peek() {
        if(s2.empty()==1){
        while(s1.empty()!=1){
            s2.push(s1.top());
            s1.pop();
        }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty()&&s2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */