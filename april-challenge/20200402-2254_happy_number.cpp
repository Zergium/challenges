class Solution {
public:
    bool isHappy(int n) {
       // max int = 10 digits
       // 1 digit is max 9, square = 81
       // max sum of squares of digits = 81 * 10 = 810
        vector<bool> number_used(1000, false);
        while (true) {
            if (n == 1) return true;
            if (n == 0) return false;
            int k = 0;
            while (n > 0) {
                int digit = n % 10;
                n /= 10;
                k += digit * digit; 
            }
            n = k;
            if (number_used[n]) return false;
            number_used[n] = true;
        }
    }
};