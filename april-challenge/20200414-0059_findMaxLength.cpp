class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
       
        // 0 1   = 2
        // 0 0 0 1 = 2

        // 1111111110101011111111111111110101010101001010010101001
        // 12345678989898
        // 00000000000000
        // 00000000011223
        
        int best = 0;
        
        unordered_map<int, int> map_sums_to_idx;
        int sum = 0;
        map_sums_to_idx[sum] = -1;
        for(int idx = 0; idx < nums.size(); idx++) {
            sum += (nums[idx] == 0 ? -1 : 1);
            auto it_sum = map_sums_to_idx.find(sum);
            if (it_sum == map_sums_to_idx.end()) {
                map_sums_to_idx[sum] = idx;    
            } else {
                int prev_idx = it_sum->second;
                int len = idx - prev_idx;
                if (best < len) best = len;
            }
        }
        
        return best;
    }
};