class NumArray {
public:
    vector<int> m_nums;
    
    NumArray(vector<int>& nums) : m_nums(nums) {
        
    }
    
    void update(int i, int val) {
        m_nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int result=0;
        for (int idx = i; idx<=j; ++idx) {
            result += m_nums[idx];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */