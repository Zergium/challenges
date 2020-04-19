class Solution {
public:
    
    int findIndex(const vector<int>& nums, int target, int lo, int hi) {
        
        if (lo > hi) return -1;
        if (lo == hi) {
            if (nums[lo] == target) {
                return lo;
            } else {
                return -1;
            }
        }
        int mid = (lo + hi) / 2;
        int mid_val = nums[mid];
        if (mid_val == target) return mid;
        if (nums[lo] < nums[hi]) {
            // sorted region
            if (mid_val < target) {
                return findIndex(nums, target, mid+1, hi);
            } else {
                return findIndex(nums, target, lo, mid-1);
            }
        } else {
            // not sorted region -> take max of both
            return max(
                findIndex(nums, target, mid+1, hi),
                findIndex(nums, target, lo, mid-1)
            );
        }
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }
        return findIndex(nums, target, 0, nums.size()-1);
    }
};



/////////////////////// improved (2 times better in worst case)

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return -1;
        }
        int lo = 0;
        int hi = nums.size()-1;
        while (lo <= hi) {
            int mi = (hi + lo) / 2;
            int mi_val = nums[mi];
            if (mi_val == target) return mi;
            if (mi_val < target) {
                if (nums[lo] > mi_val && target > nums[hi]) {
                    hi = mi-1;
                } else {
                    lo = mi+1;
                }
            } else {
                // mi_val > target
                if (nums[hi] < mi_val && target < nums[lo]) {
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }
        }
        return -1;
    }
};