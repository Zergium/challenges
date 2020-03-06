// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<2 || n<2) return 1;
        vector<int> options(m,1);
        for (int i=1; i<n; i++) {
            for (int j=m-2; j>=0; j--) {
                options[j] = options[j+1] + options[j];
            }
        }
        return options[0];
    }
};