class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //unordered_map< pair<int,int>, bool> checked;
        
        unordered_map<int, vector<int>> sum_to_pos;
        

        int count_arrays = 0;
        //vector<int> sums(nums.size()+1, 0);
        int sum = 0;
        sum_to_pos[0].push_back(0);
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            sum_to_pos[sum].push_back(i+1);
            
            int prev_sum = sum - k;
            auto it = sum_to_pos.find(prev_sum);
            if (it != sum_to_pos.end()) {
                vector<int>& pos(it->second);
                int idx = 0;
                while (idx < pos.size() && pos[idx] <= i) {
                    count_arrays++;
                    idx++;
                }
            }
            
        }
        
        //  [1,1,1,1]
        // [0,1,2,3,4]
        
        return count_arrays;
    }
};