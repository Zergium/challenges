class Solution {
private:
    unordered_map<int,vector<int>> indexes;
public:
    Solution(vector<int>& nums) {
        srand(time(nullptr));
        for (int idx = 0; idx < nums.size(); idx++) {
            indexes[nums[idx]].push_back(idx);
        }
    }
    
    int pick(int target) {
        auto it = indexes.find(target);
        if (it != indexes.end()) {
            vector<int>& vec(it->second);
            int result = vec[rand() % vec.size()];
            return result;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */