class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_pos = 0;
        for (int idx = 0; idx < nums.size() && idx <= last_pos; idx++) {
            int new_last_pos = idx + nums[idx];
            if (new_last_pos >= nums.size()) return true;
            if (last_pos < new_last_pos) last_pos = new_last_pos;
        }
        return (last_pos >= nums.size()-1);
    }
    bool canJumpX(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        deque<int> queue;
        queue.push_back(0);
        while (!queue.empty()) {
            int idx = queue.back();
            queue.pop_back();
            
            int max_jump = nums[idx];
            if (idx + max_jump >= nums.size()-1) return true;
            //for (int i=max_jump; i>0; i--) {
            for (int i=1; i<=max_jump; i++) {
                int trg = i + idx;
                if (!visited[trg]) {
                    visited[trg] = true;
                    queue.push_back(trg);
                }
            }
        }
        return false;
    }
};