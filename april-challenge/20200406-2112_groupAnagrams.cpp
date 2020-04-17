class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_sort_to_vec;
        for(const auto& str: strs) {
            string key(str);
            sort(key.begin(), key.end());
            map_sort_to_vec[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& p: map_sort_to_vec) {
            result.push_back(p.second);
        }
        return result;
    }
};