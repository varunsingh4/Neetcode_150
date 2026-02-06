class MinStack {
public:
    stack<int>s1;
    stack<int>min1;
  
    
    void push(int val) {
        if(min1.empty() || val <=min1.top())
        {
            min1.push(val);
        }
        s1.push(val);

        
    }
    
    void pop() {
        if(s1.top() == min1.top())
        {
            min1.pop();
        }
        s1.pop();
        
    }
    
    int top() {
        return s1.top();

        
    }
    
    int getMin() {
        return min1.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
