class Solution {
public:
    bool checkRecord(string s) {
        int numA(0);
        int numL(0);
        bool rewarded(true);
        for (char ch: s) {
            if (ch == 'A') {
                numA++;
                numL = 0;
                if (numA>1) {
                    rewarded = false;
                    break;
                }
            }
            else if (ch == 'L') {
                numL++;
                if (numL > 2) {
                    rewarded = false;
                    break;
                }
            } else {
                numL = 0;
            }
        }
        return rewarded;
    }
};