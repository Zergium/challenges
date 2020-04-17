class Solution {
public:
    
    class Checker {
    public:
        vector<int> nums;
        Checker() : nums(10,0) {};
        bool addAndCheck(char val) {
            int v = val - '0';
            //cout << "val: " << val << "; v: " << v << endl; 
            if (val == '.') return true;
            if (nums[v] > 0) return false;
            nums[v] = 1;
            return true;
        }
    };
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i<9; i++) {
            //cout << "---- i:" << i << endl;
            Checker rowChecker;
            Checker colChecker;
            Checker squareChecker;
            
            int sq_row = i / 3;
            int sq_col = i % 3;
            
            for (int j=0; j<9; j++) {
                //cout << "------- j:" << j << endl;
                if (!rowChecker.addAndCheck(board[i][j])) return false;
                if (!colChecker.addAndCheck(board[j][i])) return false;
                
                if (!squareChecker.addAndCheck(
                    board[sq_row * 3 + j / 3][sq_col * 3 + j % 3])) return false;
            }
        }
        
        return true;
    }
};