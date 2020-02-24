class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        std::vector<int> coinsForAmounts(amount+1, amount+1);
        
        using node_t = std::pair<int, int>;
        using container_t = std::vector<node_t>;
        
        auto comparer =
        [](const node_t& e1, const node_t& e2) 
        { return e1.first > e2.first; };
        
        std::priority_queue< node_t, container_t, decltype(comparer) > qNodes(comparer);
        qNodes.push(std::make_pair(0,0));

        while (!qNodes.empty()) {
            std::pair<int,int> node = qNodes.top();
            qNodes.pop();
            
            for (int coin: coins) {
                long long newAmount = (long long)node.second + coin;
                int newChange = node.first + 1;
                if (newAmount <= amount) {
                    if (coinsForAmounts[newAmount] > newChange) {
                        coinsForAmounts[newAmount] = newChange;
                        qNodes.push(std::make_pair(newChange, newAmount));
                    }
                }
            }
        }
        int result(coinsForAmounts[amount]);
        if (result > amount) result = -1;
        return result;
    }
};
