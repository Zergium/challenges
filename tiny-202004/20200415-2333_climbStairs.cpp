class Solution {
public:
    
    //  1
    //  1 2
    //  1 2 1+2=3
    //  1 2 3      3+2=5
    //  1 2 3      5      3+5=8
    //
    
    int climbStairs(int n) {
        int prev2 = 0;
        int prev1 = 1;
        int curr = 0;
        for (int i=0; i<n; i++) {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};