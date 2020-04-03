// Runtime: 708 ms, faster than 12.63% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Subarray Sum Equals K.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> sum(n);
        sum[0] = nums[0];
        
        for (int idx=1; idx < n; idx++) sum[idx] = sum[idx-1] + nums[idx];
        
        // cout << "sum: ";
        // for (auto x: sum) cout << x << ", ";
        // cout << ";" << endl;
        
        // [1,1,1,1,1]
        // [1,2,3,4,5]
        // k = 4
        // [1]
        // e - s + ns = k
        // e = k + s - ns;
        
        int result(0);
        for (int idx = 0; idx < n; idx++) {
            int rest = k + sum[idx] - nums[idx];
            
            //cout << "idx " << idx << "; rest " << rest << endl;
            for (int j = idx; j<n; j++) {
                if (sum[j] == rest) {
                    result++;
                }
            }
        }
        return result;
    }
};