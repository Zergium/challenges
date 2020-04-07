class Solution {
public:
    int countElements(vector<int>& arr) {
        map <int, int> items;
        for (auto x: arr) {
            items[x]++;
        }
        int result = 0;
        int prev = 0;
        int prev_count = 0;
        for (auto item: items) {
            if (prev_count > 0) {
                if (prev + 1 == item.first) {
                    result += prev_count;
                }
            };
            prev = item.first;
            prev_count = item.second;
        }
        return result;
    }
};