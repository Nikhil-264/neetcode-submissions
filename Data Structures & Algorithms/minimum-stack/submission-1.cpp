#include<bits/stdc++.h>

class MinStack {
    stack<int> value;
    stack<int> mini;
public:
    MinStack() {
    }
    
    void push(int val) {
        value.push(val);
        if(mini.empty()){
            mini.push(val);
        }
        else{
            mini.push(min(mini.top(), val));
        }
    }
    
    void pop() {
        value.pop();
        mini.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
