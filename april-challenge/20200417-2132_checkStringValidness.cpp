
Valid Parenthesis String

Given a string containing only 
three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. We define the validity of a string by these rules:


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


/////////// state of the art ...

  bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }

//// same but optimized a bit ↓    

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; int high = 0;
        for(char c : s)
        {
            low += c == '(' ? 1 : -1;
            high += c != ')' ? 1 : -1;
            
            if(high < 0) break;

            low = max(low, 0);
        }

        return low == 0;
    }
};

//////////////// mine version

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0;
        int hi = 0;
        for (char c: s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else { // c== '*'
                lo--;
                hi++;
            }
            if (hi < 0) {
                return false;
            }
            if (lo < 0) {
                lo = 0;
            }
        }
        return lo == 0;
    }
};