class Solution {
public:
    vector<int> origin;
    vector<int> current;
    Solution(vector<int>& nums)
    : origin(nums) {
        current = origin;
        
        std::srand(std::time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        current = origin;
        return current;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //cout << "shuffle" << endl;
        for (int n=current.size()-1; n>0; n--) {
            int o = rand() % (n+1);
            swap(current[n], current[o]);
            //cout << "swap " << n << " vs " << o << endl;
        }
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */