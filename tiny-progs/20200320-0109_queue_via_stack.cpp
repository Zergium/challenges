class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        vector<int> temp;
        while (!m_stack.empty()) {
            temp.push_back(*(m_stack.end()-1));
            m_stack.pop_back();
        }
        m_stack.push_back(x);
        while (!temp.empty()) {
            m_stack.push_back(*(temp.end()-1));
            temp.pop_back();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        m_stack.pop_back();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return *(m_stack.end()-1);
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_stack.empty();
    }
    
    vector<int> m_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */