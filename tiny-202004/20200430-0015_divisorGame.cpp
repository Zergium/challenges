class Solution {
public:
    
///  
    
//     1 - lost
//     1 2 - 1 win
//     1 2 3 - 1 lost 
//     1 2 3 4 = win 
//             - 1 win
//             - 2 lost
//     1 2 3 4 5 - 1 lost
//     1 2 3 4 5 6 = win
//                   - 1 win
//                   ..
//     1 2 3 4 5 6 7 - lost
//     1 2 3 4 5 6 7 8 - win
//                     -1 win
//     1 2 3 4 5 6 7 8 9 = lost
//                      1 = lost
//                      3 = lost
//     1 2 3 4 5 6 7 8 9 10 = win
//                         -1 win
                        
    unordered_map<int, bool> res;
    bool divisorGame(int N) {
        /// dfs // bfs
        //return (0 == N % 2);  <-- works fine
        
        if (N == 1) {
            return false;
        }
        if (N == 2) {
            return true;
        }
        if (N == 3) { 
            return false;
        }
        if (res.count(N) > 0) {
            return res[N];
        }
        
        bool result = false;
        for (int x = 1; x < N && !result; x++) {
            if (N % x == 0) {
                result = !divisorGame(N-x);
            }
        }
        res[N] = result;
        return result;
    }
};