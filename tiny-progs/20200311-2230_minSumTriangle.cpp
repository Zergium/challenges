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