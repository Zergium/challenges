class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0];});
        vector<vector<int>> result;
        vector<int> current;
        for (vector<int>& v: intervals) {
            if (current.empty()) {
                current = v;
            } else {
                if (current[1] >= v[0]) {
                    // merge
                    current[1] = max(current[1], v[1]);
                } else {
                    // no merge
                    result.push_back(current);
                    current = v;
                }
            }
        }
        if (!current.empty()) {
            result.push_back(current);
        }
        return result;
    }
};