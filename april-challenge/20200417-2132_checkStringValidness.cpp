
// 900 ms :(

class Solution {
public:
    
    bool isValidRest(const string& s, int idx, int numRight) {
        if (idx == s.size()) {
            return 0 == numRight;
        }
        
        if (s[idx] == '(') {
            return isValidRest(s, idx+1, numRight+1);
        } else if (s[idx] == ')') {
            if (numRight == 0) {
                return false;
            }
            return isValidRest(s, idx+1, numRight-1);
        } else {
            // *
            if (isValidRest(s, idx+1, numRight+1)) {
                return true;
            }
            if (numRight > 0 && isValidRest(s, idx+1, numRight-1)) {
                return true;
            }
            return isValidRest(s, idx+1, numRight);
        }
    }
    
    bool checkValidString(string s) {
        return isValidRest(s, 0, 0);
    }
};


