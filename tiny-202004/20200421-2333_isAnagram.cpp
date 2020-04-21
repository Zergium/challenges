class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> stat_s(26,0);
        vector<int> stat_t(26,0);
        for (int c: s) stat_s[c-'a']++;
        for (int c: t) stat_t[c-'a']++;
        return stat_s == stat_t;
    }
};