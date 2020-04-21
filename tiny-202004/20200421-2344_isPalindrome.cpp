class Solution {
public:
    bool isPalindrome(string s) {
        stringstream ss;
        for (char ch: s) {
            ch = tolower(ch);
            if ('a' <= ch && ch <= 'z' || '0' <= ch && ch <= '9') {
                ss << ch;
            }
        }
        string filtered = ss.str();
        //cout << "filtered: " << filtered << endl;
        int half_size = filtered.size()/2;
        for (int i=0; i<half_size; i++) {
            //cout << filtered[i] << " vs " << filtered[s.size()-1-i] << endl;
            if (filtered[i] != filtered[filtered.size()-1-i]) {
                return false; 
            }
        }
        return true;
    }
};