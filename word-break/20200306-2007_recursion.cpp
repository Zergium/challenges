// works, but time limit exceeded :(
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
//["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

class Solution {
    unordered_set<string> m_failedString;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (m_failedString.find(s) != m_failedString.end()) 
            return false;
        for (const string& word: wordDict) {
            if (s.substr(0, word.length()) == word) {
                if (wordBreak(s.substr(word.length()), wordDict))
                    return true;
            }
        }
        m_failedString.insert(s);
        return false;
    }
};