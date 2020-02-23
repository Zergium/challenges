/// for https://leetcode.com/problems/coin-change/
/// 32 ms + 12MB 
/// faster than 95% of CPP submits


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX_VAL = amount + 1;
        std::vector vecAmounts(amount + 1, MAX_VAL);
        vecAmounts[0] = 0;
        for (int idx = 1; idx <= amount; ++idx) {
            int currChange = vecAmounts[idx];
            for (const int coin: coins) {
                int preIdx = idx - coin;
                if (preIdx >= 0) {
                    int prevChange = vecAmounts[preIdx];
                    if (prevChange < MAX_VAL) {
                        prevChange++;
                        if (prevChange < currChange) {
                            currChange = prevChange;
                        }
                    }
                }
            }
            vecAmounts[idx] = currChange;
        }
        int result = vecAmounts[amount];
        if (result == MAX_VAL) {
            result = -1;
        }
        return result;
    }
};