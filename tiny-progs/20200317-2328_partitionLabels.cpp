class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len='z'-'a'+1;
        vector<int> start(len,-1);
        vector<int> end(len,-1);
        for (int idx = 0; idx < S.length(); ++idx) {
            int ch = S[idx] - 'a';
            if (start[ch] < 0) start[ch] = idx;
            if (end[ch] < idx) end[ch] = idx;
        }
        vector<int> result;
        int stacked = 0;
        int prev_start = 0;
        for (int idx = 0; idx < S.length(); ++idx) {
            int ch = S[idx] - 'a';
            if (start[ch] == idx) {
                stacked++;
            }
            if (end[ch] == idx) {
                stacked--;
            }
            if (stacked == 0) {
                result.push_back(idx - prev_start + 1);
                prev_start = idx + 1;
            }
        }
        return result;
    }
};