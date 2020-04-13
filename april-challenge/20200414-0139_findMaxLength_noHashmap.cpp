static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

// You are here! Your runtime beats 100.00 % of cpp submissions
// 555 / 555 test cases passed.
// Status: Accepted
// Runtime: 36 ms
// Memory Usage: 20 MB

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
        
        const int NO_POS = -2;
        const int n = nums.size();
        
        vector ar_pos(n*2 + 2, NO_POS);
        int sum = 0;
        ar_pos[n + sum] = -1;
        for(int idx = 0; idx < n; idx++) {
            sum += (nums[idx] == 0 ? -1 : 1);
            
            int& pos(ar_pos[n+sum]);
            if (pos == NO_POS) {
                pos = idx;    
            } else {
                int len = idx - pos;
                if (best < len) best = len;
            }
        }
        
        return best;
    }
};