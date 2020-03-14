class Solution {
public:
    
    pair <char, int> getNextGroup(const string& str, int& idx) {
        char ch = str[idx++];
        int num = 1;

        while (idx < str.length() && str[idx] == ch) {
            idx++;
            num++;
        }
        return {ch, num};
    }
    
    bool isStrech(const string& word, const string& S) {
        //cout << "- isStrech " << word << " vs " << S << endl;        
        int idxS = 0;
        int idxWord = 0;
        
        while (idxS < S.length() && idxWord < word.length()) {
            pair<char, int> groupWord = getNextGroup(word, idxWord);
            //cout << "word group " << groupWord.first << ", len " << groupWord.second << endl;
            pair<char, int> groupS = getNextGroup(S, idxS);
            //cout << "Strech group " << groupS.first << ", len " << groupS.second << endl;
            
            if (groupS.first != groupWord.first) {
                //cout << "tmp word: " << word << " vs " << S << "  --> " << "NO (char match)" << endl;
                return false;
            }
            if ( groupWord.second == groupS.second ||
               (3 <= groupS.second)) {
                // ok
            } else {
                //cout << "tmp word: " << word << " vs " << S << "  --> " << "NO (num match), " << groupWord.second << " vs "<< groupS.second << endl;
                return false;
            }
        }
        //cout << "fin, idxS " << idxS << " vs " << idxWord << endl;
        bool result = idxS == S.length() && idxWord == word.length();
        //cout << "word: " << word << " vs " << S << "  --> " << (result ? "YES" : "NO") << endl;
            
        return result;
        
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int count = 0;
        
        for (string word: words) {
           // cout << "--------- word: " << word << endl;
            if (isStrech(word, S)) count++;
        }
        
        return count;
    }
};