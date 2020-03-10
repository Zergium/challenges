class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n<0) return 1/(x*myPow(x,-n-1));
        if (n % 2 == 1) {
            return x * myPow(x,n-1);
        } else {
            double val = myPow(x, n/2);
            return val*val;
        }
    }
};