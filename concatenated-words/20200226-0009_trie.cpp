// Runtime: 948 ms, faster than 5.08% of C++ online submissions
// Memory Usage: 414.9 MB, less than 16.67% of C++ online submissions

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        const int MAX_CHAR = 128; // valid chars are 1..127, element 0 will be never used
        
        class Trie {
        public:
            Trie()
            : m_next(MAX_CHAR, nullptr)
            , m_isLeaf(false) {
                
            }
            ~Trie() {
                for (Trie*& ptr: m_next) {
                    if (nullptr != ptr) {
                        delete ptr;
                    }
                    ptr = nullptr;
                }
            }
            vector<Trie*> m_next;
            bool m_isLeaf; // is this char is the last char of a word
            unordered_map<string, bool> m_memo;
            
            // add a new word to the trie
            void add(const char* str) {
                if (*str == 0) {
                    this->m_isLeaf = true;
                    return;
                }
                if (*str > 0 && *str < MAX_CHAR) {
                    Trie* pNext = this->m_next[*str];
                    if (nullptr == pNext) {
                        pNext = new Trie();
                        this->m_next[*str] = pNext;
                    }
                    pNext->add(str+1);
                }
            }
            // returns true if str could be matched from current trie and possible continued words from passed root trie 
            bool match(Trie& root, const char* str) {
                if (*str == 0) return this->m_isLeaf;
                
                if (m_memo.end() != m_memo.find(str)) {
                    return true;
                }
                
                bool result(false);
                if (this->m_isLeaf) {
                    result = root.match(root, str);
                }
                if (!result) {
                    if (*str > 0 && *str < MAX_CHAR) {
                        Trie* pNext = this->m_next[*str];
                        if (nullptr != pNext) {
                            result = pNext->match(root, str+1);
                        }
                    }
                }
                
                if (result) {
                    m_memo[str] = true;
                }
                
                return result;
            }
        };
        
        // sort words array by word length
        sort(words.begin(), words.end(), [](string& a, string& b) {return a.size() < b.size();});
        
        vector<string> result;
        Trie t;
        for (string& word: words) {
            if (word.size()==0) continue; // we ignore empty words
            if (t.match(t, word.c_str())) {
                result.push_back(word);
            }
            t.add(word.c_str());
        }
        return result;
    }
};