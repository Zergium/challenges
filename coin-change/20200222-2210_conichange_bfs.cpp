/// for https://leetcode.com/problems/coin-change/
/// 270ms + 66MB
/// faster than ~10% of CPP submits

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        int result;
        
        std::unordered_set<int> setVisitedNodes;
        std::vector<int> vecNodes;
        
        setVisitedNodes.insert(0); // no need for, just for consistency, amount 0 is reached
        vecNodes.push_back(0); // we start with node 0 (amount = 0)
        int coinsOfIteration = 0;
        while (!vecNodes.empty()) {
            
            coinsOfIteration++;

            std::vector<int> vecNextNodes;            
            for (int node: vecNodes) {
                for (int coin: coins) {
                    int amountWithCoin = node + coin;
                    if (amountWithCoin == amount) {
                        return coinsOfIteration;
                    }
                    if (amountWithCoin < amount) { // if with current coin we not yet above target amount
                        if (setVisitedNodes.end() == setVisitedNodes.find(amountWithCoin)) { // if we didn't come to this amount (node)
                            setVisitedNodes.insert(amountWithCoin);
                            vecNextNodes.push_back(amountWithCoin);
                        }
                    }
                }
            }
            
            vecNodes.swap(vecNextNodes);
            
        }
        
        return -1; // tried all possible ways to reach amount with available coins - no success
    }
};

// coinChange( coins, amount ) = min( foreach coin in coins:  cointChange( coins - coin, amount - coin) )