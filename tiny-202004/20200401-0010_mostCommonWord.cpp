class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> set_banned;
        for (auto& s: banned) {
            set_banned.insert(s);
            //cout <<"ban: " << s << endl;
        }
        
        // harsmap word = count
        unordered_map<string, int> words;
        
        const string delim = " !?',;.'";
        
        // collect hashmap
        int idx = 0; 
        while (idx < paragraph.length() && idx != string::npos) {
            idx = paragraph.find_first_not_of(delim, idx);
            if (idx != string::npos && idx < paragraph.length()) {
                int idx_end = paragraph.find_first_of(delim, idx+1);
                if (idx_end == string::npos) {
                    idx_end = paragraph.length();
                }
                string word = paragraph.substr(idx, idx_end-idx);
                transform(word.begin(), word.end(), word.begin(), [](char ch){ return tolower(ch);});
                //cout << "found " << word << endl;
                
                
                if (set_banned.end() == set_banned.find(word)) {
                    words[word] += 1;
                    //cout << "inc for " << word << endl;
                }
                
                idx = idx_end;
            }    
        }
        
        
        // walk through and string with find max count
        string best_word;
        int best_count = 0;
        for (auto p : words) {
            if (p.second > best_count) {
                best_count = p.second;
                best_word = p.first;
            }
        }
        
        
        // return str with max
        return best_word;
    }
};