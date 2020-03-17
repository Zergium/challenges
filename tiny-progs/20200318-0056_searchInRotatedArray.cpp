class Solution {
public:
    
    int searchHelper(vector<int>& num, int target, int lo, int hi) {
        if (lo > hi) return -1;
        int mid = (hi + lo) / 2;
        int mid_val = num[mid];
        if (mid_val == target) return mid;
        if (hi == lo) return -1;

        int result(-1);
        int lo_val = num[lo];
        int hi_val = num[hi];
        if (lo_val < hi_val) {
            if (mid_val < target) {
                result = searchHelper(num, target, mid+1, hi);
            } else {
                result = searchHelper(num, target, lo, mid-1);
            }
        } else {
            result = searchHelper(num, target, mid+1, hi);
            if (result < 0)
                result = searchHelper(num, target, lo, mid-1);
        }
        return result;
    }
    
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size()-1);
    }
};