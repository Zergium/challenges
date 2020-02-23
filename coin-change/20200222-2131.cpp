class Solution {
private:
    std::unordered_map<int,int> m_previous;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        auto itPreviousResult = m_previous.find(amount);
        if (itPreviousResult != m_previous.end()) {
            return itPreviousResult->second;
        }
        int result(-1);
        for (int coin: coins) {
            int interim(std::numeric_limits<int>::max());
            if (coin < amount) {
                interim = coinChange(coins, amount-coin);
                if (interim > 0) {
                    interim++;
                    if (result == -1 || result > interim) {
                        result = interim;
                    }
                }
            } else if (coin == amount) {
                result = 1;
            };
        }
        m_previous[amount] = result;
        return result;
    }
};

// coinChange( coins, amount ) = min( foreach coin in coins:  cointChange( coins - coin, amount - coin) )

// not too fast