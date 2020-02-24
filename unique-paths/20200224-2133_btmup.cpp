class Solution {
public:
    int uniquePaths(int m, int n) {
        vector vec(m, 1);
        for (int i=1; i<n; ++i) {
            for (int j=0; j<m-1; ++j) {
                vec[j+1] += vec[j];
            }
        }
        return vec[m-1];
    }
};