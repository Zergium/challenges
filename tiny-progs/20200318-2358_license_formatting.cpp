class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        stringstream ss;
        int num_dashes = 0;
        for (int i=S.size()-1; i >= 0; i--) {
            char ch = S[i];
            if (ch == '-') continue;
            if (ch >= 'a' && ch <= 'z') ch += ('A'-'a');
            ss << ch;
            if ((ss.tellp()-num_dashes) % K == 0 && i != 0) {
                ss << '-';
                num_dashes++;
            }
        }
        string result(ss.str());
        reverse(result.begin(), result.end());
        return result;
    }
};