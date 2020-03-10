class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> amounts;
        for (int candy: candies) {
            anounts[candy] += 1;
        }
        
        vector<pair<int,int>> sorted;
        for (auto candy_amount: amounts) {
            sorted.push_back(candy_amount);
        }
        sort(sorted, [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        int idx = 0;
        int amount_for_child = candies.size() /2;
        int counted = 0;
        while (idx < sorted.size() && sorted[idx].second + amount < amount_for_child) {
            amount += sorted[idx].second;
        };
        
        return idx;
            
    }
};