/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */


//   m
//   xx
//   xx
//   xx
//n  xx
//   xx
//   xx

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int n = dimensions[0];
        int m = dimensions[1];
        cout << "n: " << n << ", m: " << m << endl;
        
        for (int k=0; k<2; k++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cout << " get(" << x <<"," << y << ")=";
                try{
                    int v = binaryMatrix.get(x,y);
                    cout << v;
                } catch (...)
                {
                    cout << "x";
                }
            }
            cout << endl;
        }
        cout << "=====" << endl;
            int v = binaryMatrix.get(3,0);
            cout << v << " !!!" << endl;
        }
        int lo = 0;
        int hi = m-1;
        while (lo<hi) {
            int mi = (hi + lo) / 2;
            cout << "get(" << (n-1) << ", " << mi << ")" << endl;
           // int v = binaryMatrix.get(n-1, mi);
             int v = binaryMatrix.get(3,0);
            if (v == 0) 
                lo = mi+1;
            else
                hi = mi;
        }
        cout << "get(" << (n-1) << ", " << hi << ")" << endl;
        if (binaryMatrix.get(n-1,hi) == 1) return hi;
        return -1; 
    }
};


===================  working version

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int n = dimensions[0];
        int m = dimensions[1];
       
        int best = -1;

        for (int row = 0; row<n ; row++) {

            int lo = 0;
            int hi = best < 0 ? m-1 : best - 1;
            while (lo<hi) {
                int mi = (hi + lo) / 2;
                int v = binaryMatrix.get(row, mi);
                if (v == 0) 
                    lo = mi+1;
                else
                    hi = mi;
            }
            
            if (binaryMatrix.get(row, hi) == 1) {
                if (best < 0 || best > hi) best = hi;
            };
            if (best == 0) break;
        }
        return best; 
    }
};