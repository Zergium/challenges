class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int trg = 0;
        while (idx < nums.size()) {
            if (nums[idx] == val) {
                idx++;
            } else {
                if (idx != trg) {
                    nums[trg] = nums[idx];
                }
                trg++;
                idx++;
            }
        }
        return trg;
    }
};