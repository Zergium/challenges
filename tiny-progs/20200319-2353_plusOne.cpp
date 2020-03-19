class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size()-1;
        int val = 1;
        while (idx >= 0 && val > 0) {
            int new_digit = digits[idx] + val;
            digits[idx] = new_digit % 10;
            val = new_digit / 10;
            idx--;
        }
        if (val > 0) {
            digits.insert(digits.begin(), val);
        }
        return digits;
    }
};