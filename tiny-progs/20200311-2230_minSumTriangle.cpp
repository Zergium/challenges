class Solution {
public:
    unordered_map<string, int> mem_results;
    
    string vec_to_str(vector<int> v) {
        stringstream ss;
        for (auto val: v) ss << val <<"|";
        return ss.str();
    }
    
    int minScoreTriangulation(vector<int>& A) {
        
        string vecStr = vec_to_str(A);
        auto it = mem_results.find(vecStr);
        if (it != mem_results.end()) {
            return it->second;
        }
        
        const int N = A.size();
        if (N <= 3) {
            int triangle = A[0] * A[1] * A[2];
            return triangle;
        }
        
        int minVal = numeric_limits<int>::max();
        for (int i = 0; i < A.size(); ++i) {
            
            int triangle = A[(i + N - 1) % N] * A[i] * A[(i + 1) % N];
            
            vector<int> tmp(A);
            tmp.erase(tmp.begin()+i);
            
            int value = triangle + minScoreTriangulation(tmp);
            
            minVal = min(minVal, value);
        }
        
        mem_results[vecStr] = minVal;
        
        return minVal;
    }
};



///////////////////////////////////////////////

https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture

////////////////////////////// special version1

int dp[50][50] = {};
int minScoreTriangulation(vector<int>& A, int i = 0, int j = 0, int res = 0) {
  if (j == 0) j = A.size() - 1;
  if (dp[i][j] != 0) return dp[i][j];
  for (auto k = i + 1; k < j; ++k) {
    res = min(res == 0 ? INT_MAX : res, 
      minScoreTriangulation(A, i, k) + A[i] * A[k] * A[j] + minScoreTriangulation(A, k, j));
  }
  return dp[i][j] = res;
}

////////////////////////////// special version2

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
  int dp[50][50] = {};
  for (int i = A.size() - 1; i >= 0; --i)
    for (int j = i + 1; j  < A.size();  ++j)
      for (auto k = i + 1; k < j; ++k)
        dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
  return dp[0][A.size() - 1];
} 
};



//////////////////////////////// v3

    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        for(int l=2;l<A.size();l++) {
            for(int i=0;i+l<A.size();i++) {
                for(int j=i+1;j<i+l;j++) {
                    if(dp[i][i+l]==0) dp[i][i+l]=A[i]*A[i+l]*A[j]+dp[i][j]+dp[j][i+l];
                    else dp[i][i+l]=min(dp[i][i+l], A[i]*A[i+l]*A[j]+dp[i][j]+dp[j][i+l]);
                }
            }
        }
        return dp[0][A.size()-1];
    }

    