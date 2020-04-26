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


//////////////


/*It is to convert the LCS into LIS, and then use the LIS NlogN algorithm to solve.

Suppose there are two sequences s1[ 1~6 ] = { a, b, c , e, f, a }, s2[ 1~7 ] = { b, a, e, e, d, c, a }.
    
Record the position of each element in s1 in s2, and then arrange the position in descending order, then the above example can be expressed as:

Loc( a)= { 7, 2 }, loc( b ) = {1 }, loc( c ) = { 6 }, loc( e ) = { 4, 3 }.
    
The position of each element in s1 is arranged in the order of the elements in s1 into a sequence s3 = { 7, 2, 1, 6, 4, 3, 7, 2}.
    
The value obtained by asking LIS for s3 is the answer to LCS.

Runtime: O(nlogn) , 4ms.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // LCS -> LIS
        vector<int> alph[128];  // record text1's alphabet in text2 pos.
        int maps[128];
        memset(maps, 0, sizeof(maps));
        for(int i = 0; i < text1.size(); i++) maps[text1[i]] = 1;
        
        for(int j = text2.size(); j > -1; j--) if(maps[text2[j]] == 1) alph[text2[j]].push_back(j);
        vector<int> nums;
        for(int i = 0; i < text1.size(); i++) {
            if(alph[text1[i]].size() > 0) nums.insert(nums.end(), alph[text1[i]].begin(), alph[text1[i]].end());
        }
        
        // get LIS's length by monotone stack method : O(nlogn)
        vector<int> pool;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] > pool.back() ) {
                pool.push_back(nums[i]);
            } else if(nums[i] == pool.back()) {
                continue;
            } else {
                int s = 0, e = pool.size() - 1, mid = 0;
                while(s < e) {
                    mid = (s + e)/2;
                    if(pool[mid] < nums[i]) s = mid + 1;
                    else e = mid;
                }
                pool[e] = nums[i];
            }
        }
        
        return pool.size();
    }
};
