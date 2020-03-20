class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> m_que;
    int m_k;
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (int val: nums) {
            m_que.push(val);
        }
        while (m_que.size() > k) m_que.pop();
    }
    
    int add(int val) {
        m_que.push(val);
        while (m_que.size() > m_k) m_que.pop();
        return m_que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */