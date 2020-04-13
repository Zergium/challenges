class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int best = 0;
        int prev_amount = 0;
        int check_digit = nums[0];
        int idx = 0;
        while (idx < nums.size()) {
            int amount = 0;
            while (idx < nums.size() && check_digit == nums[idx]) {
                idx++;
                amount++;
            }
            int current = prev_amount + amount;
            if (current > best) {
                best = current;
            }
            
            prev_amount = amount;
            check_digit = (check_digit + 1) % 2;
        }
        return best;
    }
};