class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> items;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int x) {
        items.push(x);
        int m = x;
        if (!mins.empty()) {
            if (mins.top() < m) m = mins.top();
        }
        mins.push(m);
    }
    
    void pop() {
        items.pop();
        mins.pop();
    }
    
    int top() {
        return items.top();
    }
    
    int getMin() {
        return mins.top();        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */