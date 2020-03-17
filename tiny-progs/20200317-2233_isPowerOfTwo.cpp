class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool result = (n > 0) && (0 == (n & (n-1)));
        return result;
    }
};