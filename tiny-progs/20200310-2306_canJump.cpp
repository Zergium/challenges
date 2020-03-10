///////////// v1, bfs - SLOW

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        deque<int> queue;
        queue.push_back(0);
        while (!queue.empty()) {
            int idx = queue.front();
            queue.pop_front();
            
            int max_jump = nums[idx];
            if (idx + max_jump >= nums.size()) return true;
            for (int i=max_jump; i>0; i--) {
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



///////////// v2, dfs - SLOW

class Solution {
public:
    bool canJump(vector<int>& nums) {
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

//////////////// v3, wave

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        int max_reacheable = 0;
        while (idx <= max_reacheable && idx < nums.size()-1) {
            int next = idx + nums[idx];
            //cout << "idx " << idx << ", nums[idx] " << nums[idx] << ", next " << next << ", max_reacheable " << max_reacheable <<endl;
            if (next > max_reacheable)
                max_reacheable = next;
            idx++;
        }
        //cout << "fin, idx " << idx << ", max_reacheable " << max_reacheable << endl;
        return max_reacheable >= (nums.size()-1);
    }
};