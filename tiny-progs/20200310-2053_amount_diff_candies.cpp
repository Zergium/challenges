class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> amounts;
        for (int candy: candies) {
            amounts[candy] += 1;
        }
        
        vector<pair<int,int>> sorted;
        for (auto candy_amount: amounts) {
            sorted.push_back(candy_amount);
        }
        sort(begin(sorted), end(sorted), [](const pair<int,int>& a, const pair<int,int>& b) -> bool {
            return a.second < b.second;
        });

        int idx = 0;
        int amount_for_child = candies.size() /2;
        int counted = 0;
        while (idx < sorted.size() && sorted[idx].second + counted < amount_for_child) {
            counted += sorted[idx].second;
        };
        
        return idx;
            
    }
};