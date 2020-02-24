
///// explanation? combinatorial magic :)


class Solution {
public:
    int uniquePaths(int m, int n) {
        // Edge cases
        if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        // Number of unique ways of arranging m-1 rights and n-1 downs
        // (m+n-2)!/((m-1)!(n-1)!)
        int a = (m >=n) ? m-1 : n-1;
        int b = (m < n) ? m-1 : n-1;
        long unsigned int num = 1, den = 1;
        int i = 0;
        while(i < b){
            num *= (a + i + 1);
            den *= i + 1;
            i++;
        }
        return num/den;
    }
};