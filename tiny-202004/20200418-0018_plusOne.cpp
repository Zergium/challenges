class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow = 1;
        int idx = digits.size()-1;
        while (idx >= 0 && overflow > 0) {
            int& digit(digits[idx]);
            int sum = digit + overflow;
            digit = sum % 10;
            overflow = sum / 10;
            idx--;
        }
        if (overflow > 0) {
            digits.insert(digits.begin(), overflow);
        }
        return digits;
    }
};