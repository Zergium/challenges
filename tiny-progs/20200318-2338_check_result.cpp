class Solution {
public:
    
    void checkResult(vector<int>& candidates, int target, vector<int>& options, vector<vector<int>>& result) {
        for (int cnd: candidates) {
            if (target == cnd) {
                options.push_back(cnd);
                vector<int> found(options);
                sort(found.begin(), found.end());
                if (result.end() == find(result.begin(), result.end(), found)) {
                    result.push_back(found);
                }
                options.pop_back();
            } else if (target > cnd) {
                options.push_back(cnd);
                checkResult(candidates, target-cnd, options, result);
                options.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector< vector<int>> result;
        vector<int> selected;
        checkResult(candidates, target, selected, result);
        
        return result;
        
    }
};