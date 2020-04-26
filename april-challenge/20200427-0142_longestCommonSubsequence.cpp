class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector< vector<int> > mat(len1+1, vector<int>(len2+1, 0));
        for (int i1 = 1; i1 <= len1; i1++) {
            for (int i2 = 1; i2 <= len2; i2++) {
                if (text1[i1-1] == text2[i2-1]) {
                    mat[i1][i2] = mat[i1-1][i2-1] + 1;
                } else {
                    mat[i1][i2] = max(mat[i1-1][i2], mat[i1][i2-1]);
                }
            }
        }
        
        // if (0) {
        //     int i1 = 0;
        //     cout << "--";
        //     for (auto c: text2) cout << c;
        //     cout << endl;
        //     for (auto& a: mat) {
        //         cout << (i1>0 ? text1[i1-1] : '-'); i1++;
        //         for(auto x: a) {
        //             cout << x;
        //         }
        //         cout << endl;
        //     }
        // }
        
        return mat[len1][len2];
    }
};