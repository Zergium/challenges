class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        vector<int> digits;
        while (x != 0) {
            digits.push_back(x%10);
            x /= 10;
        }
        for (int idx = 0; idx < digits.size() / 2; idx++) {
            if (digits[idx] != digits[digits.size()-1-idx]) return false;
        }
        return true;
    }
};