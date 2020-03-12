class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rest_to_idx;  // needed rest to a number at idx <rest,idx>
        for (int i=0; i<nums.size(); ++i) {
            int num = nums[i];
            auto it = rest_to_idx.find(num);
            if (it != rest_to_idx.end()) {
                return {it->second, i};
            }
            rest_to_idx[target-num] = i;
        }
        return {0,0};        
    }
};