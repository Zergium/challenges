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
            int sz(static_cast<int>(ss.tellp()) - num_dashes);
            if (sz % K == 0) {
                ss << '-';
                num_dashes++;
            }
        }
        string result(ss.str());
        while (!result.empty() && *prev(result.end()) == '-') result.pop_back();
        reverse(result.begin(), result.end());
        return result;
    }
};