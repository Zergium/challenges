class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> oldNums(nums);
        int trg = k % n;
        for (int idx = 0; idx < nums.size(); idx++) {
            nums[(idx + trg) % n] = oldNums[idx];
        }
    }
};


-----------------

