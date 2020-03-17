class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx = 0;
        unordered_set<int> items;
        for (auto item: nums) {
            items.insert(item);
        }
        
        vector<int> result;
        for (int i=1; i<=nums.size(); i++) {
            if (items.end() == items.find(i)) result.push_back(i);
        }
        
        return result;
        
    }
};