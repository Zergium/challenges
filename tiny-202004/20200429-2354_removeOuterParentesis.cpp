class Solution {
public:
    
    string getNextPart(string& s, int& idx) {
        if (idx < s.length()) {
            int start = idx;
            int lev = 1;
            //if (s[idx] != '(') cout << "error: expected '(' at pos " << idx << endl;
            idx++; 
        
            while (idx < s.length() && lev > 0) {
                if (s[idx] == '(') lev++;
                else lev--;
                idx++;
            }
            return s.substr(start, idx-start);
        }
        return "";
    }
    
    string removeOuterParentheses(string S) {
        int idx = 0;
        stringstream res;
        while (idx < S.length()) {
            string p = getNextPart(S, idx);
            //cout << "part: " << p;
            p = p.substr(1, p.length()-2);
            //cout << "; added " << p << endl;
            res << p;
        }
        return res.str();
    }
};