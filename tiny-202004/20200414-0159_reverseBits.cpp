class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int steps = 32;
        while (steps > 0 && n != 0) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
            steps--;
        }
        if (steps != 0 && result != 0) {
            result <<= steps;
        }
        return result;
    }
};