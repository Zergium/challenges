class Solution {
public:
    int firstUniqChar(const string& s) {
        vector<int> char_pos(26,-1);
        for (int idx = 0; idx < s.size(); idx++) {
            char ch = s[idx]-'a';
            int& val(char_pos[ch]);
            if (val == -1) { val = idx; }
            else { val = -2; }
        }
        
        int min_unique = -1;
        for (int idx: char_pos) {
            if (idx >= 0) {
                if (min_unique == -1 || min_unique > idx) {
                    min_unique = idx;
                }
            }
        }
        
        return min_unique;
    }
};