class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        int sum = nums[0];
        int best_sum = sum;
        for (int idx = 1; idx < nums.size(); idx++) {
            int num = nums[idx];
            if (sum > 0) {
                sum += num;
            } else {
                sum = num;
            }
            if (best_sum < sum) best_sum = sum;
            if (sum < 0) sum = 0;
        }
        return best_sum;
    }
};