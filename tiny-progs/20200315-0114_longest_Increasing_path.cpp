class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int H = matrix.size();
        if (H < 1) return 0;
        int W = matrix[0].size();
        if (W < 1) return 0;
        vector< pair<int, pair<int,int>>> sorted_values;
        for (int j=0; j<H; j++) {
            for (int i=0; i<W; i++) {
                sorted_values.push_back({matrix[j][i], {i,j}});
            }
        }
        sort(begin(sorted_values), end(sorted_values), 
             [](pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b) -> bool {
                 return a < b;
             });
        
        vector<pair<int,int>> neighbours = {
            {-1,0}, {+1,0}, {0,-1}, {0,+1},
        };
        
        int max_len = 0;
        
        vector< vector<int> > lens(H, vector<int>(W, -1));
        for (auto val_pos: sorted_values) {
            int i = val_pos.second.first;
            int j = val_pos.second.second;
            //cout << "next (" << i << ", " << j << ") ---> lens[j][i] = " << lens[j][i] << endl;
            if (lens[j][i] == -1) {
                lens[j][i] = 1;
                deque<pair<int,int>> qu;
                qu.push_back({i,j});
                while (!qu.empty()) {
                    pair<int,int> pos = qu.front();
                    qu.pop_front();
                    
                    //cout << " popped (" << pos.first << "," << pos.second << ")" << endl;
                    
                    int len = lens[pos.second][pos.first];
                    if (len > max_len) { max_len = len; }
                    
                    for (auto& delta: neighbours) {
                        int next_j = pos.second + delta.second;
                        int next_i = pos.first + delta.first;
                        //cout << "  checked (" << next_i << "," << next_j << ")" << endl;
                        if (next_j >= 0 && next_j < H && 
                           next_i >= 0 && next_i < W) {
                            //cout << "   good pos, lens at pos " << lens[next_j][next_i]<< endl;
                            if (matrix[pos.second][pos.first] < matrix[next_j][next_i]) {
                                if (lens[next_j][next_i] < len + 1 || lens[next_j][next_i] == -1) {
                                    lens[next_j][next_i] = len + 1;
                                    qu.push_back({next_i, next_j});
                                }
                            }
                        }
                    } 
                }
                
            } 
        }
        return max_len;
    }
};