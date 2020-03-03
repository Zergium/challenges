class Trie {
public:
    /** Initialize your data structure here. */
    
    static const int MAX_CHAR = 'z'-'a'+1;
    
    struct TrieNode {
        TrieNode()
            :m_next(MAX_CHAR, nullptr)
            ,m_leaf(false) {};
        
        bool m_leaf;
        vector<TrieNode*> m_next;
        
        ~TrieNode() {
            for (TrieNode* ptr: m_next) {
                delete ptr;
            };
            m_next.clear();
        };
        
        void insert(string rest) {
            if (rest.size() > 0) {
                char ch = rest[0]-'a';
                TrieNode* pNode = m_next[ch];
                if (nullptr == pNode) {
                    pNode = new TrieNode();
                    m_next[ch] = pNode;
                }
                if (rest.size() == 1) {
                    pNode->m_leaf = true;
                } else {
                    pNode->insert(rest.substr(1, rest.length()-1));
                }
            }
        }
        
        // found, is_word
        pair<bool,bool> searchEx(string word) {
            if (word.empty()) {
                return {true,m_leaf};
            };
            char ch = word[0]-'a';
            TrieNode* pNode(m_next[ch]);
            if (pNode != nullptr) {
                return pNode->searchEx(word.substr(1, word.length()-1));
            } else {
                return {false, false};
            }
        }
    };
    
    TrieNode m_root;
    
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        m_root.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return m_root.searchEx(word).second;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return m_root.searchEx(prefix).first;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */