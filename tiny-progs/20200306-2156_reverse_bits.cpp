class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i=0; i<32; ++i) {
            result <<= 1;
            if ((1&n) > 0) {
                result |= 1;
            }
            n >>= 1;
        }
        return result;
    }
};