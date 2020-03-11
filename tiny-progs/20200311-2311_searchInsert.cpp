class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mi = (hi + lo) / 2;
            int miVal = nums[mi];
            if (miVal < target) {
                lo = mi+1;
            } else if (miVal == target) {
                return mi;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
};