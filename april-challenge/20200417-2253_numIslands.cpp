class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int h = grid.size();
        if (h < 1) {
            return 0; 
        }
        const int w = grid[0].size();
        if (w < 1) {
            return 0;
        }
        
        const int WATER = '0';
        const int LAND_NEW = '1';
        const int LAND_DONE = '2';
        
        int numLands = 0;
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                if (grid[row][col] == LAND_NEW) {
                    numLands++;
                    queue<pair<int,int>> q;
                    q.push({row,col});
                    while (!q.empty()) {
                        pair<int, int> pos = q.front(); q.pop();
                        int r = pos.first;
                        int c = pos.second;
                        grid[r][c] = LAND_DONE;
                        int deltas[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
                        for (int i=0; i<4; i++) {
                            int next_r = r + deltas[i][0];
                            int next_c = c + deltas[i][1];
                            if (next_r >= 0 && next_r < h &&
                               next_c >= 0 && next_c < w) {
                                 if (grid[next_r][next_c] == LAND_NEW) {
                                    q.push({next_r, next_c});
                                 }
                            }
                        }
                    }
                }
            }
        }
        return numLands;
    }
    
};