class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        int last = 0;
        while (idx < bits.size()) {
            if (bits[idx] == 1) {
                idx += 2;
                last = 2;
            }
            else {
                idx++;
                last = 1;
            }
        }
        return last == 1;
    }
};