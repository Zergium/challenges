class Solution {
public:
     __attribute__((no_sanitize("undefined")))
    int rangeBitwiseAnd(int m, int n) {
        uint64_t begin = m;
        uint64_t end = n;
        uint64_t result = begin;
       // cout << "result: " << result << endl;
        while (result != 0 && begin <= end) {
            result &= begin;
           // cout << "iter --- result: " << result << endl;
            uint64_t right_bit = begin & (~(begin-1));
           // cout << "right bit: " << right_bit << endl;
            if (begin == end) break;
            begin += right_bit;
           // cout << "begin: " << begin << endl;
            
        }
        return result;
    }
};


/*
20000
2147483647

2147483646
2147483647
*/