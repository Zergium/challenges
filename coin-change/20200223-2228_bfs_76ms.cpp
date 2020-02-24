
/// 76ms, faster than 25%


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int result;
        
        std::vector<bool> reachedAmounts(amount+1, false);
        
        std::deque< std::pair<int, int> > qNodes;
        qNodes.push_back(std::make_pair(0,0));

        while (!qNodes.empty()) {
            std::pair<int,int> node = qNodes.front();
            qNodes.pop_front();
            
            for (int coin: coins) {
                int newAmount = node.second + coin;
                if (newAmount == amount) {
                    return node.first + 1;
                } else if (newAmount < amount) {
                    if (!reachedAmounts[newAmount]) {
                        reachedAmounts[newAmount] = true;
                        qNodes.push_back(std::make_pair(node.first+1, newAmount));
                    }
                }
            }
        }
        
        return -1; // we tried all possible ways to reach amount with available coins - no success
    }
};
