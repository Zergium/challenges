class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights);
        sort(begin(sorted), end(sorted));
        int moved = 0;
        for (int i=0; i<heights.size(); i++) {
            if (heights[i] != sorted[i]) {
                moved++;
            }
        }
        return moved;
    }
};