class Solution {
public:
    void eatBackspaces(int& p, const string& str) {
        int chars_to_skip = 0;
        while (p >= 0 && (chars_to_skip > 0 || str[p] == '#')) {
            if (str[p] == '#') {
                chars_to_skip++;    
            } else {
                chars_to_skip--;
            }
            
            p--;
        }
    }
    bool backspaceCompare(string S, string T) {
        // 12345##90
        // 12390
        
        // 1#2#
        // 12##
        
        // 1##c
        // #a#c
        
        // nzp#o#g
        // b#nzp#o#g
        
        int ps = S.length()-1;
        int pt = T.length()-1;
        while (ps >= 0 && pt >= 0) {
            eatBackspaces(ps, S);
            eatBackspaces(pt, T);
            if (ps >= 0 && pt >= 0) {
                if (S[ps] != T[pt]) {
                    return false;
                }
                ps--;
                pt--;
            }
        }
        if (ps >= 0) {
            eatBackspaces(ps, S);
        }
        if (pt >= 0) {
            eatBackspaces(pt, T);
        }
        return (ps == -1 && pt == -1);
    }
};