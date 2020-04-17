class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int next = 0;
        //int last = nums.size()-1;
        while (next < nums.size()) {
            if (nums[next] == 0) {
                next++;
            } else {
                nums[curr] = nums[next];
                curr++;
                next++;
            }
        }
        while (curr < nums.size()) {
            nums[curr] = 0;
            curr++;
        }
    }
};