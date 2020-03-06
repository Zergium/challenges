class Solution {
public:
    
    bool binAdvanced(const vector<int>& nums, int target, int lo, int hi) {
        if (lo > hi) return false;
        if (lo == hi) {
            return nums[lo] == target;
        }
        int valLo = nums[lo];
        int valHi = nums[hi];
        int mid = (hi + lo) / 2;
        int valMid = nums[mid];
        if (valMid == target) {
                return true;
            };
\        if (valLo < valHi) {
            if (valMid < target) {
                return binAdvanced(nums, target, mid+1, hi);
            } else {
                return binAdvanced(nums, target, lo, mid-1);
            }
        } else {
            return binAdvanced(nums, target, mid+1, hi)
                || binAdvanced(nums, target, lo, mid-1);
        }
    }
    
    bool search(vector<int>& nums, int target) {
        return binAdvanced(nums, target, 0, nums.size()-1);
    }
};