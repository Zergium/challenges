class Solution {
public:
    
    string char_to_str(unsigned char ch) {
        stringstream ss;
        ss << "[";
        for (int i=0; i<8; ++i) {
            ss << (((0x80 & ch) > 0) ? "1" : "0");
            if (i<7) ss << ",";
            ch <<= 1;
        }
        ss << "]";
        return ss.str();
    }
    
    unsigned char vec_to_char(const vector<int>& vec) {
        unsigned char result(0);
        for (int i=0; i<vec.size(); i++) {
            result <<= 1;
            if (vec[i] > 0) {
                result |= 1;
            }
        }
        return result;
    }
    
    vector<int> char_to_vec(unsigned char ch) {
        vector<int> result;
        for (int i=0; i<8; ++i) {
            result.push_back( (0x80 & ch) > 0 ? 1 : 0 );
            ch <<= 1;
        }
        return result;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> next(256, -1);
        unsigned char ch = vec_to_char(cells);
        next[ch] = 0;
        for (int i=0; N > 0; i++) {
            ch = ~ ((ch >> 1) ^ (ch << 1)) & 0x7e;
            cout << i << ": " << char_to_str(ch) << endl;
            if (next[ch] < 0) {
                next[ch] = i;
                N--;
            } else if (N > 255) {
                int step = i - next[ch];
                cout << "step: " << step << " | i=" << i << " vs next[ch]=" << next[ch] << "  |  N = " << N <<endl;
                if (N > step) {
                    N -= (N / step) * step;
                    N--;
                } else {
                    N--;
                }
                
                cout << "new N " << N << endl;
            } else N--;
            
        }
        return char_to_vec(ch);
    }
};