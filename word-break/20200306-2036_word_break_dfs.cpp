// Runtime: 4 ms, faster than 93.61% of C++ online submissions for Word Break.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Word Break.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
  
        unordered_set<string> wordsSet(wordDict.begin(), wordDict.end());
        unordered_set<int> wordLengthsSet;
        for (const string& word: wordDict) {
            wordLengthsSet.insert(word.length());
        }
        vector<int> wordLengths(wordLengthsSet.begin(), wordLengthsSet.end());
        sort(wordLengths.begin(), wordLengths.end(), greater<>());
        
        deque<int> posToCheck;
        posToCheck.push_back(0);
        
        vector<bool> visitedPos(1 + s.length(), false);
        
        while (!posToCheck.empty()) {
            int pos = posToCheck.front();
            posToCheck.pop_front();
            
            for (int len: wordLengths) {
                if (pos + len > s.length()) continue;
                string wordTry(s.substr(pos, len));
                if (wordsSet.find(wordTry) != wordsSet.end()) {
                    int nextPos = pos + len;
                    if (nextPos == s.length()) {
                        return true;
                    }
                    if (!visitedPos[nextPos]) {
                        visitedPos[nextPos] = true;
                        posToCheck.push_back(nextPos);
                    } 
                }
            }
        }
        return false;
    }
};