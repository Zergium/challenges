class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int idx = 0; idx < nums.size(); ++idx) {
            int left = (idx == 0) || (nums[idx-1] < nums[idx]);
            int right = (idx == nums.size()-1) || (nums[idx] > nums[idx+1]);
            if (left && right) return idx;
        }
        return -1;            
    }
};