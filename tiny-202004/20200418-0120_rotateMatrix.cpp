class Solution {
public:
/*
             j
  x x x x x x x o
  o x x x x x o o
  o o x x x 1 o o
i o o o x 1 2 o o
  o o o 3 2 o o o 


*/
    
    
    
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i=0; i < n / 2; i++) {
            for (int j=i; j<n-1-i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
                // matrix[i][j] = matrix[j][n-1-i];
                // matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
                // matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
                // matrix[n-1-j][i] = tmp;
            }
        }
    }
};


// ==========================

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        printf("mid = %d\n", n);
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};


------------------


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};