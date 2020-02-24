class Solution {
   map < pair<int,int>, int> mem; 
public:
    int uniquePaths(int m, int n) {
        // Edge cases
        if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        
        if (m<n) swap(m,n);
        auto it = mem.find({m,n});
        if (it != mem.end()) return it->second;
        int result = uniquePaths(m-1,n) + uniquePaths(m,n-1);
        mem[{m,n}] = result;
        return result;
    }
};