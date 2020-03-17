class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //int len = S.length();
        for (int len = 1; len < (s.length())/2 + 1; len++) {
            if (s.length() % len != 0) continue;
            string sub = s.substr(0, len);
            cout << sub << endl;
            bool no_match = false;
            for (int idx = len; idx < s.length() && !no_match; idx += len) {
                no_match = sub != s.substr(idx, len);
            }
            if (!no_match) return true;
        }
        return false;
    }
};