class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 1,2,3,4,5,6,7
        //
        if (prices.size() < 1) return 0;
        int profit = 0;
        int price = prices[0];
        for (int idx=1; idx < prices.size(); idx++) {
            if (prices[idx] > price) {
                profit += prices[idx] - price;
            }
            price = prices[idx];           
        }
        return profit;
    }
};