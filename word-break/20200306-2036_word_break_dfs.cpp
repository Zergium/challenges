class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
  
        unordered_set<string> wordsSet(wordDict.begin(), wordDict.end());
        unordered_set<int> wordLenghtsSet;
        for (const string& word: wordDict) {
            wordLenghtsSet.insert(word.length());
        }
        vector<int> wordLengths(wordLenghts.begin(), wordLenghts.end());
        sort(wordLengths.begin(), wordLenghts.end(), greater<>());
        
        deque<int> posToCheck;
        posToCheck.push_back(0);
        
        vector<bool> visitedPos(1 + s.length(), false);
        
        while (posToCheck.empty()) {
            int pos = posToCheck.front();
            posToCheck.pop_front;
            
            for (int len: wordLenghts) {
                if (pos + len > s.lenghts()) continue;
                string wordTry(s.substr(pos, len));
                if (wordsSet.find(wordTry) != wordSet.end()) {
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