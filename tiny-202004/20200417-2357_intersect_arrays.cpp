class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> amounts1;
        unordered_map<int,int> amounts2;
        for (int v: nums1) {
            amounts1[v]++;
        }
        for (int v: nums2) {
            amounts2[v]++;
        }
        vector<int> result;
        for (auto p: amounts1) {
            int value = p.first;
            int amount = p.second;
            amount = min(amount, amounts2[value]);
            for (int i=0; i<amount; i++) {
                result.push_back(value);
            }
        }
        return result;
    }
};