class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> onleft(n);
        vector<int> onright(n);
        onleft[0] = nums[0];
        onright[n-1] = nums[n-1];
        for (int i=1; i<n; i++) {
            onleft[i] = onleft[i-1] * nums[i];
            onright[n-1-i] = onright[n-1-i+1] * nums[n-1-i];
        }
        vector<int> result(n);
        result[0] = onright[1];
        result[n-1] = onleft[n-1-1];
        for (int i=1; i<n-1; i++) {
            result[i] = onleft[i-1] * onright[i+1];
        }
        return result;
    }
};