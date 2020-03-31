class Solution {
public:
    void tryNext(vector<int> vec_idx, vector<int>& A, int& maxHHMM) {
        // cout << "called ";
        // for (auto x: vec_idx) cout << x << "; ";
        // cout << endl;
        
        if (vec_idx.size() == 4) {
            int hh = A[vec_idx[0]] * 10 + A[vec_idx[1]];
            int mm = A[vec_idx[2]] * 10 + A[vec_idx[3]];
            //cout << "try hh = " << hh << ", mm=" << mm << endl;
            if (hh < 24 && mm < 60) {
                int cur = hh*100 + mm;
                if (cur > maxHHMM) maxHHMM = cur;
            }
            //cout << "maxHHMM " << maxHHMM << endl;
            return;
        }
        for (int idx = 0; idx<4; idx++) {
            int used = false;
            for (auto i : vec_idx) {
                if (i == idx) {
                    used = true;
                    break;
                }
            }
            if (!used) {
                vector<int> vec2(vec_idx);
                vec2.push_back(idx);
                tryNext(vec2, A, maxHHMM);
            }
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        int maxHHMM = -1;
        tryNext({}, A, maxHHMM);
        if (maxHHMM >= 0) {
            stringstream ss;
            int hh = maxHHMM / 100;
            int mm = maxHHMM % 100;
            if (hh < 10) ss << '0';
            ss << hh;
            ss << ':';
            if (mm < 10) ss << '0';
            ss << mm;
            return ss.str();
        }
        return "";
    }
};