class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int acc = 1;
        for (int i = 0; i<n; i++) {
            result[i] = acc;
            acc *= nums[i];
        }
        acc = 1;
        for (int i = n-1; i >= 0; i--) {
            result[i] *= acc;
            acc *= nums[i];
        }
       return result;
    }
};