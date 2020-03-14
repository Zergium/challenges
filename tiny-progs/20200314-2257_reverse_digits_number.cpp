class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
          // cout << "--- iter, x = " << x << endl;
            int digit = x % 10;
            x /= 10;
          // cout << "digit " << digit << ", rest x = " << x << endl; 
            
            if (digit < 0) {
                if (res < numeric_limits<int>::min() / 10 ||
                   res * 10 < numeric_limits<int>::min() - digit) {
                   // cout << "too small! " << res << endl;
                    return 0;
                } 
            } else {
                if (res > numeric_limits<int>::max() / 10 || 
                    res * 10 > numeric_limits<int>::max() - digit) {
                    //cout << "too big! " << res << endl;
                    return 0;
                }
            }
            res = res * 10 + digit;
            //cout << "res = " << res << endl;
        }
        return res;
    }
};