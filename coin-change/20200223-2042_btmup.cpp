/// for https://leetcode.com/problems/coin-change/
/// 48 ms + 12MB 
/// faster than 80% of CPP submits

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX_VAL = amount + 1;
        std::vector vecAmounts(amount + 1, MAX_VAL);
        vecAmounts[0] = 0;
        for (int idx = 1; idx <= amount; ++idx) {
            for (const int coin: coins) {
                int preIdx = idx - coin;
                if (preIdx >= 0) {
                    vecAmounts[idx] = std::min(vecAmounts[preIdx] + 1, vecAmounts[idx]);
                }
            }
        }
        int result = vecAmounts[amount];
        if (result == MAX_VAL) {
            result = -1;
        }
        return result;
    }
};