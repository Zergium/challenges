class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> stat(26,0);
        for (char c: s) stat[c-'a']++;
        for (char c: t) stat[c-'a']--;
        for (int amount: stat) {
            if (amount != 0) return false;
        }
        return true;
    }
};