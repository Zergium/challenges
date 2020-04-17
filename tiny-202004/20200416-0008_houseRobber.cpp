

//// backtrace
class Solution {
public:
    
    /////////////// v1
    void checkNext(vector<int>& nums, int nextIdx, int prevAmount, int& best) {
        if (nextIdx >= nums.size()) {
            if (prevAmount > best) best = prevAmount;
        } else {
            checkNext(nums, nextIdx+2, prevAmount+nums[nextIdx], best);
            checkNext(nums, nextIdx+1, prevAmount, best);
        }
        
    }
    
    int v1_rob(vector<int>& nums) {
        int best(0);
        checkNext(nums, 0, 0, best);
        return best;  
    }

    ////////////// v2 bottom-up

    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        
        vector<int> vals(nums.size(), 0);
        for (int idx = 0; idx < nums.size(); idx++) {
            int res = 0;
            if (idx > 1) {
                res = max(res, vals[idx-2] + nums[idx]);
            };            
            if (idx > 0) {
                res = max(res, vals[idx-1]);
                if (idx == 1) {
                    res = max(res, nums[idx]);
                }
            } else {
                res = nums[idx];
            }
            vals[idx] = res;
        }
        
        return vals.back();
        
    }

////////////////// v3 dynamic

    int rob(vector<int>& nums) {
        int n(nums.size());
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int prev = nums[0];
        int curr = nums[1];
        for (int idx = 2; idx < n; idx++) {
            int val(nums[idx]);
            
            int next = max(prev + val, curr);
            prev = max(prev, curr);
            curr = next;
            
        }
        
        return curr;
        
    }



};