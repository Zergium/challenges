
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


=============== memoization

// 12 ms

class Solution {
public:
    //typedef pair<int, int> posi_t;
    unordered_map<int, bool> m_prevRuns;
    
    bool isValidRest(const string& s, int idx, int numRight) {
        
        // memois
        int key = idx*1000 + numRight;
        auto it = m_prevRuns.find(key);
        if (it != m_prevRuns.end()) {
            return it->second;
        }
    
        // result
        bool result = false;
        
        if (idx == s.size()) {
            result = (0 == numRight);
        } else  if (s[idx] == '(') {
            result = isValidRest(s, idx+1, numRight+1);
        } else if (s[idx] == ')') {
            if (numRight == 0) {
                result = false;
            } else {
                result = isValidRest(s, idx+1, numRight-1);
            }
        } else {
            // ch = '*'
            result = isValidRest(s, idx+1, numRight+1);
            if (!result && numRight > 0) {
                result = isValidRest(s, idx+1, numRight-1);
            }
            if (!result) {
                result = isValidRest(s, idx+1, numRight);
            }
        }
        m_prevRuns[key] = result;
        return result;
    }
    
    bool checkValidString(string s) {
        return isValidRest(s, 0, 0);
    }
};


