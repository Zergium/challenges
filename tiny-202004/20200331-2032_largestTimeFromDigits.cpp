class Solution {
public:
    int pickLargest(int up_to, vector<int>& A) {
        int best_idx = -1;
        int best = -1;
        for (int idx = 0; idx < A.size(); idx++) {
            if (0 <= A[idx] && A[idx] <= up_to && best < A[idx]) {
                best_idx = idx;
                best = A[idx];
            }
        }
        if (best_idx >= 0) {
            A[best_idx] = -1;
        }
        cout << "picked " << best << endl;
        return best;
    }
    string largestTimeFromDigits(vector<int>& A) {
        stringstream ss;
        int digit;
        digit = pickLargest(2, A);
        if (digit >= 0) ss << digit; else return "";
        int max_2nd = (digit > 1) ? 3 : 9;
        digit = pickLargest(max_2nd, A);
        if (digit >= 0) ss << digit; else return "";
        ss << ':';
        digit = pickLargest(5, A);
        if (digit >= 0) ss << digit; else return "";
        digit = pickLargest(9, A);
        if (digit >= 0) ss << digit; else return "";
        return ss.str();
    }
};