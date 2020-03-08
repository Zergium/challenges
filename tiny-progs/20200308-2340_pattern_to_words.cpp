class Solution {
public:
    bool wordPattern(string pattern, string str) {
        auto it_ch = pattern.begin();
        stringstream ss_str(str);
        string word;
        bool has_word = getline(ss_str, word, ' ');
        vector<string> known('z'-'a'+1);
        while (it_ch != pattern.end() && has_word) {
            char ch = *it_ch - 'a';
            
            if (known[ch].empty()) {
                known[ch] = word;
            } else {
                if (known[ch] != word) {
                    return false;
                }
            }
            
            it_ch = next(it_ch);
            has_word = getline(ss_str, word, ' ');
        }            
        
        if (has_word || it_ch != pattern.end()) {
            return false;
        }
        
        return true;
    }
};