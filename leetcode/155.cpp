#include<iostream>
#include<stack>
using namespace std;
class MinStack {
private:
    stack<int> result;
    stack<int> mins;
public:
    MinStack() {

    }
    
    void push(int value) {
        result.push(value);
        if(mins.empty()){
           mins.push(value);
        }else{
            mins.push(min(mins.top(),value));
        }
    }
    
    void pop() {
        result.pop();
        mins.pop();
    }
    
    int top() {
        return result.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */