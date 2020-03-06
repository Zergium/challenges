class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        for (const string& word: wordDict) {
            if (s.substr(0, word.length()) == word) {
                if (wordBreak(s.substr(word.length()))) 
                    return true;
            }
        }
        return false;
    }
};