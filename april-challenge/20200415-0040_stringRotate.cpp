class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if (s.length() < 2) return s;
        
        int sh_right = 0;
        for (vector<int>& ar: shift) {
            int direction = ar[0];
            int amount = ar[1];
            if (direction > 0) amount = -amount;
            sh_right += amount;
        }
        int idx = sh_right % (int)s.length(); // cast to signed!
        if (idx == 0) return s;
        if (idx < 0) idx += s.length();
        return s.substr(idx) + s.substr(0, idx);
    }
    
    
/*
"wpdhhcj"
[[0,7],[1,7],[1,0],[1,3],[0,3],[0,6],[1,2]]
"hcjwpdh"

"wpdhhcj"
[[0,7],[1,7],[1,0],[1,3],[0,3],[0,6],[1,2],[1,1]]


"abc"
[[0,1],[1,2]]
"cab"

*/    
    
};