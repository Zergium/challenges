class Solution {
public:
    /**  Bidirectional BFS  **/
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict (wordList.begin(), wordList.end()), head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) return 0;
        head.insert (beginWord);
        tail.insert (endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {  // to expand 'head' and 'tail' alternatively
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            
            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string cur = *it;
                for (int j = 0; j < cur.size(); ++j) {
                    char origin = cur[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == origin) continue;
                        cur[j] = c;
                        if (ptail->find(cur) != ptail->end()) return ladder;
                        if (dict.find(cur) != dict.end()) {
                            temp.insert(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[j] = origin;
                }
            }
            ladder++;
            phead->swap (temp);
        }
        
        return 0;
    }
};