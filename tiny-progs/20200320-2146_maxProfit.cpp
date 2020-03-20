class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size() < 1) { return 0; }
        int lo = prices[0];
        for (int idx=1; idx<prices.size(); ++idx) {
            int current = prices[idx];
            if (current > lo) {
                result = max(result, current - lo);
            } else {
                lo = current;
            }
        }
        return result;
    }
};