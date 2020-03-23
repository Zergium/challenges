class Solution {
public:
    string addStrings(string num1, string num2) {
        stringstream ss;
        int overflow = 0;
        int idx = 0;
        while (idx < num1.size() || idx < num2.size()) {
            int digit1 = idx < num1.size() ? (num1[num1.size()-1-idx]-'0') : 0;
            int digit2 = idx < num2.size() ? (num2[num2.size()-1-idx]-'0') : 0;
            int sum = digit1 + digit2 + overflow;
            overflow = sum / 10;
            ss << static_cast<char>('0' + (sum % 10));
            idx++;
        }
        if (overflow != 0) {
            ss << static_cast<char>('0' + (overflow));
        }
        string result(ss.str());
        reverse(result.begin(), result.end());
        return result;
    }
};